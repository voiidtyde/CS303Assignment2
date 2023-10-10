#include "Professional.h"

//Default professional constructor derived from the Employee class
Professional::Professional(const char* name, int id) : Employee(name, id) {}

//Professional constructor created from Employee class and initializing other private values
Professional::Professional(const char* name, int id, int monthlySalary, int yearsAtCompany)
    : Employee(name, id), monthlySalary(monthlySalary), yearsAtCompany(yearsAtCompany) {}

//Returns weekly salary being the employees monthly salary divided by 4
double Professional::calculateWeeklySalary() {
  return monthlySalary / 4;
}

//Returns health care which is 50 dollars for every year the employee has worked at the company
double Professional::calculateHealthCare() {
  return (50.00 * yearsAtCompany);
}


//Professional employees get 1 vacation day per week
int Professional::calculateVacationDays() {
  return 1;
}

