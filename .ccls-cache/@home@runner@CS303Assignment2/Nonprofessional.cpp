#include "Nonprofessional.h"

Nonprofessional::Nonprofessional(const char* name, int id) : Employee(name, id) {}

Nonprofessional::Nonprofessional(const char* name, int id, double hourlyRate, int hoursWorked, int yearsAtCompany)
    : Employee(name, id), hourlyRate(hourlyRate), hoursWorked(hoursWorked), yearsAtCompany(yearsAtCompany) {}

double Nonprofessional::calculateWeeklySalary() {
  return (hourlyRate * hoursWorked);
}

double Nonprofessional::calculateHealthCare() {
  return (5 * hoursWorked);
}

int Nonprofessional::calculateVacationDays() {
  if ((hoursWorked >= 40) && (yearsAtCompany >= 2)) {
    return 1;
  }
  return 0;
}