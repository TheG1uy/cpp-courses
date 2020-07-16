// Show ways to save lambda expressions.

#include <iostream>
#include <functional>

using pointer = void(*)(int);

int main() {
    auto x = [](int){};
    // show same lambda
    // auto y = [](int){};
    // static_assert(std::is_same<decltype(x), decltype(y)>{}, "Different types");

    x(3);
    pointer p = [](int){}; // only stateless

    auto cx = x; // copy ctor

    std::function<void(int)> f(x); // create lambda container
    return 0;
}
