#include <iostream>
#include "task/task.h"
#include "todolist/ToDoList.h"
#include "listas/listas.h"
#include "menu/menu.h"
#include <conio.h>

using namespace std;

ToDoList LIST;

void insertarTarea () {
    string desc;
    int y, m, d, p;
    int c;
    cout << "Proporciona la descripción de la tarea: ";
    getline(cin, desc);
    cout << "Proporciona la fecha" << endl << "Año: ";
    cin >> y;
    getchar();
    do {cout << "Mes [1-12]: ";
    cin >> m;
    getchar();}
    while (m < 1 || m > 12);
    do {cout << "Día [1-31]: ";
    cin >> d;
    getchar();}
    while (d < 1 || d > 31);
    cout << "Prioridad [0 para el mínimo]: ";
    cin >> p;
    getchar();
    cout << "¿Está completada? [0 = no, 1 = sí]: ";
    cin >> c;
    getchar();
    Task t (desc, y, m, d, p, (c == 1 ? true : false));
    LIST.insertTask(t);
    system("cls");
    LIST.display();
}

void removerTarea () {
    if (LIST.getLength() == 0) {
        cout << "Sin tareas pendientes." << endl;
        return;
    }
    int index;
    LIST.display();
    do{cout << "Proporciona un índice a eliminar [1-" << LIST.getLength() << ", 0 para cancelar]: " << endl;
    cin >> index;
    getchar();
    if (index == 0) return;
    }
    while (index < 1 || index > LIST.getLength());
    LIST.eraseTask(index);
    system("cls");
    LIST.display();
}

void completarTarea () {
    if (LIST.getLength() == 0) {
        cout << "Sin tareas pendientes." << endl;
        return;
    }
    int index;
    LIST.display();
    do{cout << "Proporciona un índice de tarea a marcar como completada [1-" << LIST.getLength() << ", 0 para cancelar]: " << endl;
    cin >> index;
    getchar();
    if (index == 0) return;}
    while (index < 1 || index > LIST.getLength());
    LIST.completeTask(index);
    system("cls");
    LIST.display();
}

Menu mainMenu ({
    {'1', {"Ver lista", [] () { if (LIST.getLength() == 0) { cout << "Sin tareas pendientes." << endl; return; }; LIST.display(); cout << "Presiona cualquier tecla para continuar." << endl; _getch(); system("cls"); }}},
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

   // teacher, our list implementation literally dies.
   // it goes "segmentation fault!!!" at every line of code.
   // forgive us for using <list> in the underlying ToDoClass.
   // we really would appreciate your advice.
   // following test for reference.
   /*
   Lista<Task> lts;
   Task tt;
   lts.emplace_back();
   lts.clear();
   lts.emplace_back();
   lts.insert(lts.getHead(),tt);
   lts.erase(lts.getHead());
   lts.getHead()->getData().display();
   */

    system("chcp 65001"); //caracteres en español
    system("cls");
    mainMenu.display(true, true);
}
