#include "Employee.h"
#include "Professional.h"
#include "Nonprofessional.h"

int main() {
  //Creating an instance for each derived class (Professional and Nonprofessional)
  Professional tommy("Tommy", 1, 25000, 5);
  Nonprofessional jacob("Jacob", 2, 13.00, 40, 3);

  //Tests for Professional class derived functions
  cout << "Professional Weekly Salary: " << tommy.calculateWeeklySalary() << endl;
  cout << "Professional Health Care: " << tommy.calculateHealthCare() << endl;
  cout << "Professional Vacation Days: " << tommy.calculateVacationDays() << endl << endl;

  //Tests for Nonprofessional class derived functions
  cout << "Nonprofessional Weekly Salary: " << jacob.calculateWeeklySalary() << endl;
  cout << "Nonprofessional Health Care: " << jacob.calculateHealthCare() << endl;
  cout << "Nonprofessional Vacation Days: " << jacob.calculateVacationDays() << endl;
}