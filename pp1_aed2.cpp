#include <iostream>
#include <cstdlib>
#include <vector>
#include <climits>

using namespace std;

typedef int T;
const int BRANCO = 0;
const int CINZA = 1;
const int PRETO = 2;
const int INFINITO = INT_MAX;
int tempo;

template <class T>
class Planeta {
private:
    T valor;
    int cor, d, f, menor_planeta_adjacente;
    T predecessor;
    vector<T> planeta_adjacentes;
    vector<T> planeta_distancia;

public:
    void print();
    void printPlanetas();
    Planeta() {};
    Planeta(T valor): valor(valor) { }

    T getValor() {
        return valor;
    }
    void setValor(T valor) {
        this -> valor = valor;
    }
    int getCor(){
    	return cor;
    }
    void setCor(int cor){
    	this->cor = cor;
    }
    void setD(int d){
    	this->d = d;
    }
    int getD(){
    	return d;
    }
    void setF(int f){
    	this->f = f;
    }
    int getF(){
    	return f;
    }
    int getMenor() {
    	return menor_planeta_adjacente;
    }
    void setMenor(int menor_planeta_adjacente) {
    	this->menor_planeta_adjacente = menor_planeta_adjacente;
    }
    T getPredecessor(){
        return predecessor;
    }
    void setPredecessor(T predecessor){
    	this->predecessor = predecessor;
    }
    vector<T> getPlanetas(){
    	return planeta_adjacentes;
    }
    void setPlanetas(T v){
    	this->planeta_adjacentes.push_back(v);
    }
    void setDistancia(T v){
    	this->planeta_distancia.push_back(v);
    }
};

template <class T>
void Planeta<T>::print(){
  cout << getValor() << " ";
}

template <class T>
void Planeta<T>::printPlanetas(){
  for(int i = 0; i < planeta_adjacentes.size(); i++){
    cout << planeta_adjacentes[i] << " ";
  }
}

template <class T>
class Sistema {
private:
    T valor;
    int cor, d;
    T predecessor;
    vector<T> sistema_adjacentes;

public:
    void print();
    void printVertices();
    Sistema() {};
    Sistema(T valor): valor(valor) { }

    T getValor() {
        return valor;
    }
    void setValor(T valor) {
        this -> valor = valor;
    }
    int getCor(){
    	return cor;
    }
    void setCor(int cor){
    	this->cor = cor;
    }
    void setD(int d){
    	this->d = d;
    }
    int getD(){
    	return d;
    }
    T getPredecessor(){
        return predecessor;
    }
    void setPredecessor(T predecessor){
    	this->predecessor = predecessor;
    }
    vector<T> getSistemas(){
    	return sistema_adjacentes;
    }
    void setSistemas(T v){
    	this->sistema_adjacentes.push_back(v);
    }
};

template <class T>
void Sistema<T>::print(){
  cout << getValor() << " ";
}

template <class T>
void Sistema<T>::printVertices(){
  for(int i = 0; i < sistema_adjacentes.size(); i++){
    cout << sistema_adjacentes[i] << " ";
  }
}

template <class T>
class Fila{
private:
	T *vertices;
	int frente, tras;
	int TAM;
public:
	Fila(int tam);
	void enfileira(T);
	T desenfileira();
	void mostra();
	bool vazia();
};

template <class T>
Fila<T>::Fila(int tam){
	TAM = tam;
	vertices = new T[TAM];
	frente = 0;
	tras = frente;
}

template <class T>
void Fila<T>::enfileira(T it){
	if((tras + 1) % TAM == frente){
		cout << "Fila Cheia!!" << endl;
	}
	else
	{
		vertices[tras] = it;
		tras = (tras+1) % TAM;
	}
}

template <class T>
T Fila<T>::desenfileira(){
	if(frente == tras){
		cout << "Fila vazia!!" << endl;
	}
	else
	{
		T it;
		it = vertices[frente];
		frente = (frente + 1) % TAM;
		return it;
	}
}

template <class T>
void Fila<T>::mostra(){
	for(int i = frente; i < tras; i++){
		vertices[i].print();
	}
	cout << endl;
}

template <class T>
bool Fila<T>::vazia(){
	if(frente == tras){
		return true;
	}
	else{
		return false;
	}
}

template <class T>
class Grafo {
private:
  	T *adj;
  	int n, m;

public:
  	Grafo(int);
  	void iniciar(int);
  	void preenche();
  	void inserirSistema(T, T);
  	void inserirPlaneta(T, T, float);
  	void print();
  	void destroy();
  	void dfsVisita(T &);
  	void dfs();
  	void bfs(T &);

	T* getAdj(){
		return adj;
	}
	void setAdj(T* adj){
		this->adj = adj;
	}
	int getN(){
		return n;
	}
	void setN(int n){
		this->n = n;
	}
	int getM(){
		return m;
	}
	void setM(int m){
		this->m = m;
	}
};

template <class T>
Grafo<T>::Grafo (int n) {
  iniciar(n);
  preenche();
}

template <class T>
void Grafo<T>::iniciar(int n) {
    this->n = n;
    adj = new T[n+1];
}

template <class T>
void Grafo<T>::preenche(){
  for(T i = 1; i <= n; i++){
	T j(i);
	adj[i] = j;
   }
}

template <class T>
void Grafo<T>::inserirSistema(T u, T v) {
	adj[u].setSistemas(v);
	adj[v].setSistemas(u);
	m++;
}

template <class T>
void Grafo<T>::inserirPlaneta(T u, T v, float f) {

	adj[u].setPlanetas(v);
	adj[v].setPlanetas(u);

	adj[u].setDistancia(f);
	adj[v].setDistancia(f);

	m++;
}

template <class T>
void Grafo<T>::print() {
	for (int i = 1; i <= n; i++) {
		cout << "v[" << adj[i].getValor() << "] = ";
		adj[i].printVertices();
		cout << endl;
  }
}

template <class T>
void Grafo<T>::dfsVisita(T &u){
	tempo = tempo+1;
	u.setD(tempo);
	u.setCor(CINZA);
	T vertice_adj;
	for(int i = 0; i < u.getVertices().size(); i++){
		vertice_adj = u.getVertices()[i];
		if(getAdj()[vertice_adj].getCor() == BRANCO){
			getAdj()[vertice_adj].setPredecessor(u.getValor());
			dfsVisita(getAdj()[vertice_adj]);
		}
	}
	u.setCor(PRETO);
	tempo = tempo+1;
	u.setF(tempo);
	cout << u.getValor() << " ";
}

template <class T>
void Grafo<T>::dfs(){
	for(int i = 1; i <= getN(); i++){
		getAdj()[i].setCor(BRANCO);
		getAdj()[i].setPredecessor(0);
	}

	tempo = 0;
	for(int j = 1; j <= getN(); j++){
		if(getAdj()[j].getCor() == BRANCO){
			dfsVisita(getAdj()[j]);
		}
	}
}

template <class T>
void Grafo<T>::bfs(T &s){
	for(int i = 1; i <= getN(); i++){
		getAdj()[i].setCor(BRANCO);
		getAdj()[i].setD(INFINITO);
		getAdj()[i].setPredecessor(0);
	}

	s.setCor(CINZA);
	s.setD(0);
	s.setPredecessor(0);

	Fila<T> fila;
	fila = new Fila(getN());

	T u;
	T posicao;
	while(!fila){
		u = fila.desenfileira();
		for(int i = 0; i < u.getVertices().size(); i++){
			posicao = u.getVertices()[i];
			if(getAdj()[posicao].getCor() == BRANCO){
				getAdj()[posicao].setCor(CINZA);
				getAdj()[posicao].setD(u.getD()+1);
				getAdj()[posicao].setPredecessor(u.getValor());
				fila.enfileira(getAdj()[posicao]);
			}
		}
		u.setCor(PRETO);
		cout << u.getValor() << " ";
	}
}

int main(int argc, const char * argv[]) {






	return 0;
}
