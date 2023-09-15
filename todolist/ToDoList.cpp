#include "ToDoList.h"
#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

ToDoList :: ToDoList (int length = 0) {
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
    list<Task>::iterator it = taskL.begin();
    while(t.getDue() > (*it).getDue()){ it++; }
    if(t.getDue() != (*it).getDue()){ taskL.insert(it,t); }
    else{
        while((t.getPriority() > (*it).getPriority()) && (t.getDue() == (*it).getDue())){ it++; }
        taskL.insert(it,t);
    }
    length++;
}

void ToDoList :: display (void) {
    list<Task>::iterator it = taskL.begin();
    for(int i=0; i<length; i++){
        cout << i+1 << ".\t";
        (*it++).display();
    }
}

void ToDoList :: eraseTask (int n) { //NEEDS VALIDATION
    list<Task>::iterator it = taskL.begin();
    for(int i=1; i<n; i++){ it++; }
    taskL.erase(it);
    length--;
}

