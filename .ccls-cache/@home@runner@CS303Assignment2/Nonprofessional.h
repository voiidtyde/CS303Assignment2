#ifndef NONPROFESSIONAL_H
#define NONPROFESSIONAL_H
#include "Employee.h"

class Professional : public Employee {
private: 
  double hourlyRate;
  int hoursWorked;
  int vacationHoursEarned;
  int yearsAtCompany;
public:
  Professional(string& name, int id, double hourlyRate, int hoursWorked, int yearsAtCompany);
  double calculateWeeklySalary() override;
  double calculateHealthCare() override;
  int calculateVacationDays() override;
};
#endif 