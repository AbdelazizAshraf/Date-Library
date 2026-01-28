#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;

	struct stDate {
		short day = 0;
		short month = 0;
		short year = 0;
	};

	struct period {
		stDate startDate;
		stDate EndDate;
	};


class clsDate
{
private:
	stDate date;

public:
	clsDate();
	clsDate(short day, short month, short year);
	clsDate(short days, short year);
	clsDate(string strDate);

	bool isLeapYear( );
	static bool isLeapYear(short number);


	short numberOfDaysInTheYear();
	static short numberOfDaysInTheYear(short year);

	int numberOfHourseInTheYear();
	static int numberOfHourseInTheYear(short year);
	
	int numberOfMinutesInTheYear();
	static int numberOfMinutesInTheYear(short year);

	int numberOfSecondsInTheYear();
	static int numberOfSecondsInTheYear(short year);

	short numberOfDaysInMonth();
	static short numberOfDaysInMonth(int numberofMonth, int year);

	int numberOfDaysTillThisDaySince1970();
	static int numberOfDaysTillThisDaySince1970(int year, int month, int day);

	int orderOfDayInWeek();
	static int orderOfDayInWeek(int year, int month, int day);

	string nameOfDayBasedOnItsOrder();
	static string nameOfDayBasedOnItsOrder(int numOfDay);

	string nameOfMonthBasedOnItsOrder();
	static string nameOfMonthBasedOnItsOrder(short number);

	void calenderGenerator();
	static void calenderGenerator(short month, short year);

	void yearCalenderGenerator();
	static void yearCalenderGenerator(short year);

	bool isValidDate();
	static bool isValidDate(short day, short month, short year);

	short totalDaysFromTheBeggingOfTheYear();
	static short totalDaysFromTheBeggingOfTheYear(short day, short month, short year);
	
	static stDate dateForSpecificNumberOfDays(short numberOfDays, short year);

	stDate increasingDateByXDays( int numberToIncrease);
	static stDate increasingDateByXDays(short day, short month, short year, int numberToIncrease);

	bool  isTheLastDayInTheMonth();
	static bool  isTheLastDayInTheMonth(short day, short month, short year);

	bool  isTheLastMonthInTheYear();
	static bool  isTheLastMonthInTheYear(short month);

	stDate increaseDateByOneDay();
	static stDate increaseDateByOneDay(short day, short month, short year);

	short numberOfDaysFromTheBeggingOfTheYear();
	static short numberOfDaysFromTheBeggingOfTheYear(short day, short month, short year);

	static int diffDaysBetweenTwoDates(stDate date1, stDate date2);
	
	static int ageCalculator(stDate date_1);
	
	stDate increaseDateByOneWeek();
	static 	stDate increaseDateByOneWeek(short day, short month, short year);

	stDate increaseDateByXWeeks( short x);
	static stDate increaseDateByXWeeks(short day, short month, short year, short x);

	stDate increaseDateByOneMonth();
	static stDate increaseDateByOneMonth(short day, short month, short year);

	stDate increaseDateByXMonths( short x);
	static stDate increaseDateByXMonths(short day, short month, short year, short x);

	stDate decreaseDateByOneDay();
	static stDate decreaseDateByOneDay(short day, short month, short year);

	stDate decreaseDateByXDays( short x);
	static stDate decreaseDateByXDays(short day, short month, short year, short x);

	bool isEndOfWeek();
	static bool isEndOfWeek(stDate Date);

	bool isWeekEnd();
	static bool isWeekEnd(stDate Date);

	bool isBussinessDay();
	static bool isBussinessDay(stDate Date);

	static short calculateVacationDays(stDate Date1, stDate Date2);

	static stDate calculateVacationReturnDate(stDate Date, short vacationDays);
	
	static bool isDate1EqualDate2(stDate Date1, stDate Date2);
	static bool isDate1BeforeDate2(stDate Date1, stDate Date2);
	static bool isDate1AfterDate2(stDate Date1, stDate Date2);
	static short compareTwoDates(stDate Date1, stDate Date2);
	static bool isOverlap(period period1, period period2);
	static bool isDateWithinThePeriod(period periodOfTwoDates, stDate Date);
	static short lengthOfPeriod(period period1);
	static short countOfOverlappedDays(period period1, period period2);
	string converDateToString();
	static string convertStructureToString(stDate StDate);

	static stDate convertStringToDateStructure(string Date);
	void printDate();
};


