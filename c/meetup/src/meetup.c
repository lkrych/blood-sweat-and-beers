#include "meetup.h"
#include <time.h>
#include <string.h>
#include <stdio.h>

#define TEENTH 9
#define LAST 8

const char * weekday[] = { "Sunday", "Monday",
                             "Tuesday", "Wednesday",
                             "Thursday", "Friday", "Saturday"};

int get_count(const char* week) {
    if (strcmp(week, "first") == 0) {
        return 1;
    } else if (strcmp(week, "second") == 0) {
        return 2;
    } else if (strcmp(week, "third") == 0) {
        return 3;
    } else if (strcmp(week, "fourth") == 0) {
        return 4;
    } else if (strcmp(week, "teenth") == 0) {
        // nonsense number we can use as switch
        return TEENTH;
    } else if (strcmp(week, "last") == 0) {
        return LAST;
    }
    return 5;
}


int meetup_day_of_month(unsigned int year, unsigned int month, const char *week, const char *day_of_week) {
    int month_for_time_struct = month - 1;
    // printf("=====================================\n");
    // printf("Constructing tm for %s, %u %u\n", day_of_week, month_for_time_struct, year-1900);
    // printf("=====================================\n");
    struct tm t = { .tm_year=year-1900, .tm_mon=month_for_time_struct, .tm_mday=1};
    mktime(&t);
    int day_of_week_count = 0;
    int day_of_month = 1;
    int needed_count = get_count(week);
    int last_counted_day = 0;
    // printf("=====================================\n");
    // printf("searching for %d, %s\n", needed_count, day_of_week);
    // printf("=====================================\n");
    int current_month = (int) month_for_time_struct;
    while (current_month == (int) month_for_time_struct) {
        const char* current_day = weekday[t.tm_wday];
        // printf("current day is %s, current count is %d\n", current_day, day_of_week_count);
        if (current_day == day_of_week) {
            day_of_week_count += 1;
            last_counted_day = day_of_month;
            if (needed_count == TEENTH && day_of_month >= 13 && day_of_month <= 19) {
                // found the teenth day
                break;
            }
        }
        if (day_of_week_count == needed_count) {
            break;
        }

        // keep marching along
        t.tm_mday += 1;
        mktime(&t);
        day_of_month += 1;
        current_month = t.tm_mon;
    }
    
    if (needed_count == LAST) {
        return last_counted_day;
    }

    return day_of_month;
}
