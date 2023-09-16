#include <iostream>
#include "task/task.h"
#include "todolist/ToDoList.h"
#include "listas/listas.h"
#include "menu/menu.h"
#include <conio.h>

using namespace std;

ToDoList LIST(10);

void insertarTarea () {

}

void removerTarea () {

}

void completarTarea () {

}

Menu mainMenu ({
    {'1', {"Ver lista", [] () { LIST.display(); cout << "Presiona cualquier tecla para continuar." << endl; _getch(); system("cls"); }}},
    {'2', {"Insertar tarea", insertarTarea }},
    {'3', {"Remover tarea", removerTarea }},
    {'4', {"Completar tarea", completarTarea }}
}, "MENÚ PRINCIPAL");

int main () {
    /*
    // individual tasks examples
    // actual program should implement these inside the yet to do ToDoList class
    // constructor (description string, year, month, day, priority (0 is lowest), boolean completed)
    Task t1 ("nose. si?", 2023, 9, 12);
    Task t2 ("si no?", 2023, 9, 16);
    Task t3 ("no?", 2023, 9, 11, 0, true);
    Task t4 ("si???", 2023, 9, 14, 3, false);

    t1.display();
    t2.display();
    t3.display();
    t4.display();
    */
   Lista<Task> lts;
   Task tt;
   lts.emplace_back();
   lts.clear();
   lts.emplace_back();
   lts.insert(lts.getHead(),tt);
   lts.erase(lts.getHead());
   lts.getHead()->getData().display();

   mainMenu.display(true, true);
}
