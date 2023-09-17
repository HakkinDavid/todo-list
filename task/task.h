/*  nombre: Clase Task
    autor: David Emmanuel Santana Romero
    versión: 1.0
    fecha: 12 de septiembre de 2023
*/

#ifndef TASK_H
#define TASK_H

#include <chrono>
using namespace std;
using namespace chrono;

class Task {
    private:
        string description; //description of task
        int priority; //nivel prioridad de task
        year_month_day due; //fecha due de task
        bool completed; //status of completion
    public:
        Task (string, int, int, int, int, bool); //constructor
        ~Task (); //destructorrrr

        void setDescription (string);
        void setPriority (int);
        void setDue (int, int, int);
        void setCompleted (bool);
        //sets para propiedades del task

        string getDescription ();
        int getPriority ();
        year_month_day getDue ();
        bool getCompleted ();

        void display (); //desplegar detalles
        bool isDue (); //revisar si task esta due basado en la fecha de ahora
};

#include "task.cpp"
#endif