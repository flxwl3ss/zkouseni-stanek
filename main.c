#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int sum_of_digits(int number)
{
    int sum = 0;
    while (number > 0)
    {
        sum += number % 10;
        number /= 10;
    }
    return sum;
}

int main()
{
    time_t time_raw_format;
    struct tm *ptr_time;
    char buffer[50];

    time(&time_raw_format);
    ptr_time = localtime(&time_raw_format);
    if (strftime(buffer, sizeof(buffer), "%d.%m.%Y", ptr_time) == 0)
    {
        perror("Error formatting date");
        return 1;
    }

    printf("Datum: %s\n\n", buffer);

    int day, month;
    char *endptr = buffer;
    day = strtoul(endptr, &endptr, 10);
    endptr++;
    month = strtoul(endptr, &endptr, 10);

    int vyvolany_scitani = day + month;
    vyvolany_scitani = (vyvolany_scitani - 1) % 29 + 1;

    int digit_sum = sum_of_digits(day) + sum_of_digits(month);

    const char *output[] =
    {
        "not in list", "1", "2", "3", "4", "5", "6", "7", "8", "9",
        "10", "11", "12", "13", "14", "15", "16", "17", "18", "19",
        "20", "21", "22", "23", "24", "25", "26", "27", "28", "29"
    };

    if (vyvolany_scitani >= 1 && vyvolany_scitani <= 29)
    {
        printf("Vyvolany: %s\n", output[vyvolany_scitani]);
    }
    else
    {
        printf("Vyvolany: %s\n", output[0]);
    }

    printf("Vyvolany nad nim: %s\n", output[vyvolany_scitani + 1]);

    printf("Vyvolany pod nim: %s\n", output[vyvolany_scitani - 1]);

    printf("RNG od stanka: %s\n", output [vyvolany_scitani = digit_sum]);


    return 0;
}
