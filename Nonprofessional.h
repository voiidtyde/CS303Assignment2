#ifndef NONPROFESSIONAL_H
#define NONPROFESSIONAL_H
#include "Employee.h"

class Nonprofessional : public Employee {
private: 
  double hourlyRate;
  int hoursWorked;
  int vacationHoursEarned;
  int yearsAtCompany;
public:
  Nonprofessional(const char* name, int id);
  Nonprofessional(const char* name, int id, double hourlyRate, int hoursWorked, int yearsAtCompany);
  double calculateWeeklySalary() override;
  double calculateHealthCare() override;
  int calculateVacationDays() override;
};
#endif 