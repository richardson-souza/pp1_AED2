#include <iostream>
#include <cstdlib>
#include <vector>
#include <climits>
using namespace std;

const int BRANCO = 0;
const int CINZA = 1;
const int PRETO = 2;
const int MAX = INT_MAX;
int tempo;

template<class T>
class Sistema {
private:
    T valor;
    int cor, d, f;
    T predecessor;
    vector<T> vertices;

public:
    void imprime();
    void imprimeVertices();
    Sistema() {};
    Sistema(T valor): valor(valor) { }
    Sistema(T valor, int cor, int d, int f, T predecessor){
    	this->valor = valor;
    	this->cor = cor;
    	this->d = d;
    	this->f = f;
    	this->predecessor = predecessor;
    }

    T getVertex() {
        return valor;
    }
    void setVertex(T valor) {
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
    T getPredecessor(){
        return predecessor;
    }
    void setPredecessor(T predecessor){
    	this->predecessor = predecessor;
    }
    vector<T> getVertices(){
    	return vertices;
    }
    void setVertices(T v){
    	this->vertices.push_back(v);
    }
};

template<class T>
void Sistema<T>::imprime(){
  cout << getVertex() << " ";
}

template<class T>
void Sistema<T>::imprimeVertices(){
  for(int i = 0; i < vertices.size(); i++){
    cout << vertices[i] << " ";
  }
}

template<class T>
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

template<class T>
Fila<T>::Fila(int tam){
	TAM = tam;
	vertices = new T[TAM];
	frente = 0;
	tras = frente;
}

template<class T>
void Fila<T>::enfileira (T item){
	if((tras + 1) % TAM == frente){
		cout << "Fila Cheia!!" << endl;
	}
	else
	{
		vertices[tras] = item;
		tras = (tras+1) % TAM;
	}
}

template<class T>
T Fila<T>::desenfileira(){
	if(frente == tras){
		cout << "Fila vazia!!" << endl;
		return NULL;
	}
	else
	{
		T item;
		item = vertices[frente];
		frente = (frente + 1) % TAM;
		return item;
	}
}

template<class T>
void Fila<T>::mostra(){
	for(int i = frente; i < tras; i++){
		vertices[i].imprime();
	}
	cout << endl;
}

template<class T>
bool Fila<T>::vazia(){
	if(frente == tras){
		return true;
	}
	else{
		return false;
	}
}

template<class T>
class No {
public:
	T item;
    No *prox;

    No() {}

    T getSistema() {
        return item;
    }

    void setSistema(T item) {
        this -> item = item;
    }

    No* getProx() {
        return prox;
    }

    void setProx(No *prox) {
        this->prox = prox;
    }
};

template<class T>
class Pilha {
private:
    T *fundo, *topo;
    int estado;

public:
    Pilha();

    T* getFundo(){
    	return fundo;
    }

    void setFundo(T *fundo) {
    	this->fundo = fundo;
    }

    T* getTopo(){
        return topo;
    }

    void setTopo(T *topo){
    	this->topo = topo;
    }

    int getEstado(){
    	return estado;
    }

    void setEstado(int estado){
    	this->estado = estado;
    }

    T desempilha();
    void empilha(T);
    bool vazia();
    void mostra();
};

template<class T>
Pilha<T>::Pilha() {
    fundo = new No<T>();
    topo = fundo;
    estado = 0;
}

template<class T>
bool Pilha<T>::vazia() {
	return topo == fundo;
}

template<class T>
void Pilha<T>::empilha(T item) {
    T *aux = new No<T>();
    topo -> setSistema(item);
    aux -> setProx(topo);
    topo = aux;
}

template<class T>
T Pilha<T>::desempilha() {
	T *aux = topo;
	topo = topo->getProx();
	T item = topo->getSistema();
	//item = topo->getItem();
	delete aux;
	return item;
}

template<class T>
void Pilha<T>::mostra(){
	T *aux = new No<T>();
	aux = topo->getProx();
	while(aux != NULL){
		cout << aux->getSistema().getVertex() << " ";
		aux = aux->getProx();
	}
	cout << endl;
}

template<class T>
class Grafo {
private:
  	T *adj;
  	int n, m;

public:
  	Grafo(int);
  	void iniciar(int);
  	void preenche();
  	void insere(T, T);
  	void imprime();
  	void destroy();
  	void bfs(T &,T &,T &,T &,T &);
  	void descobreCaminho(T,T);


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

template<class T>
Grafo<T>::Grafo (int n) {
  iniciar(n);
  preenche();
}

template<class T>
void Grafo<T>::iniciar(int n) {
    this->n = n;
    adj = new T[n+1];
}

template<class T>
void Grafo<T>::preenche(){
  for(T i = 1; i <= n; i++){
	T j(i);
	adj[i] = j;
   }
}

template<class T>
void Grafo<T>::insere(T u,T v) {
	adj[u].setVertices(v);
	adj[v].setVertices(u);
	m++;
}

template<class T>
void Grafo<T>::imprime() {
	for (int i = 1; i <= n; i++) {
		cout << "v[" << adj[i].getVertex() << "] = ";
		adj[i].imprimeVertices();
		cout << endl;
  }
}

template<class T>
void bfs(T &g, T &s, T &final, T &visita, T &caminho){
	for(int i = 1; i <= g.getN(); i++){
		if(g.getAdj()[i].getCor() != PRETO){
			g.getAdj()[i].setCor(BRANCO);
			g.getAdj()[i].setD(MAX);
			g.getAdj()[i].setPredecessor(0);
		}
	}
	s.setCor(CINZA);
	s.setD(0);
	s.setPredecessor(0);

	Fila<T> fila(g.getN());
	fila.enfileira(s);
	T u; T posicao; bool continuar = 1;
	while(continuar){
		u = fila.desenfileira();
		if(u.getVertex() == final.getVertex()){
			continuar = 0;
		}
		else{
			for(int i = 0; i < u.getVertices().size(); i++){
				posicao = u.getVertices()[i];
				if(g.getAdj()[posicao].getCor() == BRANCO){
					g.getAdj()[posicao].setCor(CINZA);
					g.getAdj()[posicao].setD(u.getD()+1);
					g.getAdj()[posicao].setPredecessor(u.getVertex());
					fila.enfileira(g.getAdj()[posicao]);
				}
			}
		}
		u.setCor(PRETO);
		visita.empilha(u);
	}
	descobreCaminho(visita, caminho);
}

template<class T>
void descobreCaminho(T &visita, T &caminho){
	caminho.empilha(visita.desempilha());
	while(!visita.vazia()){
		if(caminho.getTopo()->getProx()->getSistema().getPredecessor() == visita.getTopo()->getProx()->getSistema().getVertex()){
			caminho.empilha(visita.desempilha());
		}
		else{
			visita.desempilha();
		}
	}
}

/*void Grafo::destroy() {
  for (int i = 0; i <= n; i++) {
    adj[i].destroy(); // destroi lista
  }
  delete( adj );
  n = m = 0;
}*/

/*
void dfsVisita(Grafo &g, Sistema &u){
	tempo = tempo+1;
	u.setD(tempo);
	u.setCor(CINZA);
	//cout << u.getVertex() << " ";
	Vertex vertice_adj;
	for(int i = 0; i < u.getVertices().size(); i++){
		vertice_adj = u.getVertices()[i];
		if(g.getAdj()[vertice_adj].getCor() == BRANCO){
			g.getAdj()[vertice_adj].setPredecessor(u.getVertex());
			dfsVisita(g, g.getAdj()[vertice_adj]);
		}
	}
	u.setCor(PRETO);
	tempo = tempo+1;
	u.setF(tempo);
}

void dfs(Grafo &g){
	for(int i = 1; i <= g.getN(); i++){
		g.getAdj()[i].setCor(BRANCO);
		g.getAdj()[i].setPredecessor(0);
	}

	tempo = 0;
	for(int j = 1; j <= g.getN(); j++){
		if(g.getAdj()[j].getCor() == BRANCO){
			dfsVisita(g, g.getAdj()[j]);
		}
	}
}

*/

int main(int argc, const char * argv[]) {
	int ordem, tamanho, qtd_inimigos, inimigo, vertice_1, vertice_2, sistema_inicial, sistema_final;

	Pilha visita;
	Pilha caminho;

	cin >> ordem;
	cin >> tamanho;
	Grafo<int> grafo(ordem);
	for(int i = 1; i <= tamanho; i++){
		cin >> vertice_1;
		cin >> vertice_2;
		grafo.insere(vertice_1,vertice_2);
	}

	cin >> qtd_inimigos;
	for(int i = 1; i <= qtd_inimigos; i++){
		cin >> inimigo;
		grafo.getAdj()[inimigo].setCor(PRETO);
	}


	cin >> sistema_inicial;
	cin >> sistema_final;
	grafo.bfs(grafo, grafo.getAdj()[sistema_inicial], grafo.getAdj()[sistema_final], visita, caminho);

	caminho.mostra();
	cout << endl << "fim";

  return 0;
}
