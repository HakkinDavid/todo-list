#include "ToDoList.h"
#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

ToDoList :: ToDoList (int length) {
    this -> length = length;
    for(int i=0; i<length; i++){
        taskL.emplace_back();
    }
}
ToDoList :: ~ToDoList () {
    taskL.clear();
    length = 0;
}

void ToDoList :: setLength (int len) {
    length = len;
}
int ToDoList :: getLength (void) {
    return length;
}

void ToDoList :: insertTask (Task t) {
    Nodo<Task> *it = taskL.getHead();
    if (length == 0) {
        taskL.insert(it,t);
    }
    else{
        while(t.getDue()>(it->getData()).getDue() && it->getNext()!=taskL.getHead()){ it = it->getNext(); }
        if(t.getDue() != (it->getData()).getDue()){ taskL.insert(it,t); }
        else{
            while((t.getPriority() > (it->getData()).getPriority()) && (t.getDue() == (it->getData()).getDue())){ it = it->getNext(); }
            taskL.insert(it,t);
        }
    }
    length++;
}

void ToDoList :: display (void) {
    Nodo<Task> *it = taskL.getHead();
    for(int i=0; i<length; i++){
        cout << i+1 << ".\t";
        (it->getData()).display();
        it = it->getNext();
    }
}

void ToDoList :: eraseTask (int n) { //NEEDS VALIDATION
    Nodo<Task> *it = taskL.getHead();
    for(int i=1; i<n; i++){ it = it->getNext(); }
    taskL.erase(it);
    length--;
}

void ToDoList :: completeTask (int n) { //NEEDS VALIDATION
    Nodo<Task> *it = taskL.getHead();
    for(int i=1; i<n; i++){ it = it->getNext(); }
    (it->getData()).setCompleted(true);
}