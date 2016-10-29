#include <iostream>
#include "parser.h"
#include <vector>

int main()
{
	std::cout << "Hello";
    Parser parser("calc.txt");
    auto words = parser.GetResult();
    print(words.size());
    return 0;
}
