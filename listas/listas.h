/*  nombre: Clase Lista
    autores: Mauricio Alcantar Due�as
    versi�n: 1.0
    fecha: 15 de septiembre de 2023
*/

#ifndef LISTAS_H
#define LISTAS_H

using namespace std;

template <class T>
class Nodo {
private:
    T data;
    Nodo<T>* next;

public:
    Nodo (T data, Nodo<T>* next = nullptr);
    ~Nodo ();

    void setData (T);
    void setNext (Nodo<T>*);
    T getData (void);
    Nodo<T>* getNext (void);
};

template <class T>
class Lista{
private:
    Nodo<T>* head;

public:
    Lista ();
    ~Lista ();

    void setHead (Nodo<T>*);
    Nodo<T>* getHead (void);

    void emplace_back (void);
    void clear (void);
    void insert (Nodo<T>*, T);
    void erase (Nodo<T>*);
};

#include "listas.cpp"
#endif
