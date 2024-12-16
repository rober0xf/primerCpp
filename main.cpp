#include "Sales_item.h"
#include <iostream>
#include <ostream>

int main(int argc, char *argv[]) {
    Sales_item item1;
    Sales_item item2;

    std::cin >> item1;
    std::cin >> item2;

    std::cout << item1 << std::endl;
    std::cout << "the profit is: " << item1.get_profit() << std::endl;

    Sales_item result = item1 + item2;
    std::cout << "new isbn: " << result.get_isbn() << " copies sold: " << result.get_copies_sold() << " sale_price: " << result.get_sale_price() << std::endl;

    return 0;
}
