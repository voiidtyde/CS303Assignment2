#include "Professional.h"

Professional::Professional(string& name, int id, int monthlySalary, int yearsAtCompany)
    : Employee(name, id), monthlySalary(monthlySalary), yearsAtCompany(yearsAtCompany) {}

double Professional::calculateWeeklySalary() {
  return monthlySalary / 4;
}

double Professional::calculateHealthCare() {
  return (50.00 * yearsAtCompany);
}

int Professional::calculateVacationDays() {
  return 1;
}

