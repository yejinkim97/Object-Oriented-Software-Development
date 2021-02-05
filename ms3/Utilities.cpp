// Name: Ye Jin Kim	
// Seneca Student ID: 163291180
// Seneca email: yjkim33@myseneca.ca
// Date of completion: Nov 12th, 2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#define _CRT_SECURE_NO_WARNINGS
#include "Utilities.h"

using namespace std;

char Utilities::m_delimiter;

void Utilities::setFieldWidth(size_t newWidth)
{
	m_widthField = newWidth;
}
size_t Utilities::getFieldWidth() const
{
	return m_widthField;
}
std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more)
{
	string token;
	if (next_pos <= str.length())
	{
		size_t loc = str.find_first_of(m_delimiter, next_pos);
		if (loc != string::npos)
		{
			token = str.substr(next_pos, loc - next_pos);
			next_pos = loc + 1;
		}
		else
		{
			token = str.substr(next_pos);
			next_pos = str.length() + 1;
		}
		if ((token.empty()) && (next_pos != str.length() + 1))
		{
			more = false;
			throw str + "<== Error: There are two delimiters with no token.";
		}
		if (m_widthField < token.length())
			m_widthField = token.length();
		more = next_pos <= str.length();
	}
		return token;
}
void Utilities::setDelimiter(char newDelimiter)
{
	m_delimiter = newDelimiter;
}
char Utilities::getDelimiter()
{
	return m_delimiter;
}

