#pragma once

#include <iostream>
#include "parser.h"
#include <string>
#include <vector>

#include <fstream>

#include "word.h"

template <class T>
void print(const T i_s)
{
	std::cout << "\n" << i_s << "\n";
}

class Parser
{
public:
	Parser(const std::string& i_path);
    std::vector<Word> GetResult();

private:
    void _Parse();
    void _ReadText();
    void _InsertWord(Word i_word);

private:
    std::string m_stack_text;
	std::ifstream m_file_stream;

    std::vector<Word> m_words;
};
