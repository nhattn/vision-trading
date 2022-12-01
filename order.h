#ifndef __ORDER_H
#define __ORDER_H

#include <string>

namespace vision {
    enum class OrderAction {
        BUY,
        SELL,
        HOLD
    };
    enum class OrderType {
        LIMIT,
        FOLLOW,
        STOP
    };
    struct Order {
        public:
            Order(int id, std::string name, double price, double quantity,
                  int time, OrderAction action = OrderAction::BUY,
                  OrderType type = OrderType::LIMIT);
            ~Order();
            std::string to_string() const;
            bool operator == ( const Order &rhs );
            bool operator != ( const Order &rhs );
            int ID;
            std::string Name;
            double Price;
            double Quantity;
            int Time;
            OrderAction Action;
            OrderType Type;
    };
    const std::string to_string(OrderAction action);
    const std::string to_string(OrderType type);
}

#endif
