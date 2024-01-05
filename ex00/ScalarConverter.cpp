#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &obj) 
{
	*this = obj;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &obj) 
{
	(void)obj;
	return *this;
}

ScalarConverter::~ScalarConverter() {}

void	ScalarConverter::convert(std::string input)
{
	std::string	joinedInput;
	char		charConverted;
	int			intConverted;
	//float		floatConverted;
	//double		doubleConverted;

	joinedInput = ConverterUtil::deleteWhiteSpace(input);
	try
	{
		std::istringstream	iss(joinedInput);
		int					tempInt;

		std::cout << "char: ";

		iss >> tempInt;
		//std::cout << "tempInt: " << tempInt << std::endl;
		if (iss.fail() || !iss.eof() || joinedInput.empty())
			throw	std::invalid_argument("impossible");
			
		if (ConverterUtil::isValidChar(tempInt) == false)
			throw	ConverterUtil::RangeException();
		if (ConverterUtil::isDisplayableChar(tempInt) == false)
			throw	ConverterUtil::charDisplayException();

		charConverted = static_cast<char>(tempInt);
		std::cout << charConverted << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}//convert char

	try
	{
		std::cout << "int : ";
		if (ConverterUtil::isFloat(joinedInput) == true)
			intConverted = ConverterUtil::floatToInt(joinedInput);
		else
		{
			//std::cout << "is not Float" << std::endl;
			std::istringstream	iss(joinedInput);
			iss >> intConverted;
			if (iss.fail() || !iss.eof() || joinedInput.empty())
				throw	std::invalid_argument("impossible");
		}
		std::cout << intConverted << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}//+부호 처리는?
