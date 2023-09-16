#include <iostream>
using namespace std;

template <class T> Nodo<T> :: Nodo (T data, Nodo<T>* next) {
    this -> data = data;
    this -> next = next;
}
template <class T> Nodo<T> :: ~Nodo () {
    next = nullptr;
}

template <class T> void Nodo<T> :: setData (T d) {
    data = d;
}
template <class T> void Nodo<T> :: setNext (Nodo<T>* n) {
    next = n;
}
template <class T> T Nodo<T> :: getData (void) {
    return data;
}
template <class T> Nodo<T>* Nodo<T> :: getNext (void) {
    return next;
}


template <class T> Lista<T> :: Lista () {
    this -> head = nullptr;
}
template <class T> Lista<T> :: ~Lista () {
    head = nullptr;
}

template <class T> void Lista<T> :: setHead (Nodo<T>* h) {
    head = h;
}
template <class T> Nodo<T>* Lista<T> :: getHead (void) {
    return head;
}

template <class T> void Lista<T> :: emplace_back (void) {
    T t;
    Nodo<T> *n = new Nodo<T>(t);
    n->setNext(head); //Circular i guess
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
    if(head != nullptr){ 
        Nodo<T> *c = head;
        Nodo<T> *p = c;
        do{
            p = c;
            c = c->getNext();
            p -> ~Nodo();
        } while(c != head);
        head = nullptr;
    }
}
template <class T> void Lista<T> :: insert (Nodo<T>* dex, T obj) {

}
template <class T> void Lista<T> :: erase (Nodo<T>* dex) {

}