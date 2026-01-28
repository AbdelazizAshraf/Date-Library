#include "../include/Date.h"
#include <iostream>

int main() {
    // -----------------------------
    // 1️⃣ Create Dates
    // -----------------------------
    clsDate today;  // current system date
    std::cout << "Today: ";
    today.printDate();

    clsDate birthday(15, 3, 1998);  // specific date
    std::cout << "Birthday: ";
    birthday.printDate();

    clsDate fromDayOfYear(75, 2026);  // 75th day of 2026
    std::cout << "75th day of 2026: ";
    fromDayOfYear.printDate();

    clsDate fromString("28/1/2026");  // string to date
    std::cout << "From string: ";
    fromString.printDate();

    // -----------------------------
    // 2️⃣ Date Info
    // -----------------------------
    std::cout << "Is 2026 a leap year? " << (fromString.isLeapYear() ? "Yes" : "No") << "\n";
    std::cout << "Day of the week: " << fromString.nameOfDayBasedOnItsOrder() << "\n";
    std::cout << "Month name: " << fromString.nameOfMonthBasedOnItsOrder() << "\n";
    std::cout << "Day number in year: " << fromString.totalDaysFromTheBeggingOfTheYear() << "\n";

    // -----------------------------
    // 3️⃣ Increase / Decrease Dates
    // -----------------------------
    stDate nextWeek = fromString.increaseDateByOneWeek();
    std::cout << "Next week: " << nextWeek.day << "/" << nextWeek.month << "/" << nextWeek.year << "\n";

    stDate plus10Days = fromString.increasingDateByXDays(10);
    std::cout << "+10 days: " << plus10Days.day << "/" << plus10Days.month << "/" << plus10Days.year << "\n";

    stDate yesterday = fromString.decreaseDateByOneDay();
    std::cout << "Yesterday: " << yesterday.day << "/" << yesterday.month << "/" << yesterday.year << "\n";

    // -----------------------------
    // 4️⃣ Calendar Example
    // -----------------------------
    std::cout << "\nCalendar for January 2026:\n";
    fromString.calenderGenerator(1, 2026);

    std::cout << "\nFull year 2026 calendar:\n";
    fromString.yearCalenderGenerator(2026);

    // -----------------------------
    // 5️⃣ Date Comparison
    // -----------------------------
    stDate d1 = { 1, 1, 2026 };
    stDate d2 = { 28, 1, 2026 };

    std::cout << "Compare 01/01/2026 and 28/01/2026: "
        << fromString.compareTwoDates(d1, d2) << "\n";  // -1 = d1 < d2

    // -----------------------------
    // 6️⃣ Vacation / Business Days
    // -----------------------------
    stDate vacationStart = { 1, 2, 2026 };
    stDate vacationEnd = { 10, 2, 2026 };

    std::cout << "Vacation days (excluding weekends): "
        << fromString.calculateVacationDays(vacationStart, vacationEnd) << "\n";

    stDate returnDate = fromString.calculateVacationReturnDate(vacationStart, 5);
    std::cout << "Return date after 5 business days: "
        << returnDate.day << "/" << returnDate.month << "/" << returnDate.year << "\n";

    // -----------------------------
    // 7️⃣ Age calculation
    // -----------------------------
    int ageInDays = fromString.ageCalculator(birthday.convertStringToDateStructure("15/3/1998"));
    std::cout << "Days since birthday: " << ageInDays << "\n";

    return 0;
}
