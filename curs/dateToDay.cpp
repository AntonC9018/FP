#include <stdio.h>
#include <conio.h>
#include <math.h>

// Enter a date in format dd.mm.yyyy
// figure out what day of week it is

// We're going to base off of today, 22.11.2019, which is a Friday

// The algorithm is as follows:
//      1. figure out how many days are in the date entered
//      2. calculate the offset off 22.11.2019
//      3. mod 7 that, to ignore all whole weeks that have passed
//      4. add the rest to Friday (4) to get the answer

// the days of week array
const char *daysOfWeek[] = {
    "Monday",
    "Tuesday",
    "Wednesday",
    "Thursday",
    "Friday",
    "Saturday",
    "Sunday"
};

const int weekLength = sizeof(daysOfWeek) / sizeof(char*);
const int maxDay = 31;
const int maxMonth = 12;


// mapping of month number 
// to number of days in it (leap year)
const int monthDaysLeap[] = {
    31, // january
    28, // february
    31, // march
    30, // april
    31, // may
    30, // june
    31, // july
    31, // august
    30, // september
    31, // october
    30, // november
    31, // december
};

// mapping of month number
// to number of days in it (non-leap year)
const int monthDaysNonLeap[] = {
    31, // january
    27, // february
    31, // march
    30, // april
    31, // may
    30, // june
    31, // july
    31, // august
    30, // september
    31, // october
    30, // november
    31, // december
};


int leapYearLength = 0, nonLeapYearLength = 0;

const int baseYear = 2019;
const int baseMonth = 11 - 1; // november (starting from 0)
const int baseDay = 22;
const int baseWeekDay = 5 - 1; // friday

int scanDate(int *day, int *month, int *year);
int convertDateToDays(int day, int month, int year);
int convertToInteger(char buffer[], int length);
int validateInputDecimal(char buffer[], int length);
int validateDate(char buffer[], int length, int maxValue);

int main()
{
    // calculate non-leap year length (364)
    for (int i = 0; i < sizeof(monthDaysNonLeap) / sizeof(int); i++) {
        nonLeapYearLength += monthDaysNonLeap[i];
    }

    // calculate leap year length (365)
    for (int i = 0; i < sizeof(monthDaysLeap) / sizeof(int); i++) {
        leapYearLength += monthDaysLeap[i];
    }
    
    // calculate how many days are in the base data
    int baseNumDays = convertDateToDays(baseDay, baseMonth, baseYear);

    // prompt user for input
    printf("Input the date in the format [dd.mm.yyyy]: ");

    // get user input in format
    // dd.mm.yyyy
    int day, month, year;
    int valid = scanDate(&day, &month, &year);
    if (!valid) return 1;

    // get day number in the date the user entered
    int inputNumDays = convertDateToDays(day, month, year);

    int difference = inputNumDays - baseNumDays;

    int weekDayIndex = (difference + baseWeekDay) % weekLength;

    if (weekDayIndex < 0) {
        weekDayIndex += weekLength;
    }

    printf("That day will be a %s.", daysOfWeek[weekDayIndex]);

    return 0;
}

int convertDateToDays(int day, int month, int year) {
    // figure out whether the current year has been a leap year
    int isLeap = year % 4 == 0;
    year--;
    // figure out the number of leap years in that year
    int numLeapYears = year / 4;
    int numNonLeapYears = year - numLeapYears;

    // start with the number of days that have passed 
    // since the start of this month
    int result = day;

    // sum the number of days in all months 
    // of this year before the current one
    if (isLeap)
        for (int i = month - 1; i >= 0; i--) {
            result += monthDaysLeap[i];
        }
    else
        for (int i = month - 1; i >= 0; i--) {
            result += monthDaysNonLeap[i];
        }

    // add years contributions
    result += numLeapYears * leapYearLength;
    result += numNonLeapYears * nonLeapYearLength;

    return result;
}

// let user input the date in the format [dd.mm.yyyy] 
// returns 1 if the input were successful, 0 otherwise
int scanDate(int *day, int *month, int *year) {

    char buffer[6];

    // enter a string
    // enter year as usual
    // dd.mm.yyyy
    scanf("%3s%3s%4i", buffer, buffer + 3, year);
    // one probably could've used scanf("%i%i%i") 
    // haven't been the conditions this strict
    // + we get some custom valudation and show off that we
    // can convert a buffer into a number

    // get user input
    // dd.
    *day = validateDate(buffer, 3, maxDay);
    if (*day == -1) 
        return 0;
    
    // mm.
    *month = validateDate(buffer + 3, 3, maxMonth);
    if (*month == -1)
        return 0;    

    // decrement by 1
    // do not use this syntax: *month--
    // as this won't decrement it
    // parenthesis are necessary as '--' operator has higher precedence
    // so it would first decrement the 'month' pointer and then 
    // the * operator would take effect, resulting in no effect
    (*month)--;

    // figure out if the year entered is a leap year
    int isLeap = *year % 4 == 0;

    // validate day entered
    if (isLeap) {
        if (*day > monthDaysLeap[*month]) {
            printf("Invalid input. The month you entered has %i days, but received day = %i.",
                monthDaysLeap[*month], *day);
            return 0;
        }
    } else {
        if (*day > monthDaysLeap[*month]) {
            printf("Invalid input. The month you entered has %i days, but received day = %i.",
                   monthDaysLeap[*month], *day);
            return 0;
        }
    }
    return 1;
}

// check if all values are in range from '0' through '9'
int validateInputDecimal(char buffer[], int length) {
    for (int i = 0; i < length; i++) {
        if (buffer[i] < '0' || buffer[i] > '9') {
            return 0;
        }
    }
    return 1;
}

// convert characters from the input buffer, e.g.
// { '1', '9', '6' }
// 1 is the first entered value, 9 is the second etc
// into a number (considering entered in decimal), e.g.
// 6 + 9 * 10 + 1 * 10 * 10 = 196
int convertToInteger(char buffer[], int length) {
    int result = buffer[0] - '0';
    for (int i = 1; i < length; i++) {
        result *= 10;
        result += buffer[i] - '0';
    }
    return result;
}

// length = maximum number of characters that one can enter
// e.g. while entering the first part "dd.", length = 3
// assume buffer is a substring of a string that has the user input
int validateDate(char buffer[], int length, int maxValue) {

    if (buffer[length - 1] != '.') {
        puts("\nInvalid input. Expected a number followed by a dot.");
        return -1;
    }

    // validate input (check for no letters)
    if (!validateInputDecimal(buffer, length - 1)) {
        puts("\nInvalid input. You must input just numbers.");
        return -1;
    }

    // convert input to a number
    int result = convertToInteger(buffer, length - 1);

    // do not let it exceed the maxDay (or maxMonth) limit
    if (maxValue != -1 && result > maxValue) {
        printf("\nInvalid input. Expected number to be <= %i, received %i.",
               maxValue, result);
        return -1;
    }

    return result;
}