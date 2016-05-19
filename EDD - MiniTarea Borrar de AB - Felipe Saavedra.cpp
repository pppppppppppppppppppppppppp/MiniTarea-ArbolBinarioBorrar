#include <iostream>

using namespace std;

struct nodo{
    int data;
    nodo *der;
    nodo *izq;
    nodo(int x):data(x){}
};

struct arbol{
    nodo *raiz;
    arbol():raiz(NULL){}

    void buscar_elemento(int x){

    }
    void insertar(nodo *nuevo){
        insertarR(nuevo,raiz);
    }

    void insertarR(nodo *nuevo, nodo *p){
        if(p == NULL){
            p = nuevo;
            return;
        }
        if(nuevo->data > p->data){
            insertarR(nuevo,p->der);
        }
        if(nuevo->data < p->data){
            insertarR(nuevo,p->izq);
        }
    }

    void borrar_elemento(nodo *r,nodo *b){ // nodo raiz y el que queremos eliminar respectivamente
        if(raiz==NULL)return;

        else if(r->data<b->data) borrar_elemento(r->der,b);
        else if(r->data>b->data) borrar_elemento(r->izq,b);

        else{
            if(r->izq==NULL&&r->der==NULL){
                delete r;
                return;
            }
            else if(r->izq==NULL){
                nodo *aux=r;
                r=r->der;
                delete aux;
                return;
            }
            else if(r->der==NULL){
                nodo *aux=r;
                r=r->izq;
                delete aux;
                return;
            }
            else{
                nodo *aux=r->der;
                while(aux->izq!=NULL){
                    aux=aux->izq;
                }
                r=aux;
                borrar_elemento(r->der,aux);
            }
        }
    }

};

int main() {
    cout << "Hello, World!" << endl;
    return 0;
}