#include <iostream>
#include "Array.h"
#include <vector>
using namespace justin_su;
int main()
{
    Array<int>arr({1},12);
    arr.print();

    std::cout << arr.length() << std::endl;
    arr.removeAt(2);
    arr.print();
    std::cout << arr.length() << std::endl;



    return 0;
}
