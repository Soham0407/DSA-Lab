#include <stdio.h>
int isLeapYear(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        return 1;
    return 0;
}

int main()
{
    int month, year, i, day;
    int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    char *months[12] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"};

    char *days[7] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};

    printf("Enter month (1-12): ");
    scanf("%d", &month);

    printf("Enter year: ");
    scanf("%d", &year);

    if (month == 2 && isLeapYear(year))
        daysInMonth[1] = 29;

    int totalDays = 0;
    for (i = 1; i < year; i++)
    {
        if (isLeapYear(i))
            totalDays += 366;
        else
            totalDays += 365;
    }

    for (i = 0; i < month - 1; i++)
        totalDays += daysInMonth[i];

    int startDay = (totalDays + 1) % 7;

    printf("%s %d\n", months[month - 1], year);

    for (i = 0; i < 7; i++)
        printf("%s ", days[i]);

    printf("\n");

    for (i = 0; i < startDay; i++)
        printf("    ");

    for (day = 1; day <= daysInMonth[month - 1]; day++)
    {
        printf("%3d ", day);

        if ((day + startDay) % 7 == 0)
            printf("\n");
    }
    return 0;
}
