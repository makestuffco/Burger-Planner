#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <set>

#include "burgerAPI.h"

using namespace std;

template<typename T>auto print(std::vector<T> const& vect)
{
    for(auto const& id : vect)
    {
        cout << id << '\t';
    }
    cout << '\n';
}

int main()
{
    vector<Product> beef_products = {{
        {"1lb beef", 1, 5, "link to 1lb beef"},
        {"2.25lb beef", 2.25, 8, "link to 2.25 beef"},
        {"5lb beef", 5, 15, "link to 5lb beef"}
    }};

    vector<Product> buns_products = {{
        {"8 Pack", 8, 3, "link to 8 pack"},
        {"12 Pack", 12, 5, "link to 12 pack"}
    }};

    for(double burger = 1; burger < 40; burger++)
    {
        auto beef = getBestOption(beef_products, burger/4);
        auto buns = getBestOption(buns_products, burger);
        
        cout << burger << '\t';
        print(beef);

        cout << '\t';
        print(buns);
        cout << '\n';
    }
}