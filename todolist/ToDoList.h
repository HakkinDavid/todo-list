/*  nombre: Clase ToDoList
    autores: David Emmanuel Santana Romero, Mauricio Alcantar Due�as
    versi�n: 3.0
    fecha: 16 de septiembre de 2023
*/

#ifndef TODOLIST_H
#define TODOLIST_H

#include "../listas/listas.h"
#include "../task/task.h"
using namespace std;

class ToDoList {
private:
    Lista<Task> taskL; //lista ligada para guardar obj task
    int length;
public:
    ToDoList (int length = 0);//constructor
    ~ToDoList ();//destructor

    void setLength (int);
    int getLength (void);

    void insertTask (Task);//insertar un obj task mientras mantendiendo el orden 
    void display (void);//desplegar lista de tasks en el todolist
    void eraseTask (int);
    void completeTask (int);
};

#include "ToDoList.cpp"
#endif
