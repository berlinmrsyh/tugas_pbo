#include <iostream>
#include <stdexcept>
#include "Date.h"
using namespace std;
 
const string Date::STR_MONTHS[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun",
                                   "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
 
const int Date::DAYS_IN_MONTHS[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
 
const string Date::STR_DAYS[] = {"Sunday", "Monday", "Tuesday", "Wednesday",
                                 "Thursday", "Friday", "Saturday"};
 
bool Date::isLeapYear(int year) {
   return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}
 
bool Date::isValidDate(int y, int m, int d) {
   if (y >= YEAR_MIN && y <= YEAR_MAX && m >= 1 && m <= 12) {
      int lastDayOfMonth = DAYS_IN_MONTHS[m-1];
      if (m == 2 && isLeapYear(y)) {
         lastDayOfMonth = 29;
      }
      return (d >= 1 && d <= lastDayOfMonth);
   } else {
      return false;
   }
}
 
int Date::getDayOfWeek(int y, int m, int d) {
   int centuryTable[] = {4, 2, 0, 6, 4, 2, 0, 6}; // 17xx, 18xx, ...
   int MonthTable[] = {0, 3, 3, 6, 1, 4, 6, 2, 5, 0, 3, 5};
   int MonthLeapYearTable[] = {6, 2, 3, 6, 1, 4, 6, 2, 5, 0, 3, 5};
 
   int century = y / 100;
   int twoDigitYear = y % 100;
   int centuryTableIndex = (century - 17) % 8;

   if (centuryTableIndex < 0) {
      centuryTableIndex += 8;
   }
   int sum = centuryTable[centuryTableIndex] + twoDigitYear + twoDigitYear / 4;
   if (isLeapYear(y)) {
      sum += MonthLeapYearTable[m-1];
   } else {
      sum += MonthTable[m-1];
   }
   sum += d;
   return sum % 7;
}
 
Date::Date(int y, int m, int d) {
   setDate(y, m, d);
}
 
void Date::setDate(int y, int m, int d) {
   setYear(y);
   setMonth(m);
   setDay(d); 
}
 
int Date::getYear() const {
   return year;
}
 
void Date::setYear(int y) {
   if (y >= YEAR_MIN && y <= YEAR_MAX) {
      year = y;
   } else {
      throw invalid_argument("Error: Invalid year (1753-9999)!");
   }
}
 
int Date::getMonth() const {
   return month;
}
 
void Date::setMonth(int m) {
   if (m >= 1 && m <= 12) {
      month = m;
   } else {
      throw invalid_argument("Error: Invalid month (1-12)!");
   }
}
 
int Date::getDay() const {
   return day;
}
 
void Date::setDay(int d) {
   int lastDayOfMonth = DAYS_IN_MONTHS[month-1];
   if (month == 2 && isLeapYear(year)) {
      lastDayOfMonth = 29;
   }
   if (d >= 1 && d <= lastDayOfMonth) {
      day = d;
   } else {
      throw invalid_argument("Error: Invalid day (1-28|29|30|31)!");
   }
}
 
// Print this instance in the format "xxxday, d mmm yyyy".
void Date::print() const {
   cout << STR_DAYS[getDayOfWeek(year, month, day)] << ", "
        << day << " " << STR_MONTHS[month-1] << " " << year << endl;
}
 
// Increment this instance to the next day and return this instance by reference
Date& Date::nextDay() {
   int lastDayOfMonth = DAYS_IN_MONTHS[month-1];
   if (month == 2 && isLeapYear(year)) {
      lastDayOfMonth = 29;
   }
 
   // check day against the end of month
   if (++day > lastDayOfMonth) {
      day = 1;
      if (++month > 12) {
         month = 1;
         if (++year > YEAR_MAX) {
            throw out_of_range("Error: Next day is out of range!");
         }
      }
   }
   return *this;
}
 
// Decrement this instance to the previous day and return this instance by reference
Date& Date::previousDay() {
   int lastDayOfMonth = DAYS_IN_MONTHS[month-1];
   if (month == 2 && isLeapYear(year)) {
      lastDayOfMonth = 29;
   }
 
   // check day against the end of month
   if (--day < 1) {
      day = lastDayOfMonth;
      if (--month < 1) {
         month = 12;
         if (--year < YEAR_MIN) {
            throw out_of_range("Error: Previous day is out of range!");
         }
      }
   }
   return *this;
}
 
// Increment this instance to the next month and return this instance by reference
Date& Date::nextMonth() {
   if (++month > 12) {
      month = 1;
      if (++year > YEAR_MAX) {
         throw out_of_range("Error: Next month is out of range!");
      }
   }
   // may need to adjust the last day of the month
   int lastDayOfMonth = DAYS_IN_MONTHS[month-1];
   if (month == 2 && isLeapYear(year)) {
      lastDayOfMonth = 29;
   }
   if (day > lastDayOfMonth) {
      day = lastDayOfMonth;
   }
   return *this;
}
 
// Decrement this instance to the previous month and return this instance by reference
Date& Date::previousMonth() {
   if (--month < 1) {
      month = 12;
      if (--year < YEAR_MIN) {
         throw out_of_range("Error: Previous month is out of range!");
      }
   }
   // may need to adjust the last day of the month
   int lastDayOfMonth = DAYS_IN_MONTHS[month-1];
   if (month == 2 && isLeapYear(year)) {
      lastDayOfMonth = 29;
   }
   if (day > lastDayOfMonth) {
      day = lastDayOfMonth;
   }
   return *this;
}
 
// Increment this instance to the next year and return this instance by reference
Date& Date::nextYear() {
   if (++year > YEAR_MAX) {
      throw out_of_range("Error: Next year is out of range!");
   }
   // may need to adjust the last day of the month for leap year (29 Feb)
   //  to non-leap year (28 Feb)
   if (month == 2 && day == 29 && !isLeapYear(year)) {
      day = 28;
   }
   return *this;
}
 
// Decrement this instance to the previous year and return this instance by reference
Date& Date::previousYear() {
   if (--year < YEAR_MIN) {
      throw out_of_range("Error: Previous year is out of range!");
   }
   // may need to adjust the last day of the month for leap year (29 Feb)
   //  to non-leap year (28 Feb)
   if (month == 2 && day == 29 && !isLeapYear(year)) {
      day = 28;
   }
   return *this;
}