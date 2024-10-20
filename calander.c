#include <stdio.h>

int main() {
    int year, month, daysInMonth, startingDay, dayOfWeek;

    
    printf("Enter year: ");
    scanf("%d", &year);
    printf("Enter month (1-12): ");
    scanf("%d", &month);

    if (month == 2) {
        
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
            daysInMonth = 29;
        else
            daysInMonth = 28;
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        daysInMonth = 30;
    } else {
        daysInMonth = 31;
    }

    
    startingDay = (year - 1) * 365 + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400;
    for (int i = 1; i < month; ++i) {
        if (i == 2) {
            if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
                startingDay += 29;
            else
                startingDay += 28;
        } else if (i == 4 || i == 6 || i == 9 || i == 11) {
            startingDay += 30;
        } else {
            startingDay += 31;
        }
    }
    dayOfWeek = (startingDay + 1) % 7; 

    
    printf("\n==============================\n");
    printf("       %d-%02d\n", year, month);
    printf("==============================\n");
    printf(" Sun Mon Tue Wed Thu Fri Sat\n");

    
    for (int i = 0; i < dayOfWeek; ++i) {
        printf("    ");
    }

    for (int day = 1; day <= daysInMonth; ++day) {
        printf("%4d", day);
        if ((day + dayOfWeek) % 7 == 0) {
            printf("\n");
        }
    }

    printf("\n");
    return 0;
}