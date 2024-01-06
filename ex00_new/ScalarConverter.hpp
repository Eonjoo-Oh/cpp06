#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <cstdlib>
#include <sstream>
#include "ConverterUtil.hpp"

class	ConverterUtil;

class	ScalarConverter
{
	public :
		ScalarConverter();
		ScalarConverter(const ScalarConverter &obj);
		ScalarConverter &operator = (const ScalarConverter  &obj);
		~ScalarConverter();
		static void	convert(std::string input);
};

#endif