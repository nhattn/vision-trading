#include <order.h>
#include <iomanip>
#include <sstream>

namespace vision {
    namespace {
        inline std::string precision_2_digit(double num) {
            std::ostringstream ss;
            ss << std::fixed;
            ss << std::setprecision(2);
            ss << num;
            return ss.str();
        }
        inline std::string escape_name(std::string s) {
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
    Order::Order(int id, std::string name, double price, double quantity,
           int time, OrderAction action, OrderType type) : ID(id),
        Name(name), Price(price), Quantity(quantity), Time(time),
        Action(action), Type(type) {}
    Order::~Order() {}
    bool Order::operator == ( const Order &rhs ) {
        if (
            ID != rhs.ID || Name != rhs.Name
            || Price != rhs.Price || Quantity != rhs.Quantity
            || Time != rhs.Time || Type != rhs.Type || Action != rhs.Action
        ) {
            return false;
        }
        return true;
    }
    bool Order::operator != ( const Order &rhs ) {
        return !operator == (rhs);
    }
    std::string Order::to_string() const {
        return "{\"id\":" + std::to_string(ID) + ",\"name\":\"" + escape_name(Name) + "\""
               ",\"price\":" + precision_2_digit(Price) + ",\"quantity\":" + precision_2_digit(Quantity) + ","
               "\"action\":\"" + vision::to_string(Action) + "\",\"type\":\"" + vision::to_string(Type) + "\""
               ",\"timestamp\":" + std::to_string(Time) + "}";
    }
    const std::string to_string(OrderAction action) {
        if(action == OrderAction::SELL) return std::string("Sell");
        if (action == OrderAction::BUY) return std::string("Buy");
        if(action == OrderAction::HOLD) return std::string("Hold");
        return std::string("Buy");
    }
    const std::string to_string(OrderType type) {
        if(type == OrderType::LIMIT) return std::string("Limit");
        if(type == OrderType::FOLLOW) return std::string("Follow");
        if (type == OrderType::STOP) return std::string("Stop");
        return std::string("Limit");
    }
}
