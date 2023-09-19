/*  nombre: Clase Lista
    autores: Mauricio Alcantar Due�as
    versi�n: 2.0
    fecha: 16 de septiembre de 2023
*/

#ifndef LISTAS_H
#define LISTAS_H

using namespace std;

template <class T>
class Nodo {
private:
    T data;//data guardado en el nodo
    Nodo<T>* next;//pointer al proximo nodo en la lista

public:
    Nodo (T data, Nodo<T>* next = nullptr);//constructor
    ~Nodo ();//destructor

    void setData (T);
    void setNext (Nodo<T>*);
    T& getData (void);
    Nodo<T>* getNext (void);//getter para el pointer al prox nodo en la litsa omg :O
};

template <class T>
class Lista {
private:
    Nodo<T>* head;//pointer al head (primer nodo) de la lista

public:
    Lista ();//constructor para initializar al obj lista con un list empty 
    ~Lista ();//destructor 2 mai heart </3

    void setHead (Nodo<T>*);//set head first node lista
    Nodo<T>* getHead (void);//get head for list

    void emplace_back (void);//new nodo con datos defaulted al final de la lista
    void clear (void);//clear list by haciendo set el head a un nullpointer
    void insert (Nodo<T>*, T);//insert nodo nuevo con datos proovided despues del nodo especificdo en la lista 
    void erase (Nodo<T>*);//erase specific nodo de la lista
};

#include "listas.cpp"
#endif
