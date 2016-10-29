#pragma once

#include <string>

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
