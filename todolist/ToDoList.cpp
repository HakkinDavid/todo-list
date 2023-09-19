#include "ToDoList.h"
#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

ToDoList :: ToDoList (int length) { //constructor para inizializar obj con max cap del list
    this -> length = length;
    //initialize taskL list con obj empty 
    for(int i=0; i<length; i++){
        taskL.emplace_back();
    }
}
ToDoList :: ~ToDoList () { //destructor
    taskL.clear();//clear para un reset del length a 0
    length = 0;
}

void ToDoList :: setLength (int len) {
    length = len; //new length to set
}
int ToDoList :: getLength (void) {
    return length; //getssss
}

void ToDoList :: insertTask (Task t) { //mantener orden del list por fecha mientras que insertas un obj
   // -t = task para ser insertado
    Nodo<Task> *it = taskL.getHead(); 
    if (length == 0) { //si no tiene nada la list, haga un insert del task a el
        taskL.insert(it,t);
        length++;
        return;
    }
    while(t.getDue()>(it->getData()).getDue() && it->getNext()!=taskL.getHead()){ it = it->getNext(); }
    if(it->getNext() == taskL.getHead()){ //insert task si llegamos al final del list
        if((t.getDue()>(it->getData()).getDue()) || (t.getPriority()>(it->getData()).getPriority() && t.getDue()==(it->getData()).getDue())){
            Nodo<Task> *n = new Nodo<Task>(t);
            it->setNext(n);
            n->setNext(taskL.getHead());
        }
        else{ taskL.insert(it,t); }
        length++;
        return;
    }
    if(t.getDue() != (it->getData()).getDue()){ 
        taskL.insert(it,t); 
        length++;
        return;
    } //insert task si las fechas no son igual
    while((t.getPriority() > (it->getData()).getPriority()) && (t.getDue() == (it->getData()).getDue()) && (it->getNext()!=taskL.getHead())){ it = it->getNext(); }
    if(it->getNext() == taskL.getHead()){ //insert task cuando llegamos al fin del list
        if((t.getPriority() > (it->getData()).getPriority())){
            Nodo<Task> *n = new Nodo<Task>(t);
            it->setNext(n);
            n->setNext(taskL.getHead());
        }
        else{ taskL.insert(it,t); }
        length++;
        return;
    }
    taskL.insert(it,t); //insert task
    length++;
}

void ToDoList :: display (void) { //desplegar la lista de tasks en el ToDoList
    Nodo<Task> *it = taskL.getHead();
    for(int i=0; i<length; i++){
        cout << i+1 << ".\t";//desplegar numero del task
        (it->getData()).display();//desplegar detalles task
        it = it->getNext();
    }
}

void ToDoList :: eraseTask (int n) { //NEEDS VALIDATION para segurar n es un index valido
    //borrar task de la list por su position :( (index)
    Nodo<Task> *it = taskL.getHead();
    if(length==1){ 
        delete it; 
        taskL.setHead(nullptr);
        length--;
        return; 
    }
    for(int i=1; i<n; i++){ it = it->getNext(); }
    taskL.erase(it);
    length--;
}
//marcar un task como completo por su position
void ToDoList :: completeTask (int n) { //NEEDS VALIDATION para asegurar q n es un index valido
    Nodo<Task> *it = taskL.getHead();
    for(int i=1; i<n; i++){ it = it->getNext(); }
    (it->getData()).setCompleted(true);
}