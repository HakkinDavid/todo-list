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
    Nodo<T> *n = new Nodo<T>;
    if(head == nullptr){ head = n; }
    else{
        Nodo<T> *c = head;
        
    }
}
template <class T> void Lista<T> :: clear (void) {

}
template <class T> void Lista<T> :: insert (Nodo<T>* dex, T obj) {

}
template <class T> void Lista<T> :: erase (Nodo<T>* dex) {

}