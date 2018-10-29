#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h> 
#include <time.h>
#include <regex>
#include <iterator>
#include <sstream>

void swap(int &a, int &b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

std::vector <int> ranList(int num)
{
	srand((unsigned int) time(NULL));
	std::vector <int> list;
	int x = 0;
	list.resize(num);
	for (auto & y : list)
	{
		y = x;
		x++;
	}
	for (int i = 0; i < num; i++)
	{
		x = rand() % num;
		swap(list[x], list[num - i - 1]);
	}
	return list;
}

int main()
{
	std::regex word_regex("(\\S+)");
	std::string input, output;
	std::getline(std::cin, input);
	auto words_begin = std::sregex_iterator(input.begin(), input.end(), word_regex);
	auto words_end = std::sregex_iterator();
	for (std::sregex_iterator i = words_begin; i != words_end; ++i)
	{
		std::smatch match = *i;
		std::string match_str = match.str();
		if (match_str.length() <= 2)
		{
			output += match_str + " ";
		}
		else
		{
			auto list = ranList(match_str.length() - 2);
			std::string str;
			str.resize(match_str.length());
			int p = 0;
			for (auto &x : str)
			{
				if (p == 0 || p == match_str.length() - 1)
				{
					x = match_str[p];
				}
				else
				{
					x = match_str[list[p - 1] + 1];
				}
				p++;
			}
			output += str + " ";
		}
	}
	std::cout << output;
	return 0;
}