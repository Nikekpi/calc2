#pragma once

#include <string>
#include <iostream>

template <class T>
void print(const T i_s)
{
	std::cout << "\n" << i_s << "\n";
}

struct Sign
{
    enum type
    {
		Plus,
		Minus,
		Multiply,
		Divide,
		OpenBrackets,
		CloseBrackets,
		Value
    };
};

struct Word
{
    Sign::type m_type;
    double m_value;
};
