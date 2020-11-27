#include "leap.h"

bool is_leap_year(int year){
    bool divis_by_4 = (year % 4) == 0;
    bool divis_by_100 = (year % 100) == 0;
    bool divis_by_400 = (year % 400) == 0;
    if (divis_by_4) {
        if (divis_by_100) {
            if (divis_by_400) {
                return true;
            }
            return false;
        }
        return true;
    }
    return false;
}
