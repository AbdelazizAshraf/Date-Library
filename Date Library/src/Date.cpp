#define _CRT_SECURE_NO_WARNINGS
#include "../include/Date.h";
#include <iostream>;
#include <ctime>
#include <string>

/*
	Constructors
*/

// Def
clsDate::clsDate() {
	time_t timeInSec = time(0);
	tm localtm;
	localtime_s(&localtm, &timeInSec);
	this->date.day = localtm.tm_mday;
	this->date.month = localtm.tm_mon;
	this->date.year = localtm.tm_year + 1900;

}
// Param
clsDate::clsDate(short day, short month, short year) {
	this->date.day = day;
	this->date.month = month;
	this->date.year = year;

}
// Param
clsDate::clsDate(short days, short year) {
    date = dateForSpecificNumberOfDays(days, year);

}
// Param
clsDate::clsDate(string strDate) {
    stDate innerDate = convertStringToDateStructure(strDate);
    date = innerDate;
}



// Check LeapYear
bool clsDate::isLeapYear() {
	return (date.year % 400 == 0 || date.year % 100 != 0 && date.year % 4 == 0);
}
short clsDate::numberOfDaysInTheYear() {
	return (isLeapYear(date.year) ? 366 : 365);
}
int clsDate::numberOfHourseInTheYear() {
	return (numberOfDaysInTheYear(date.year) * 24);
}
int clsDate::numberOfMinutesInTheYear() {
	return(numberOfHourseInTheYear(date.year) * 60);
} 
int clsDate::numberOfSecondsInTheYear() {
	return (numberOfMinutesInTheYear(date.year) * 60);
}
short clsDate::numberOfDaysInMonth() {

    if (date.month > 0 && date.month <= 12) {

        short Months[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        return (date.month == 2 ? (isLeapYear(date.year) ? 29 : 28) : Months[date.month - 1]);
    }
    else {
        return 0;
    }
}
int clsDate::numberOfDaysTillThisDaySince1970() {
    int DaysFrom1970 = 0;
    int daysInMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    // Number Of Days From 1970 To Previous Year
    for (int i = 1970; i < date.year; ++i) {
        DaysFrom1970 += numberOfDaysInTheYear(i);
    }
    // Number Of Day From 1 Jan To Previous Month;
    if (date.month > 1 && date.month <= 12) {
        for (int i = 1; i < date.month; ++i) {
            DaysFrom1970 += daysInMonth[i - 1];
        }
        if (isLeapYear(date.year) && date.month > 2) {
            DaysFrom1970++;
        }
    }

    // Add Days
    DaysFrom1970 += date.day;

    return DaysFrom1970;
}
int clsDate::orderOfDayInWeek() {
    int orderOfDay = 0;
    int numberofDays = numberOfDaysTillThisDaySince1970(date.year, date.month, date.day);
    orderOfDay = ((numberofDays + 3) % 7);
    return orderOfDay;
}
string clsDate::nameOfDayBasedOnItsOrder() {
    int numOfDay = orderOfDayInWeek();
    switch (numOfDay) {
    case (0): {
        return "Sun";
        break;
    }
    case (1): {
        return "Mon";
        break;
    }
    case (2): {
        return "Tue";
        break;
    }
    case (3): {
        return "Wed";
        break;
    }
    case (4): {
        return"Thu";
        break;
    }
    case (5): {
        return "Fri";
        break;
    }
    case (6): {
        return "Sat";
        break;
    }
    default: {
        return "??";
        break;
    }
    }
}
string clsDate::nameOfMonthBasedOnItsOrder() {
    string months[13] = { "", "Jan", "Feb", "Mar", "Apr", "May", "June", "July", "Aug", "Sep", "Oct", "Nov", "Dec" };
    return months[date.month];
}
void clsDate::calenderGenerator() {

    short firstDayOfTheMonth = orderOfDayInWeek(1, date.month, date.month);
    short	cursor = firstDayOfTheMonth + 1;
    short monthDaysNum = numberOfDaysInMonth(date.month, date.year);

    //                 format 
    cout << "\n" << nameOfMonthBasedOnItsOrder(date.month) << " " << date.year << "\n\n";
    cout << "--------------------------------------------------------------------------------\n";
    cout << left << setw(7) << "Sun" << setw(7) << "Mon" << setw(7) << "Tue" << setw(7) << "Wed" << setw(7) << "Thur" << setw(7) << "Fri" << setw(7) << "Sat" << "\n";
    cout << left << setw(7 * firstDayOfTheMonth) << " ";
    for (int i = 0; i < monthDaysNum; ++i) {
        cout << setw(7) << i + 1;
        if ((cursor) == 7) {
            cout << "\n";
            cursor = 0;
        }
        ++cursor;
    }
    cout << "\n--------------------------------------------------------------------------------\n";

}
void clsDate::yearCalenderGenerator() {
    cout << "===========================  " << date.year << "  ===================================\n";
    for (int i = 0; i < 12; ++i) {
        calenderGenerator(i + 1, date.year);
    }
}
bool clsDate::isValidDate() {
    short monthDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    if (isLeapYear(date.year)) {
        monthDays[1] = 29;
    }

    if (date.month > 12 || date.month < 1) {
        return false;
    }

    if (date.day < 1 || date.day > monthDays[date.month - 1]) {
        return false;
    }
    return true;

}
short clsDate::totalDaysFromTheBeggingOfTheYear() {
    short totalDays = date.day;
    short monthDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    for (int i = 1; i < date.month; ++i) {
        totalDays += monthDays[i - 1];
    }
    if (isLeapYear(date.year) && date.month > 2) {
        ++totalDays;
    }

    return totalDays;


}
stDate clsDate::increasingDateByXDays( int numberToIncrease) {
    stDate newDate;

    while (numberToIncrease > 0)
    {
        short daysInMonth = numberOfDaysInMonth(date.month, date.year);
        short remainingDays = daysInMonth - date.day;

        if (numberToIncrease > (daysInMonth - date.day)) {
            numberToIncrease -= ((daysInMonth - date.day) + 1);
            date.day += (daysInMonth - date.day);
            if (date.day == daysInMonth) {
                if (date.month == 12 && date.day == 31) {
                    date.year++;
                    date.month = 1;
                    date.day = 1;
                }
                else {

                    date.month++;
                    date.day = 1;
                }

            }
        }
        else {
            date.day += numberToIncrease;
            newDate.day = date.day;
            newDate.month = date.month;
            newDate.year = date.year;
            numberToIncrease = 0;
        }

    }
    return newDate;

}
bool  clsDate::isTheLastDayInTheMonth() {

    if (date.day == (numberOfDaysInMonth(date.month, date.year))) {
        return true;
    }
    else {
        return false;
    }

}
bool  clsDate::isTheLastMonthInTheYear() {
    if (date.month == 12) {
        return true;
    }
    else {
        return false;
    }

}
stDate clsDate::increaseDateByOneDay() {
    stDate Date = { date.day, date.month, date.year };
    if (Date.day < numberOfDaysInMonth(date.month, date.year)) {
        Date.day += 1;

    }
    else {
        if (Date.month == 12 && Date.day == 31) {
            Date.year++;
            Date.month = 1;
            Date.day = 1;
        }
        else {
            Date.month++;
            Date.day = 1;
        }
    }
    return Date;
}
short clsDate::numberOfDaysFromTheBeggingOfTheYear() {
    short numberOfDaysInTheYearFromTheBegging{ 0 };

    // number of days from the begging of the year uptill the previous month
    for (int i = 1; i < date.month; ++i) {
        numberOfDaysInTheYearFromTheBegging += numberOfDaysInMonth(i, date.year);
    }
    // Add The Days In |The Current Month
    numberOfDaysInTheYearFromTheBegging += date.day;

    return numberOfDaysInTheYearFromTheBegging;

}

stDate clsDate::increaseDateByOneWeek() {
    stDate Date = increasingDateByXDays(date.day, date.month, date.year, 7);
    return Date;
}
stDate clsDate::increaseDateByXWeeks( short x) {
    stDate Date = increasingDateByXDays(date.day, date.month, date.year, 7 * x);
    return Date;
}
stDate clsDate::increaseDateByOneMonth() {
    stDate Date = increasingDateByXDays(date.day, date.month, date.year, numberOfDaysInMonth(date.month, date.year));
    return Date;
}
stDate clsDate::increaseDateByXMonths( short x) {
    stDate Date = increasingDateByXDays(date.day,date.month, date.year, numberOfDaysInMonth(date.month, date.year) * x);
    return Date;
}
stDate clsDate::decreaseDateByOneDay() {

    stDate Date;
    Date.day = date.day;
    Date.month = date.month;
    Date.year = date.year;
    if (Date.day == 1) {

        if (Date.month == 1) {
            Date.month = 12;
            Date.day = numberOfDaysInMonth(Date.month, Date.year);
            Date.year--;
        }
        else {
            Date.day = numberOfDaysInMonth(Date.month - 1, Date.year);
            Date.month--;
        }
    }
    else {
        Date.day--;
    }

    return Date;

}
stDate clsDate::decreaseDateByXDays( short x) {
    stDate Date;
    Date.day = date.day;
    Date.month = date.month;
    Date.year = date.year;


    while (x != 0) {
        if (x < Date.day) {
            Date.day -= x;
            x = 0;
        }
        else {

            x -= (Date.day);
            if (Date.month == 1) {
                Date.year--;
                Date.month = 12;
                Date.day = numberOfDaysInMonth(Date.month, Date.year);
            }
            else {
                Date.day = numberOfDaysInMonth(Date.month - 1, Date.year);
                Date.month--;
            }


        }


    }




    return Date;
}
bool clsDate::isEndOfWeek() {
    short theOrderOfTheDay = orderOfDayInWeek(date.year, date.month, date.day);
    return (theOrderOfTheDay == 6);

}
bool clsDate::isWeekEnd() {
    short theOrderOfTheDay = orderOfDayInWeek(date.year, date.month, date.day);
    return (theOrderOfTheDay == 5 || theOrderOfTheDay == 6);
}
bool clsDate::isBussinessDay() {
    return (!isWeekEnd(date));
}


short clsDate::calculateVacationDays(stDate Date1, stDate Date2) {
    // number of vacation days 
    // actual vacation days = total days - number of weekends
    // total days 
    short numberOfVacationDays = diffDaysBetweenTwoDates(Date1, Date2);

    // number of weekends

    stDate Date;
    Date.day = Date1.day;
    Date.month = Date1.month;
    Date.year = Date1.year;
    short numberOfWeekEnds{ 0 };
    for (int i = 0; i < numberOfVacationDays; ++i) {
        if (isWeekEnd(Date)) {
            numberOfWeekEnds++;
        }
        Date = increaseDateByOneDay(Date.day, Date.month, Date.year);
    }

    return (numberOfVacationDays - numberOfWeekEnds);
}
stDate clsDate::calculateVacationReturnDate(stDate Date, short vacationDays) {


    while (vacationDays != 0) {
        if (isBussinessDay(Date)) {
            vacationDays--;
            Date = increaseDateByOneDay(Date.day, Date.month, Date.year);
        }
        else {
            Date = increaseDateByOneDay(Date.day, Date.month, Date.year);
        }
    }
    return Date;

}
bool  clsDate::isDate1EqualDate2(stDate Date1, stDate Date2) {
    return(Date1.day == Date2.day && Date1.month == Date2.month && Date1.year == Date2.year);
}
bool  clsDate::isDate1BeforeDate2(stDate Date1, stDate Date2) {
    if (Date1.year < Date2.year) {
        return true;
    }
    else if (Date1.year == Date2.year) {
        if (Date1.month < Date2.month) {
            return true;
        }
        else if (Date1.month == Date2.month) {
            if (Date1.day < Date2.day) {
                return true;
            }

        }
    }
    else {
        return false;
    }
}
bool  clsDate::isDate1AfterDate2(stDate Date1, stDate Date2) {
    if (!isDate1BeforeDate2(Date1, Date2) && !isDate1EqualDate2(Date1, Date2)) {
        return true;
    }
}
short clsDate::compareTwoDates(stDate Date1, stDate Date2) {
    if (isDate1BeforeDate2(Date1, Date2)) {
        return -1;
    }
    else if (isDate1AfterDate2(Date1, Date2)) {

        return 1;
    }
    else {
        return 0;
    }
}
bool clsDate::isOverlap(period period1, period period2) {
    if (compareTwoDates(period1.EndDate, period2.startDate) == -1) return false;
    if (compareTwoDates(period2.EndDate, period1.startDate) == -1) return false;
    return true;

}
bool clsDate::isDateWithinThePeriod(period periodOfTwoDates, stDate Date) {

    return(compareTwoDates(Date, periodOfTwoDates.EndDate) <= 0 && compareTwoDates(Date, periodOfTwoDates.startDate) >= 0);
}
short clsDate::lengthOfPeriod(period period1) {

    short length{ 0 };

    stDate startPointDate;
    startPointDate.day = period1.startDate.day;
    startPointDate.month = period1.startDate.month;
    startPointDate.year = period1.startDate.year;
    while (!isDate1EqualDate2(startPointDate, increaseDateByOneDay(period1.EndDate.day, period1.EndDate.month, period1.EndDate.year))) {
        length++;
        startPointDate = increaseDateByOneDay(startPointDate.day, startPointDate.month, startPointDate.year);
    }

    return length;
}
short clsDate::countOfOverlappedDays(period period1, period period2) {
    short countOfOverlapsDays{ 0 };
    short lengthOfPeriodOne = lengthOfPeriod(period1);
    short lengthOfPeriodTwo = lengthOfPeriod(period2);

    if (!isOverlap(period1, period2)) {
        return 0;

    }


    if (isDate1BeforeDate2(period1.startDate, period2.startDate)) {
        countOfOverlapsDays = diffDaysBetweenTwoDates(period2.startDate, period1.EndDate);
    }
    else if (isDate1BeforeDate2(period2.startDate, period1.startDate)) {
        countOfOverlapsDays = diffDaysBetweenTwoDates(period1.startDate, period2.EndDate);


    }
    else {
        if (lengthOfPeriodOne < lengthOfPeriodTwo) {
            return lengthOfPeriodOne;
        }
    }




    return countOfOverlapsDays;
}
string clsDate::convertStructureToString(stDate StDate) {
    string Date = "";
    Date += to_string(StDate.day) + "/";
    Date += to_string(StDate.month) + "/";
    Date += to_string(StDate.year);
    return Date;
}

stDate clsDate::convertStringToDateStructure(string Date) {
    stDate stDate;
    stDate.day = stoi(Date.substr(0, Date.find("/") + 1));


    Date.erase(0, Date.find("/") + 1);


    stDate.month = stoi(Date.substr(0, Date.find("/") + 1));


    Date.erase(0, Date.find("/") + 1);

    stDate.year = stoi(Date.substr(0, Date.length()));

    return stDate;

}


// The Definition of Static Variables
bool clsDate::isLeapYear(short number) {
    return (number % 400 == 0 || number % 100 != 0 && number % 4 == 0);
}
short clsDate::numberOfDaysInTheYear(short year) {
    return (isLeapYear(year) ? 366 : 365);
}
int clsDate::numberOfHourseInTheYear(short year) {
    return (numberOfDaysInTheYear(year) * 24);
}
int clsDate::numberOfMinutesInTheYear(short year) {
    return(numberOfHourseInTheYear(year) * 60);
}
int clsDate::numberOfSecondsInTheYear(short year) {
    return (numberOfMinutesInTheYear(year) * 60);
}
short clsDate::numberOfDaysInMonth(int numberofMonth, int year) {
 
    if (numberofMonth > 0 && numberofMonth <= 12) {

        short Months[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        return (numberofMonth == 2 ? (isLeapYear(year) ? 29 : 28) : Months[numberofMonth - 1]);
    }
    else {
        return 0;
    }
}
int clsDate::numberOfDaysTillThisDaySince1970(int year, int month, int day) {
    int DaysFrom1970 = 0;
    int daysInMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    // Number Of Days From 1970 To Previous Year
    for (int i = 1970; i < year; ++i) {
        DaysFrom1970 += numberOfDaysInTheYear(i);
    }
    // Number Of Day From 1 Jan To Previous Month;
    if (month > 1 && month <= 12) {
        for (int i = 1; i < month; ++i) {
            DaysFrom1970 += daysInMonth[i - 1];
        }
        if (isLeapYear(year) && month > 2) {
            DaysFrom1970++;
        }
    }

    // Add Days
    DaysFrom1970 += day;

    return DaysFrom1970;
}
int clsDate::orderOfDayInWeek(int year, int month, int day) {
    int orderOfDay = 0;
    int numberofDays = numberOfDaysTillThisDaySince1970(year, month, day);
    orderOfDay = ((numberofDays + 3) % 7);
    return orderOfDay;
}
string clsDate::nameOfDayBasedOnItsOrder(int numOfDay) {
    switch (numOfDay) {
    case (0): {
        return "Sun";
        break;
    }
    case (1): {
        return "Mon";
        break;
    }
    case (2): {
        return "Tue";
        break;
    }
    case (3): {
        return "Wed";
        break;
    }
    case (4): {
        return"Thu";
        break;
    }
    case (5): {
        return "Fri";
        break;
    }
    case (6): {
        return "Sat";
        break;
    }
    default: {
        return "??";
        break;
    }
    }
}
string clsDate::nameOfMonthBasedOnItsOrder(short number) {
    string months[13] = { "", "Jan", "Feb", "Mar", "Apr", "May", "June", "July", "Aug", "Sep", "Oct", "Nov", "Dec" };
    return months[number];
}
void clsDate::calenderGenerator(short month, short year) {

    short firstDayOfTheMonth = orderOfDayInWeek(1, month, year);
    short	cursor = firstDayOfTheMonth + 1;
    short monthDaysNum = numberOfDaysInMonth(month, year);

    //                 format 
    cout << "\n" << nameOfMonthBasedOnItsOrder(month) << " " << year << "\n\n";
    cout << "--------------------------------------------------------------------------------\n";
    cout << left << setw(7) << "Sun" << setw(7) << "Mon" << setw(7) << "Tue" << setw(7) << "Wed" << setw(7) << "Thur" << setw(7) << "Fri" << setw(7) << "Sat" << "\n";
    cout << left << setw(7 * firstDayOfTheMonth) << " ";
    for (int i = 0; i < monthDaysNum; ++i) {
        cout << setw(7) << i + 1;
        if ((cursor) == 7) {
            cout << "\n";
            cursor = 0;
        }
        ++cursor;
    }
    cout << "\n--------------------------------------------------------------------------------\n";

}
void clsDate::yearCalenderGenerator(short year) {
    cout << "===========================  " << year << "  ===================================\n";
    for (int i = 0; i < 12; ++i) {
        calenderGenerator(i + 1, year);
    }
}
bool clsDate::isValidDate(short day, short month, short year) {
    short monthDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    if (isLeapYear(year)) {
        monthDays[1] = 29;
    }

    if (month > 12 || month < 1) {
        return false;
    }

    if (day < 1 || day > monthDays[month - 1]) {
        return false;
    }
    return true;

}
short clsDate::totalDaysFromTheBeggingOfTheYear(short day, short month, short year) {
    short totalDays = day;
    short monthDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    for (int i = 1; i < month; ++i) {
        totalDays += monthDays[i - 1];
    }
    if (isLeapYear(year) && month > 2) {
        ++totalDays;
    }

    return totalDays;


}
stDate clsDate::dateForSpecificNumberOfDays(short numberOfDays, short year) {
    stDate innerDate;
    int i = 0;
    short monthDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (isLeapYear(year)) {
        monthDays[1] = 29;
    }
    int month{ 0 };
    int day{ 0 };
    while (numberOfDays > monthDays[i]) {
        numberOfDays -= monthDays[i];
        ++month;
        ++i;
    }

    day = numberOfDays;
    innerDate.day = day;
    innerDate.month = month;
    innerDate.year = year;

    return innerDate;


}
stDate clsDate::increasingDateByXDays(short day, short month, short year, int numberToIncrease) {
    stDate newDate;

    while (numberToIncrease > 0)
    {
        short daysInMonth = numberOfDaysInMonth(month, year);
        short remainingDays = daysInMonth - day;

        if (numberToIncrease > (daysInMonth - day)) {
            numberToIncrease -= ((daysInMonth - day) + 1);
            day += (daysInMonth - day);
            if (day == daysInMonth) {
                if (month == 12 && day == 31) {
                    year++;
                    month = 1;
                    day = 1;
                }
                else {

                    month++;
                    day = 1;
                }

            }
        }
        else {
            day += numberToIncrease;
            newDate.day = day;
            newDate.month = month;
            newDate.year = year;
            numberToIncrease = 0;
        }

    }
    return newDate;

}
bool  clsDate::isTheLastDayInTheMonth(short day, short month, short year) {

    if (day == (numberOfDaysInMonth(month, year))) {
        return true;
    }
    else {
        return false;
    }

}
bool  clsDate::isTheLastMonthInTheYear(short month) {
    if (month == 12) {
        return true;
    }
    else {
        return false;
    }

}
stDate clsDate::increaseDateByOneDay(short day, short month, short year) {
    stDate Date = { day, month, year };
    if (Date.day < numberOfDaysInMonth(month, year)) {
        Date.day += 1;

    }
    else {
        if (Date.month == 12 && Date.day == 31) {
            Date.year++;
            Date.month = 1;
            Date.day = 1;
        }
        else {
            Date.month++;
            Date.day = 1;
        }
    }
    return Date;
}
short clsDate::numberOfDaysFromTheBeggingOfTheYear(short day, short month, short year) {
    short numberOfDaysInTheYearFromTheBegging{ 0 };

    // number of days from the begging of the year uptill the previous month
    for (int i = 1; i < month; ++i) {
        numberOfDaysInTheYearFromTheBegging += numberOfDaysInMonth(i, year);
    }
    // Add The Days In |The Current Month
    numberOfDaysInTheYearFromTheBegging += day;

    return numberOfDaysInTheYearFromTheBegging;

}
int clsDate::diffDaysBetweenTwoDates(stDate date1, stDate date2) {
    int numberOfDiffDays{ 0 };

    if (date1.year != date2.year) {

        // the remaining Days in The Date1
        numberOfDiffDays += (numberOfDaysInTheYear(date1.year) - numberOfDaysFromTheBeggingOfTheYear(date1.day, date1.month, date1.year));

        // number of Days From The begging of The year in Date2
        numberOfDiffDays += numberOfDaysFromTheBeggingOfTheYear(date2.day, date2.month, date2.year);

        //Days in Years between year1 and year2 
        for (int i = date1.year; (i + 1) < date2.year; ++i) {
            numberOfDiffDays += numberOfDaysInTheYear(i + 1);
        }

    }
    else {
        numberOfDiffDays = numberOfDaysFromTheBeggingOfTheYear(date2.day, date2.month, date2.year) - numberOfDaysFromTheBeggingOfTheYear(date1.day, date1.month, date1.year);
    }

    return numberOfDiffDays;
}
int clsDate::ageCalculator(stDate date_1) {
    int NumberOfAgeDays{ 0 };

    // First Get The Now Date By gmtime();

    time_t numberOfSecFrom1970 = time(0);

    // create a pointer its type is time structure this structure has the date information that return from gmtime (&ref of variable that hold the number of seconds )
    tm* dt = gmtime(&numberOfSecFrom1970);


    // Create A structure from the date type to send it to  function
    stDate date_2;
    date_2.day = dt->tm_mday;
    date_2.month = dt->tm_mon + 1;
    date_2.year = (dt->tm_year + 1900);


    NumberOfAgeDays = diffDaysBetweenTwoDates(date_1, date_2);
    return NumberOfAgeDays;

}
stDate clsDate::increaseDateByOneWeek(short day, short month, short year) {
    stDate Date = increasingDateByXDays(day, month, year, 7);
    return Date;
}
stDate clsDate::increaseDateByXWeeks(short day, short month, short year, short x) {
    stDate Date = increasingDateByXDays(day, month, year, 7 * x);
    return Date;
}
stDate clsDate::increaseDateByOneMonth(short day, short month, short year) {
    stDate Date = increasingDateByXDays(day, month, year, numberOfDaysInMonth(month, year));
    return Date;
}
stDate clsDate::increaseDateByXMonths(short day, short month, short year, short x) {
    stDate Date = increasingDateByXDays(day, month, year, numberOfDaysInMonth(month, year) * x);
    return Date;
}
stDate clsDate::decreaseDateByOneDay(short day, short month, short year) {

    stDate Date;
    Date.day = day;
    Date.month = month;
    Date.year = year;
    if (Date.day == 1) {

        if (Date.month == 1) {
            Date.month = 12;
            Date.day = numberOfDaysInMonth(Date.month, Date.year);
            Date.year--;
        }
        else {
            Date.day = numberOfDaysInMonth(Date.month - 1, Date.year);
            Date.month--;
        }
    }
    else {
        Date.day--;
    }

    return Date;

}
stDate clsDate::decreaseDateByXDays(short day, short month, short year, short x) {
    stDate Date;
    Date.day = day;
    Date.month = month;
    Date.year = year;


    while (x != 0) {
        if (x < Date.day) {
            Date.day -= x;
            x = 0;
        }
        else {

            x -= (Date.day);
            if (Date.month == 1) {
                Date.year--;
                Date.month = 12;
                Date.day = numberOfDaysInMonth(Date.month, Date.year);
            }
            else {
                Date.day = numberOfDaysInMonth(Date.month - 1, Date.year);
                Date.month--;
            }


        }


    }




    return Date;
}
bool clsDate::isEndOfWeek(stDate Date) {
    short theOrderOfTheDay = orderOfDayInWeek(Date.year, Date.month, Date.day);
    return (theOrderOfTheDay == 6);

}
bool clsDate::isWeekEnd(stDate Date) {
    short theOrderOfTheDay = orderOfDayInWeek(Date.year, Date.month, Date.day);
    return (theOrderOfTheDay == 5 || theOrderOfTheDay == 6);
}
bool clsDate::isBussinessDay(stDate Date) {
    return (!isWeekEnd(Date));
}
string clsDate::converDateToString() {
    string Date = "";
    Date += to_string(date.day) + "/";
    Date += to_string(date.month) + "/";
    Date += to_string(date.year);
    return Date;
}
void clsDate::printDate() {
    cout << date.day << "/" << date.month << "/" << date.year << "\n";
}