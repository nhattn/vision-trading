#ifndef __BOOK_H
#define __BOOK_H

#include <order.h>

namespace vision {
    class OrderBook {
        public:
            OrderBook();
            ~OrderBook();
            void add(Order order);
            void match(double &quantity);
            void match(Order order, double &quantity);
    };
}

#endif
