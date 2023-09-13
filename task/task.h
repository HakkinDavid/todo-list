/*  nombre: Clase Task
    autores: David Emmanuel Santana Romero
    versión: 1.0
    fecha: 12 de septiembre de 2023
*/

#ifndef TASK_H
#define TASK_H

#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

class Task {
    private:
        string description;
        int priority;
        year_month_day due;
        bool completed;
    public:
        Task (string, int, int, int, int, bool);
        ~Task ();

        void setDescription (string);
        void setPriority (int);
        void setDue (int, int, int);
        void setCompleted (bool);

        string getDescription ();
        int getPriority ();
        year_month_day getDue ();
        bool getCompleted ();

        void display ();
        bool isDue ();
};

#include "task.cpp"
#endif