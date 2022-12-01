#include <order.h>

namespace vision {
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
        return "{\"id\":" + std::to_string(ID) + ",\"name\":\"" + Name + "\""
               ",\"price\":" + std::to_string(Price) + ",\"quantity\":" + std::to_string(Quantity) + ","
               "\"action\":\"" + vision::to_string(Action) + "\",\"type\":\"" + vision::to_string(Type) + "\"}";
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
