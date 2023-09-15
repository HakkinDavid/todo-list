/*  nombre: Clase ToDoList
    autores: David Emmanuel Santana Romero, Mauricio Alcantar Dueñas
    versión: 1.0
    fecha: 15 de septiembre de 2023
*/

#ifndef TODOLIST_H
#define TODOLIST_H

#include <list>
#include "task.h"
using namespace std;

class ToDoList {
private:
    list<Task> taskL;
    int length;
public:
    ToDoList (int);
    ~ToDoList ();

    void setLength (int);
    int getLength (void);

    void insertTask (Task);
    void display (void);
    void eraseTask (int);
};

#include "ToDoList.cpp"
#endif
