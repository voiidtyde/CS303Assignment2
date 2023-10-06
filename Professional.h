#ifndef PROFESSIONAL_H
#define PROFESSIONAL_H
#include "Employee.h"

class Professional : public Employee {
private: 
  int monthlySalary;
  int vacationDays;
  int yearsAtCompany;
public:
  Professional(const char* name, int id);
  Professional(const char* name, int id, int monthlySalary, int yearsAtCompany);
  double calculateWeeklySalary() override;
  double calculateHealthCare() override;
  int calculateVacationDays() override;
};
#endif 