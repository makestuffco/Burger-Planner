#include <iostream>
#include <vector>
#include <string>

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
        {"1lb beef", 1, 3.28, "link to 1lb beef"},
        {"2.25lb beef", 2.25, 7.48, "link to 2.25 beef"},
        {"3lb beef", 3, 9.64, "link to 3lb beef"},
        {"5lb beef", 5, 11.34, "link to 5lb beef"},
        {"10lb beef", 10, 19.88, "link to 10lb beef"}
    }};

    vector<Product> buns_products = {{
        {"8 Pack", 8, 3, "link to 8 pack"},
        {"12 Pack", 12, 5, "link to 12 pack"}
    }};

    for(double burger = 1; burger < 50; burger++)
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