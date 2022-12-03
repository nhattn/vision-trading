#include <iostream>
#include <order.h>
#include <util.h>

int main(int argc, char **argv) {
    vision::Order ord(1, "RMF23", 1892, 2, static_cast<int>(util::get_current_time()), vision::OrderAction::BUY, vision::OrderType::LIMIT);
    std::cout << ord.to_string() << std::endl;
    vision::Order ord1(2, "RX\"03", 1896, 1,  static_cast<int>(util::get_current_time()));
    std::cout << ord1.to_string() << std::endl;
    return 0;
}
