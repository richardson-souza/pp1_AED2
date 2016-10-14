#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

typedef int Vertex;
const int BRANCO = 0;
const int CINZA = 1;
const int PRETO = 2;
int tempo;

class Item {
private:
    Vertex valor;
    int cor, d, f;
    Item *predecessor;
    vector<Vertex> vertices;

public:
    void print();
    void printVertices();
    Item() {};
    Item(Vertex valor): valor(valor) { }
    Item(Vertex valor, int cor, int d, int f, Item* predecessor){
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
    void setPredecessor(Item *predecessor){
    	this->predecessor = predecessor;
    }
    Item* getPredecessor(){
    	return predecessor;
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
/*
class No {
private:
    Item *item;
    No *prox;

public:
    No() {}

    Item* getItem() {
        return item;
    }

    void setItem(Item *item) {
        this -> item = item;
    }

    No* getProx() {
        return prox;
    }

    void setProx(No *prox) {
        this->prox = prox;
    }
};

class Lista{
private:
	No *prim, *ult;
public:
	No* getPrim(){
		return prim;
	}

	No* getUlt(){
		return ult;
	}
	Lista();
	void insere(Item*);
	//void remove(Item*);
	void print();
	//void search(Item*);
	void destroy();
};

Lista::Lista() {
    prim = new No(); // cabeça
    prim -> setProx(NULL);
    ult = prim;
}

void Lista::insere(Item* x){
	ult->setProx(new No());
	ult = ult->getProx();
	ult->setProx(NULL);
	ult->setItem(x);
}

void Lista::print(){
  No* p = getPrim()->getProx();
  while(p != NULL){
    p->getItem()->print();
    p = p->getProx();
  }
  cout << endl;
}

void Lista::destroy(){
  No* p = getPrim()->getProx();
    while(p != NULL){
      delete(p);
      p = p->getProx();
    }
}*/
/*
class Fila{
private:
	Item *vertices; //vetor
	int frente, tras;
	int TAM;
public:
	Fila(int tam);
	void enfileira(Item*);
	Item* desenfileira();
	void mostra();
	bool vazia();
};
Fila::Fila(int tam){
		TAM = tam;
		vertices = new Item[TAM];
		frente = 0;
		tras = frente;
	}
void Fila::enfileira (Item *it){
	if((tras + 1) % TAM == frente){
		cout << "Fila Cheia!!" << endl;
	}
	else
	{
		vertices[tras] = it;
		tras = (tras+1) % TAM;
	}
}
Item* Fila::desenfileira(){
	if(frente == tras){
		cout << "Fila vazia!!" << endl;
		return NULL;
	}
	else
	{
		Item *it = new Item();
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
*/
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
  int n;
  /*Vertex v = 1;
  Vertex b = 2;
  Lista *l = new Lista();
  Item *i = new Item(v);
  Item *j = new Item(b);
  l->insere(j);
  l->insere(i);
  l->print();
  dfs1(l);
  cout << l->getPrim()->getProx()->getItem()->getCor();*/

  cout << "ordem: "; cin >> n;
  Grafo g(n);
  //cout << "-----grafo-----" << endl;
  testaGrafo(g);
  for(int i = 0; i < g.getAdj()[1].getVertices().size(); i++){
	  cout << g.getAdj()[1].getVertices()[i] << endl;
  }
  /*g.getAdj()[1].setCor(CINZA);
  g.getAdj()[3].setCor(BRANCO);
  g.getAdj()[5].setCor(PRETO);
  cout << g.getAdj()[1].getCor() << endl;
  cout << g.getAdj()[2].getCor() << endl;
  cout << g.getAdj()[3].getCor() << endl;
  cout << g.getAdj()[4].getCor() << endl;
  cout << g.getAdj()[5].getCor() << endl;*/
  //testaGrafo(g);
  //cout << "-----fim-------" << endl;

  //g.getAdj()[1].print();
  //dfs(g);
  //cout << g.getAdj()->getPrim()->getProx()->getItem()->getCor();
  //cout << "-----fim-------";
  return 0;
}
