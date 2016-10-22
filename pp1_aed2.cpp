#include <iostream>
#include <cstdlib>
#include <vector>
#include <climits>

using namespace std;

typedef int Vertex;
const int BRANCO = 0;
const int CINZA = 1;
const int PRETO = 2;
const int INFINITO = INT_MAX;
int tempo;

class Item {
private:
    Vertex valor;
    int cor, d, f;
    Vertex predecessor;
    vector<Vertex> vertices;

public:
    void print();
    void printVertices();
    Item() {};
    Item(Vertex valor): valor(valor) { }
    Item(Vertex valor, int cor, int d, int f, Vertex predecessor){
    	this->valor = valor;
    	this->cor = cor;
    	this->d = d;
    	this->f = f;
    	this->predecessor = predecessor;
    }

    Vertex getVertex() {
        return valor;
    }
    void setVertex(Vertex valor) {
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
    Vertex getPredecessor(){
        return predecessor;
    }
    void setPredecessor(Vertex predecessor){
    	this->predecessor = predecessor;
    }
    vector<Vertex> getVertices(){
    	return vertices;
    }
    void setVertices(Vertex v){
    	this->vertices.push_back(v);
    }
};

void Item::print(){
  cout << getVertex() << " ";
}

void Item::printVertices(){
  for(int i = 0; i < vertices.size(); i++){
    cout << vertices[i] << " ";
  }
}

class Grafo { // Não-direcionado
private:
  	Item *adj;
  	int n, m; // ordem e tamanho

public:
  	Grafo(int); // construtor
  	void initialize(int);
  	void preenche();
  	void insertEdge(Vertex, Vertex);
  	void print();
  	void destroy();
// métodos get/set para n, m e adj.
	Item* getAdj(){
		return adj;
	}
	void setAdj(Item* adj){
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

Grafo::Grafo (int n) {
  initialize(n);
  preenche();
}

void Grafo::initialize(int n) {
  //if (this->n != 0){
    this->n = n;
    adj = new Item[n+1]; // Vetor usa
    //inicializar os itens do vetor de 1 a n com os respectivos numeros de vertice
  //}  // células de 1..n
}

void Grafo::preenche(){
  for(Vertex i = 1; i <= n; i++){
	Item j(i);
	adj[i] = j;
   }
}

void Grafo::insertEdge(Vertex u, Vertex v) {
  //Item *x = new Item(v); // chave = vértice
  adj[u].setVertices(v); // Insere na lista // vetor de itens(adj) pega a lista(getVertices) e adiciona
  //x = new Item (u);
  adj[v].setVertices(u); // Insere na lista
  m++;
}

void Grafo::print() {
  for (int i = 1; i <= n; i++) {
    cout << "v[" << adj[i].getVertex() << "] = ";
    adj[i].printVertices();
    cout << endl;
  }
}

/*void Grafo::destroy() {
  for (int i = 0; i <= n; i++) {
    adj[i].destroy(); // destroi lista
  }
  delete( adj );
  n = m = 0;
}*/

//busca em profundidade
void dfsVisita(Grafo &g, Item &u){
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

class Fila{
private:
	Item *vertices; //vetor
	int frente, tras;
	int TAM;
public:
	Fila(int tam);
	void enfileira(Item);
	Item desenfileira();
	void mostra();
	bool vazia();
};
Fila::Fila(int tam){
	TAM = tam;
	vertices = new Item[TAM];
	frente = 0;
	tras = frente;
}
void Fila::enfileira (Item it){
	if((tras + 1) % TAM == frente){
		cout << "Fila Cheia!!" << endl;
	}
	else
	{
		vertices[tras] = it;
		tras = (tras+1) % TAM;
	}
}
Item Fila::desenfileira(){
	if(frente == tras){
		cout << "Fila vazia!!" << endl;
		return NULL;
	}
	else
	{
		Item it;
		it = vertices[frente];
		frente = (frente + 1) % TAM;
		return it;
	}
}
void Fila::mostra(){
	for(int i = frente; i < tras; i++){
		vertices[i].print();
	}
	cout << endl;
}
bool Fila::vazia(){
	if(frente == tras){
		return true;
	}
	else{
		return false;
	}
}

class No {
public:
	Item item;
    No *prox;

    No() {}

    Item getItem() {
        return item;
    }

    void setItem(Item item) {
        this -> item = item;
    }

    No* getProx() {
        return prox;
    }

    void setProx(No *prox) {
        this->prox = prox;
    }
};

class Pilha {
private:
    No *fundo, *topo;
    int estado;

public:
    Pilha();

    No* getFundo(){
    	return fundo;
    }

    void setFundo(No *fundo) {
    	this->fundo = fundo;
    }

    No* getTopo(){
        return topo;
    }

    void setTopo(No *topo){
    	this->topo = topo;
    }

    int getEstado(){
    	return estado;
    }

    void setEstado(int estado){
    	this->estado = estado;
    }

    Item desempilha();
    void empilha(Item);
    bool vazia();
    void mostra();
};

Pilha::Pilha() {
    fundo = new No();
    topo = fundo;
    estado = 0;
}

bool Pilha::vazia() {
	return topo == fundo;
}

void Pilha::empilha(Item item) {
    No *aux = new No();
    topo -> setItem(item);
    aux -> setProx(topo);
    topo = aux;
}

Item Pilha::desempilha() {
	No *aux = topo;
	topo = topo->getProx();
	Item item = topo->getItem();
	//item = topo->getItem();
	delete aux;
	return item;
}

void Pilha::mostra(){
	No *aux = new No();
	aux = topo->getProx();
	while(aux != NULL){
		cout << aux->getItem().getVertex() << " ";
		aux = aux->getProx();
	}
	cout << endl;
}

void descobreCaminho(Pilha &visita, Pilha &caminho){
	caminho.empilha(visita.desempilha());
	while(!visita.vazia()){
		if(caminho.getTopo()->getProx()->getItem().getPredecessor() == visita.getTopo()->getProx()->getItem().getVertex()){
			caminho.empilha(visita.desempilha());
		}
		else{
			visita.desempilha();
		}
	}
}

//busca em largura
void bfs(Grafo &g, Item &s, Item &final, Pilha &visita, Pilha &caminho){
	for(int i = 1; i <= g.getN(); i++){
		g.getAdj()[i].setCor(BRANCO);
		g.getAdj()[i].setD(INFINITO);
		g.getAdj()[i].setPredecessor(0);
	}
	s.setCor(CINZA);
	s.setD(0);
	s.setPredecessor(0);

	Fila fila(g.getN());
	fila.enfileira(s);
	Item u; Vertex posicao; bool continuar = 1;
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

// Função auxiliar
void testaGrafo(Grafo &g) {
  g.insertEdge(1, 2);
  g.insertEdge(2, 3);
  g.insertEdge(3, 4);
  g.insertEdge(4, 5);
  g.insertEdge(5, 1);
  g.insertEdge(5, 2);
  g.insertEdge(2, 4);
  g.print();
}

int main(int argc, const char * argv[]) {
  Grafo g(5); Pilha visita; Pilha caminho;

  cout << "-----grafo-----" << endl;
  testaGrafo(g);

  bfs(g, g.getAdj()[1], g.getAdj()[4], visita, caminho);
  caminho.mostra();

  cout << endl << "fim";

  return 0;
}
