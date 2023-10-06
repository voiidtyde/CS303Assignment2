#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>
#include <iomanip>
#include <iostream>
using namespace std;

class Employee {
public:
  Employee(const char* name, int id) {
    name = name;
    id = id;
  }
  //Creates the three pure virtual functions that will be used in the derived classes
  virtual double calculateWeeklySalary() = 0;
  virtual double calculateHealthCare() = 0;
  virtual int calculateVacationDays() = 0;

//Protected members relevant to ALL employees
protected:
  string name;
  int id;
};


#endif 