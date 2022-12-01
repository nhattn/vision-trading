#include <iostream>
#include <order.h>

int main(int argc, char **argv) {
    vision::Order ord(1, "RMF23", 1892, 2, static_cast<int>(time(nullptr)), vision::OrderAction::BUY, vision::OrderType::LIMIT);
    std::cout << ord.to_string() << std::endl;
    return 0;
}
