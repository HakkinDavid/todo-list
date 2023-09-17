#include "task.h"
#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

Task :: Task (string description = "Sin descripción", int Dyear = 2023, int Dmonth = 12, int Dday = 12, int priority = 0, bool completed = false) {
    //Constructor con parametros de la descripcion, prioridad, fecha, y su estatus de completion.
    //initializar propiedades del task 
    this -> description = description;
    due = year_month_day (
        year(Dyear),
        month(Dmonth),
        day(Dday)
    );
    this -> priority = priority;
    this -> completed = completed;
}
Task :: ~Task  () {
    //destructor, tambien se resetea propiedades del task a sus valores default
    description = "";
    priority = 0;
    completed = 0;
}

void Task :: setDescription (string d) {
    //description de task
    description = d;
}
void Task :: setPriority (int p) {
    //nivel de prioridad del task
    priority = p;
}
void Task :: setDue (int y, int m, int d) {
    //fecha de entrega del task
    due = year_month_day (
        year(y),
        month(m),
        day(d)
    );
}
void Task :: setCompleted (bool c) {
    // status de completion
    completed = c;
}

string Task :: getDescription () {
    return description;
}
int Task :: getPriority () {
    return priority;
}
year_month_day Task :: getDue () {
    return due;
}
bool Task :: getCompleted () {
    return completed;
}
//gets para cada parte de task

void Task :: display () {
    cout << (completed ? "☑" : (isDue() ? "☒" : "□")) << " " << static_cast<int>(due.year()) << "-" << static_cast<unsigned>(due.month()) << "-" << static_cast<unsigned>(due.day()) << " | " << "Prioridad: " << priority << " | " << description << endl;
}//ensenar los detalles del task
bool Task :: isDue () {
    //revisar si el task es due, basado en el tiempo y fecha de ahora.
    return (year_month_day{time_point_cast<days>(system_clock::now())} >= due);
}