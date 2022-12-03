#ifndef __UTIL_H
#define __UTIL_H

#include <string>
#include <ctime>

namespace util {
    time_t get_current_time();
    std::string precision_2_digit(double num, int digits = 2);
    std::string escape_name(std::string s);
}

#endif
