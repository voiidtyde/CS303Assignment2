#include "Nonprofessional.h"

//Nonprofessional default constructor derived from Employee class
Nonprofessional::Nonprofessional(const char* name, int id) : Employee(name, id) {}

//Nonprofessional constructor created from Employee class and initializing other private values
Nonprofessional::Nonprofessional(const char* name, int id, double hourlyRate, int hoursWorked, int yearsAtCompany)
    : Employee(name, id), hourlyRate(hourlyRate), hoursWorked(hoursWorked), yearsAtCompany(yearsAtCompany) {}

//Returns weekly salary based on the hourly rate and hours worked
double Nonprofessional::calculateWeeklySalary() {
  return (hourlyRate * hoursWorked);
}

//Returns health care which is 5 dollars for every hour worked
double Nonprofessional::calculateHealthCare() {
  return (5 * hoursWorked);
}

//Returns a vacation day if the employee worked at least 40 hours and has been at the compant for at least 2 years, otherwise no vacation days
int Nonprofessional::calculateVacationDays() {
  if ((hoursWorked >= 40) && (yearsAtCompany >= 2)) {
    return 1;
  }
  return 0;
}