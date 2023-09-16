#include <iostream>
#include "task/task.h"
#include "todolist/ToDoList.h"
#include "listas/listas.h"

// Someone should add #include <windows.h> here for the cls() function
// which erases the console, for better viewing. I can't because Mac :)

using namespace std;

int main () {
    char choice=0;
    ToDoList LIST(10);
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
        // menu system
    do{ // do while repeating menu
        int choInt=0; // choice but int lolool
        do{// do while choices
            cout << "Elegir opcion.\n1.- Ver lista To-Do.\n2.- Insertar tarea.\n3.- Remover tarea.\n4.- Cumplir tarea.\n5.- Menu principal." << endl;
            cin >> choInt;
        }while(choInt<1 || choInt>5);// end do while choices
        switch(choInt){
            case 1:{ //   VER LISTA
                LIST.display();
                break;}//       END CASE VER LISTA
            case 2:{ //   INSERTAR TAREA
                break;}//        END CASE INSERTAR TAREA
            case 3:{ //   REMOVER TAREA
                break;}//        END REMOVER TAREA
            case 4:{ //   CUMPLIR TAREA
                break;}//        END CASE CUMPLIR TAREA
            case 5:{//    MENU PRINCIPAL
                break;}//        END CASE MENU PRINCIPAL
            default:{
                cout << "You say what???" << endl;
                break;}
        }
        cout << "¿Desea salir del programa? Usa '#' para salir. Ingresa cualquier otro caracter para continuar." << endl;
        cin >> choice;
    }while(choice!='#'); // end do while repeating menu
}
