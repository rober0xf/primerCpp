#ifndef SALES_ITEM_H
#define SALES_ITEM_H

#include <istream>
#include <ostream>
#include <string>
#include <sys/types.h>

class Sales_item {
    friend std::istream &operator>>(std::istream &is, Sales_item &item);
    friend std::ostream &operator<<(std::ostream &os, const Sales_item &item);
    friend Sales_item operator+(const Sales_item &item1, const Sales_item &item2);
    friend bool operator==(const Sales_item &item1, const Sales_item &item2);

  public:
    // default initilization
    Sales_item() = default;

    std::string get_isbn() const { return isbn_code; }
    unsigned get_copies_sold() const { return copies_sold; }
    double get_sale_price() const { return sale_price; }
    double get_profit() const { return profit(); }
    double get_average_price() const {
        if (copies_sold == 0) {
            return 0.0;
        }
        return (copies_sold * sale_price) / copies_sold;
    }

  private:
    std::string isbn_code;
    unsigned copies_sold = 0;
    double sale_price = 0;
    double profit() const { return (copies_sold * sale_price); }
};

#endif // SALES_ITEM_H
