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
  ~Employee();
  virtual double calculateWeeklySalary() = 0;
  virtual double calculateHealthCare() = 0;
  virtual int calculateVacationDays() = 0;

protected:
  string name;
  int id;
};


#endif 