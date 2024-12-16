#include "Sales_item.h"
#include <iostream>

// input operator
std::istream &operator>>(std::istream &is, Sales_item &item) {
    std::cout << "insert the isbn, number of sold copies and sale price: ";
    is >> item.isbn_code >> item.copies_sold >> item.sale_price;
    if (!is) {
        std::cerr << "input error" << std::endl;
        item = Sales_item(); // redefinirlo con los valores por default
    }

    return is;
}

// output operator
std::ostream &operator<<(std::ostream &os, const Sales_item &item) {
    os << "ISBN: " << item.isbn_code << std::endl << "Copies sold: " << item.copies_sold << std::endl << "Sale price: " << item.sale_price << std::endl;

    return os;
}

Sales_item operator+(const Sales_item &item1, const Sales_item &item2) {
    if (item1.isbn_code != item2.isbn_code) {
        throw std::invalid_argument("ISBNs does not match");
    }

    Sales_item result;
    result.isbn_code = item1.isbn_code;
    result.sale_price = item1.sale_price + item2.sale_price;
    result.copies_sold = item1.copies_sold + item2.copies_sold;

    return result;
}
