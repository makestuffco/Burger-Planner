#include "burgerAPI.h"
#include <vector>
#include <iostream>

using namespace std;

ostream& operator<<(ostream& out, Product const& p)
{
    return out << p.name << '\t';
}

double getQuantity(vector<Product> const& products)
{
    double quantity = 0;
    for(auto const& product : products)
        quantity += product.quantity;
    return quantity;
}

double getPrice(vector<Product> const& products)
{
    //if(products.empty()) return 0xffff;
    double price = 0;
    for(auto const& product : products)
        price += product.price;
    return price;
}

auto getOptions(vector<Product> const& products, double const& quantity_required, vector<Product> const& passthrough = {})
{
    if(getQuantity(passthrough) >= quantity_required) return vector<vector<Product>>{passthrough};

    vector<vector<Product>> output;
    for(auto const& product : products)
    {
        vector<Product> current_state { passthrough.begin(), passthrough.end() };
        current_state.push_back(product);
        auto sub_ops = getOptions(products, quantity_required, current_state);
        output.insert(output.end(), sub_ops.begin(), sub_ops.end());
    }
    return output;
}

vector<Product> getBestOption(vector<Product> const& products, double const quantity_required)
{
    const auto options = getOptions(products, quantity_required);
    vector<Product> best {{"Error: ", 0xffff, 0xffff,"you shouldn't be able to see this"}};
    for(auto const& option : options)
        if(getPrice(option) < getPrice(best))
            best = option;
    return best;
}