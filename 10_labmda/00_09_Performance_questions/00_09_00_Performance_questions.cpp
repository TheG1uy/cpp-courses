// Compile this to O3 and do performance comparisons.

#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <functional>
#include <chrono>

int x = 0;

void foo(int);

void bar(int v)
{
    x += v;
}


int main() {
    std::vector<int> v(100000000, 1);
    std::function<void(int)> func(foo);

    auto begin = std::chrono::high_resolution_clock::now();

    std::for_each(v.begin(), v.end(), [](int v){
        x += v;
    });

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed_secs = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
    std::cout << elapsed_secs << std::endl;

    begin = std::chrono::high_resolution_clock::now();

    std::for_each(v.begin(), v.end(), bar); // change to foo, f

    end = std::chrono::high_resolution_clock::now();

    elapsed_secs = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
    std::cout << elapsed_secs << std::endl;
}
