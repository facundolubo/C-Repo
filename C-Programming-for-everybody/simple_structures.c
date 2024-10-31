#include <stdio.h>
#include <stdlib.h>

struct simpledate {
    int day;
    int month;
    int year;
};


static int day_tab[2][13] = {
  {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
  {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(struct simpledate *pd) /* set day of year from month, day */
{
	int month = pd->month;
	int sum_days = 0;
	int year = pd->year - 2023;
	for (int i = 1; i < month; i++) {
		sum_days += day_tab[year][i];
	}
	sum_days += pd->day;
    return sum_days;
}

void dump_date(struct simpledate *pd)
{
    /* The date should be in the following format - note that */
    /* The month and day are always two digits with leading zeros */
    printf("%04d/%02d/%02d\n", pd->year, (*pd).month, pd->day);
}

int main() {
    void dump_date();
    printf("Playing with structures\n");
    struct simpledate sd;

    sd.year = 2023;
    sd.month = 2;
    sd.day = 11;
    dump_date(&sd);
    printf("Day of year %d\n", day_of_year(&sd));

    sd.year = 2023;
    sd.month = 9;
    sd.day = 15;
    dump_date(&sd);
    printf("Day of year %d\n", day_of_year(&sd));

    sd.year = 2024;
    sd.month = 9;
    sd.day = 15;
    dump_date(&sd);
    printf("Day of year %d\n", day_of_year(&sd));
	return 0;
}
