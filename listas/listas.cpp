#include "listas.h"
#include <iostream>
using namespace std;

template <class T> Nodo<T> :: Nodo (T data, Nodo<T>* next = nullptr) {
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


template <class T> Lista :: Lista () {

}
template <class T> Lista :: ~Lista () {

}

template <class T> void Lista :: setHead (Nodo<T>* h) {

}
template <class T> Nodo<T>* Lista :: getHead (void) {

}

template <class T> void Lista :: emplace_back (void) {

}
template <class T> void Lista :: clear (void) {

}
template <class T> void Lista :: insert (Nodo<T>* dex, T obj) {

}
template <class T> void Lista :: erase (Nodo<T>* dex) {

}