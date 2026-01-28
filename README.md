# Date Library

# 📅 clsDate — Full Date Utility Library in C++

A complete custom **Date handling library** built from scratch in C++ without relying on advanced STL date utilities.

This class provides powerful tools for:

- Date validation
- Date arithmetic (add / subtract days, weeks, months)
- Calendar generation
- Period and overlap calculations
- Vacation day calculations (excluding weekends)
- Age calculation
- Day / Month name detection
- Difference between dates
- Conversions between string and date structure

---

## 🧱 Date Structure

```cpp
struct stDate
{
    short day;
    short month;
    short year;
};
````

---

## 🏗 Constructors

| Constructor                 | Description                                     |
| --------------------------- | ----------------------------------------------- |
| `clsDate()`                 | Initializes object with **current system date** |
| `clsDate(day, month, year)` | Create date manually                            |
| `clsDate(days, year)`       | Create date from day-number in year             |
| `clsDate("dd/mm/yyyy")`     | Create date from string                         |

---

## 📆 Leap Year & Year Info

| Function                         | Description                    |
| -------------------------------- | ------------------------------ |
| `isLeapYear()`                   | Check if object's year is leap |
| `isLeapYear(year)`               | Static version                 |
| `numberOfDaysInTheYear(year)`    | 365 or 366                     |
| `numberOfHourseInTheYear(year)`  | Hours in year                  |
| `numberOfMinutesInTheYear(year)` | Minutes in year                |
| `numberOfSecondsInTheYear(year)` | Seconds in year                |

---

## 🗓 Month & Day Info

| Function                             | Description                 |
| ------------------------------------ | --------------------------- |
| `numberOfDaysInMonth()`              | Days in current month       |
| `numberOfDaysInMonth(month, year)`   | Static version              |
| `nameOfDayBasedOnItsOrder()`         | Sun, Mon, Tue...            |
| `nameOfDayBasedOnItsOrder(numOfDay)` | Static version by order 0–6 |
| `nameOfMonthBasedOnItsOrder()`       | Jan, Feb, Mar...            |
| `nameOfMonthBasedOnItsOrder(number)` | Static version              |
| `orderOfDayInWeek()`                 | Returns 0–6 (Sun–Sat)       |
| `orderOfDayInWeek(year, month, day)` | Static version              |

---

## 🧮 Date Calculations

| Function                                             | Description                 |
| ---------------------------------------------------- | --------------------------- |
| `totalDaysFromTheBeggingOfTheYear()`                 | Day number in year          |
| `totalDaysFromTheBeggingOfTheYear(day, month, year)` | Static version              |
| `numberOfDaysTillThisDaySince1970()`                 | Days since epoch            |
| `numberOfDaysTillThisDaySince1970(year, month, day)` | Static version              |
| `diffDaysBetweenTwoDates(d1, d2)`                    | Difference in days          |
| `ageCalculator(date)`                                | Age in days from given date |

---

## ➕ Increase Date

| Function                   | Description |
| -------------------------- | ----------- |
| `increaseDateByOneDay()`   | +1 day      |
| `increaseDateByXDays(x)`   | +X days     |
| `increaseDateByOneWeek()`  | +7 days     |
| `increaseDateByXWeeks(x)`  | +7×x days   |
| `increaseDateByOneMonth()` | +1 month    |
| `increaseDateByXMonths(x)` | +X months   |

Also available as **static versions** with parameters (`day, month, year`).

---

## ➖ Decrease Date

| Function                 | Description |
| ------------------------ | ----------- |
| `decreaseDateByOneDay()` | -1 day      |
| `decreaseDateByXDays(x)` | -X days     |

Also available as **static versions** with parameters (`day, month, year`).

---

## ✅ Validation

| Function                        | Description          |
| ------------------------------- | -------------------- |
| `isValidDate()`                 | Validate object date |
| `isValidDate(day, month, year)` | Static version       |

---

## 📊 Calendar Generation

| Function                         | Description                          |
| -------------------------------- | ------------------------------------ |
| `calenderGenerator()`            | Print month calendar for object date |
| `calenderGenerator(month, year)` | Static version                       |
| `yearCalenderGenerator()`        | Print full year for object date      |
| `yearCalenderGenerator(year)`    | Static version                       |

---

## 📅 Week & Business Logic

| Function               | Description           |
| ---------------------- | --------------------- |
| `isEndOfWeek()`        | Is Saturday           |
| `isEndOfWeek(date)`    | Static version        |
| `isWeekEnd()`          | Is Friday or Saturday |
| `isWeekEnd(date)`      | Static version        |
| `isBussinessDay()`     | Not weekend           |
| `isBussinessDay(date)` | Static version        |

---

## 🧾 Period & Overlap

```cpp
struct period
{
    stDate startDate;
    stDate EndDate;
};
```

| Function                         | Description          |
| -------------------------------- | -------------------- |
| `isOverlap(p1, p2)`              | Check overlap        |
| `lengthOfPeriod(p)`              | Days in period       |
| `countOfOverlappedDays(p1, p2)`  | Overlap days         |
| `isDateWithinThePeriod(p, date)` | Check date in period |

---

## 🏖 Vacation Calculations

| Function                                  | Description                |
| ----------------------------------------- | -------------------------- |
| `calculateVacationDays(d1, d2)`           | Excludes weekends          |
| `calculateVacationReturnDate(date, days)` | Return date after vacation |

---

## 🔁 Date Comparison

| Function                     | Description |
| ---------------------------- | ----------- |
| `isDate1EqualDate2(d1, d2)`  | Equal       |
| `isDate1BeforeDate2(d1, d2)` | Before      |
| `isDate1AfterDate2(d1, d2)`  | After       |
| `compareTwoDates(d1, d2)`    | -1, 0, 1    |

---

## 🔄 Conversions

| Function                            | Description          |
| ----------------------------------- | -------------------- |
| `convertStructureToString(date)`    | `dd/mm/yyyy`         |
| `convertStringToDateStructure(str)` | String → struct      |
| `converDateToString()`              | Object date → string |
| `printDate()`                       | Print date           |

---

## 🧠 Special Utilities

| Function                                  | Description               |
| ----------------------------------------- | ------------------------- |
| `dateForSpecificNumberOfDays(days, year)` | Convert day number → date |
| `numberOfDaysFromTheBeggingOfTheYear()`   | Day order in year         |

---

## 🖥 Example Usage

```cpp
clsDate today;
today.printDate();

clsDate custom(15, 3, 2025);
cout << custom.nameOfDayBasedOnItsOrder();

stDate nextWeek = custom.increaseDateByOneWeek();
```

---

## 🎯 What This Project Demonstrates

This project shows strong understanding of:

* Date algorithms
* Calendar mathematics
* Struct manipulation
* Static vs member functions
* Real-world business logic (vacation, periods, overlap)
* Working with system time (`time_t`, `tm`, `localtime_s`, `gmtime`)

---

## 🚀 Author

**Abdelaziz Ballouz**
Custom Date Library built as part of mastering C++ fundamentals and OOP.

> This project is an educational demonstration of how date systems work internally without relying on built-in date libraries.

```



