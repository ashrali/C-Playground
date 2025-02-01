#include <iostream>
#include <ctime>
using namespace std;

int main()
{
    int BirthYear, BirthMonth, BirthDate;
    
    // Get current time
    time_t timestamp = time(nullptr);
    struct tm *currentTime = localtime(&timestamp);
    
    // Extract current date
    int currentYear = currentTime->tm_year + 1900;
    int currentMonth = currentTime->tm_mon + 1;
    int currentDay = currentTime->tm_mday;

    cout << "Enter your birth year: ";
    cin >> BirthYear;
    cout << "Enter your birth month: ";
    cin >> BirthMonth;
    cout << "Enter your birth date (day of the month): ";
    cin >> BirthDate;

    // Calculate age in years
    int ageInYears = currentYear - BirthYear;
    if (currentMonth < BirthMonth || (currentMonth == BirthMonth && currentDay < BirthDate)) {
        ageInYears--;  // Adjust if current date is before birthday this year
    }

    // Calculate age in months
    int ageInMonths = (currentYear - BirthYear) * 12 + (currentMonth - BirthMonth);
    if (currentMonth < BirthMonth) {
        ageInMonths--;  // Adjust if current month is before birth month
    }

    // Calculate age in days
    int ageInDays = (currentYear - BirthYear) * 365 + (currentMonth - BirthMonth) * 30 + (currentDay - BirthDate);
    
    // Adjust for days in each month and leap years
    for (int i = BirthYear; i < currentYear; i++) {
        ageInDays += (i % 4 == 0 && (i % 100 != 0 || i % 400 == 0)) ? 366 : 365;
    }
    
    cout << "Age in years: " << ageInYears << endl;
    cout << "Age in months: " << ageInMonths << endl;
    cout << "Age in days: " << ageInDays << endl;

    return 0;
}