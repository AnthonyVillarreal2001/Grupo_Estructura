#include <iostream>
using namespace std;

int main() {
    
    int a = 2;
    int b = 1;
    int c = 21;

    auto suma = [&](int& a) -> int {
         
        b += 1;
        c += 1;


        return a +  b + c;
    
    };

    std::cout << suma(a) << std::endl;
    std::cout << b << std::endl;
    std::cout << c << std::endl;


    return 0;
}