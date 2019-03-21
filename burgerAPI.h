#pragma once
#include <string>
#include <vector>

struct Product
{
    std::string name;
    double quantity;
    double price;
    std::string link;
};

extern std::ostream& operator<<(std::ostream& out, Product const& p);
extern std::vector<Product> getBestOption(std::vector<Product> const& products, double const& quantity_required);