#include <util.h>
#include <iomanip>
#include <sstream>

namespace util {
    time_t get_current_time() {
        auto time = std::time(nullptr);
        std::tm *tm = std::localtime(&time);
        return std::mktime(tm);
    }
    std::string precision_2_digit(double num, int digits) {
        std::ostringstream ss;
        ss << std::fixed;
        ss << std::setprecision(digits);
        ss << num;
        return ss.str();
    }
    std::string escape_name(std::string s) {
        std::string res;
        for(unsigned int i = 0; i < s.length(); i++) {
            if (s.at(i) == '"') {
                if (i == 0 || s.at(i - 1) != '\\') {
                    res.append(1, '\\');
                }
            }
            res.append(1, s.at(i));
        }
        return res;
    }
}
