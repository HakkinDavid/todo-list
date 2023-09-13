#include "task.h"
#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

Task :: Task (string description = "Sin descripción", int Dyear = 2023, int Dmonth = 12, int Dday = 12, int priority = 0, bool completed = false) {
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
    description = "";
    priority = 0;
    completed = 0;
}

void Task :: setDescription (string d) {
    description = d;
}
void Task :: setPriority (int p) {
    priority = p;
}
void Task :: setDue (int y, int m, int d) {
    due = year_month_day (
        year(y),
        month(m),
        day(d)
    );
}
void Task :: setCompleted (bool c) {
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

void Task :: display () {
    cout << (completed ? "☑" : (isDue() ? "☒" : "□")) << " " << static_cast<int>(due.year()) << "-" << static_cast<unsigned>(due.month()) << "-" << static_cast<unsigned>(due.day()) << " | " << description << endl;
}
bool Task :: isDue () {
    return (year_month_day{time_point_cast<days>(system_clock::now())} >= due);
}