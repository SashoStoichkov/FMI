#include <iostream>
using namespace std;

#include "birthdate.h"

bool checkDay(int day) { return (day >= 1 && day <= 31); }

bool checkMonth(int month) { return (month >= 1 && month <= 12); }

bool checkYear(int year) { return (year >= 1970); }

bool checkDate(int day, int month, int year) {
  return (checkDay(day) && checkMonth(month) && checkYear(year));
}

String toString(int day, int month, int year) {
  char date[11];
  sprintf(date, "%02d.%02d.%04d", day, month, year);
  return String(date);
}

BirthDate::BirthDate(int day, int month, int year) {
  if (checkDate(day, month, year)) {
    this->day = day;
    this->month = month;
    this->year = year;

    date = toString(day, month, year);
  }
}

void BirthDate::setDay(int day) {
  if (checkDay(day)) {
    this->day = day;
    date = toString(day, month, year);
  }
}

void BirthDate::setMonth(int month) {
  if (checkMonth(month)) {
    this->month = month;
    date = toString(day, month, year);
  }
}

void BirthDate::setYear(int year) {
  if (checkYear(year)) {
    this->year = year;
    date = toString(day, month, year);
  }
}

int BirthDate::getDay() const { return day; }

int BirthDate::getMonth() const { return month; }

int BirthDate::getYear() const { return year; }

String BirthDate::getDate() const { return date; }