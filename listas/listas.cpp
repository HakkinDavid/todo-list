#include <iostream>
using namespace std;
//nodo class implementacion
template <class T> Nodo<T> :: Nodo (T data, Nodo<T>* next) {
    //nodo constructor
    this -> data = data;
    this -> next = next;
    //parametros
}
template <class T> Nodo<T> :: ~Nodo () {//destructor
    next = nullptr;
}

template <class T> void Nodo<T> :: setData (T d) {
    data = d;//set los datos guardados en el nodo
}
template <class T> void Nodo<T> :: setNext (Nodo<T>* n) {
    next = n;//set al pointer para el proximo nodo en la lista
}
template <class T> T Nodo<T> :: getData (void) {//get data que estaba guardado en el nodo
    return data;
}
template <class T> Nodo<T>* Nodo<T> :: getNext (void) {
    return next;//get el pointer al proximo nodo en la lista
}


template <class T> Lista<T> :: Lista () {//constructor para lista empty initializado
    this -> head = nullptr;
}
template <class T> Lista<T> :: ~Lista () {//destructor
    head = nullptr;
}

template <class T> void Lista<T> :: setHead (Nodo<T>* h) {//set el primer nodo de la lista
    head = h;
}
template <class T> Nodo<T>* Lista<T> :: getHead (void) {//get first nodo de la lista
    return head;
}

template <class T> void Lista<T> :: emplace_back (void) {//poner un nodo nuevo con datos default al final de la lista
    T t;
    Nodo<T> *n = new Nodo<T>(t);
    n->setNext(head); //Circular reference i guess
    if(head == nullptr){ 
        head = n; 
    }
    else{
        Nodo<T> *c = head;
        while(c->getNext() != head){ c = c->getNext(); }
        c->setNext(n);
    }
    delete n;
}
template <class T> void Lista<T> :: clear (void) {
    head = nullptr;
}
template <class T> void Lista<T> :: insert (Nodo<T>* dex, T obj) { //insertar un nodo nuevo con los provided datos despues de nodo especificado en la lista
    Nodo<T> *n = new Nodo<T>(obj);
    if(dex == nullptr){ 
        head = n; 
        n->setNext(head); //MAKE LIST CIRCULAR?????? WHATTTTT :O
    }
    else if(dex == head){
        head = n;
        n->setNext(dex);
        Nodo<T> *c = dex;
        while(c->getNext() != dex){ c = c->getNext(); }
        c->setNext(head);
    }
    else{
        Nodo<T> *c = head;
        Nodo<T> *p = c;
        while(c != dex){
            p = c;
            c = c->getNext();
        }
        p->setNext(n);
        n->setNext(c);
    }
}
template <class T> void Lista<T> :: erase (Nodo<T>* dex) {//erase al nodo especificado de la lista :[
    Nodo<T> *c = head;
    Nodo<T> *p = c;
    if(dex == head){
        head = c->getNext();
        delete c;
        return;
    }
    while(c != dex){
        p = c;
        c = c->getNext();
    }
    p->setNext(c->getNext());
    delete c;
}