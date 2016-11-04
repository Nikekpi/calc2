#include <iostream>
#include <vector>

#include "parser.h"
#include "calc.h"

int main()
{
	std::cout << "Hello";
    Parser parser("calc.txt");
    auto words = parser.GetResult();
	double result = Calc(words);
	print(result);
    return 0;
}
