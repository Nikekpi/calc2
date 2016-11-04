#include "parser.h"
#include <iostream>
#include <string>

Parser::Parser(const std::string& i_path)
{
    m_file_stream.open(i_path);

    print(i_path);

    _ReadText();

    _Parse();
}

std::vector<Word> Parser::GetResult()
{
    return m_words;
}

void Parser::_ReadText()
{
    if (!m_file_stream)
        return;

    std::string row_text;

    do {
        std::string buffer;
        m_file_stream >> buffer;
        row_text += buffer;
    } while (m_file_stream);


    m_stack_text = row_text;
    print(m_stack_text);
}

void Parser::_InsertWord(Word i_word)
{
	m_words.push_back(i_word);
}

void Parser::_Parse()
{
    for (int i = 0; i < m_stack_text.size(); ++i)
    {
        auto ch = m_stack_text[i];

        switch(ch)
        {
        case '+' :
        {
        	Word w = {Sign::Plus, 0};
        	_InsertWord(w);
            break;
        }
        case '-':
        {
        	Word w = {Sign::Minus, 0};
        	_InsertWord(w);
            break;
        }
        case '*':
        {
        	Word w = {Sign::Multiply, 0};
        	_InsertWord(w);
            break;
        }
        case '/':
        {
        	Word w = {Sign::Divide, 0};
        	_InsertWord(w);
            break;
        }
        case '(':
        {
        	Word w = {Sign::OpenBrackets, 0};
        	_InsertWord(w);
            break;
        }
        case ')':
        {
        	Word w = {Sign::CloseBrackets, 0};
        	_InsertWord(w);
            break;
        }

        default :
        {
        	std::string value;
        	bool is_value = true;
        	int j = i;
        	char temp_number = m_stack_text[j];
        	while(is_value)
        	{
        		if (temp_number < '9' && temp_number > '0' || temp_number == '.' || temp_number == ',')
				{
        			value += temp_number;
        			temp_number = m_stack_text[++j];
				}
        		else
        		{
        			is_value = false;
        		}
        	}
        	i += value.length()-1;
        	double d_value;
        	try
        	{
        		d_value = std::stod(value);
        	}
        	catch(...)
        	{
        		std::cout<<"Wrong convert";
        	}

			Word w = {Sign::Value, d_value};
			_InsertWord(w);
        }
        }

    }
}
