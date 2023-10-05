#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>
#include <iostream>
using namespace std;

class Employee {
public:
  Employee(string& name, int id) {
    name = name;
    id = id;
    healthCare = 0;
  }
  ~Employee();
  virtual double calculateWeeklySalary() = 0;
  virtual double calculateHealthCare() = 0;
  virtual int calculateVacationDays() = 0;

protected:
  string name;
  int id;
  double healthCare;
};


#endif