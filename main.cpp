#include <iostream>
#include "task/task.h"
#include "todolist/ToDoList.h"
using namespace std;

int main () {

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
    // pps
}
