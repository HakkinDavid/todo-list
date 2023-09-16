/*  nombre: Clase ToDoList
    autores: David Emmanuel Santana Romero, Mauricio Alcantar Due�as
    versi�n: 1.0
    fecha: 15 de septiembre de 2023
*/

#ifndef TODOLIST_H
#define TODOLIST_H

#include "../listas/listas.h"
#include "../task/task.h"
using namespace std;

class ToDoList {
private:
    Lista<Task> taskL;
    int length;
public:
    ToDoList (int length = 0);
    ~ToDoList ();

    void setLength (int);
    int getLength (void);

    void insertTask (Task);
    void display (void);
    void eraseTask (int);
    void completeTask (int);
};

#include "ToDoList.cpp"
#endif
