#include "ScalarConverter.hpp"

//constructors and destructors
ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &a)
{
	(void)a;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &a)
{
	if (this != &a) {}
	return (*this);
}

ScalarConverter::~ScalarConverter() {}

// helper funcs
std::string toupperStr(std::string input)
{
    for (int i = 0; input[i]; i++)
		input[i] = (char)std::toupper(input[i]);
    return (input);
}

void printValue(std::string charVal, std::string intVal, std::string floatVal, std::string doubleVal)
{
	std::cout << "char: " << charVal << "\nint: " << intVal << "\nfloat: " << floatVal << "\ndouble: " << doubleVal << std::endl;
	exit(0);
}

// converters
void convertChar(std::string input)
{
    char c      = input[0];
    int i       = static_cast<int>(input[0]);
    float f     = static_cast<float>(input[0]);
    double d    = static_cast<double>(input[0]);

    std::cout << "char: '" << c << "'" << std::endl;
    std::cout << "int: " << i << std::endl;
    std::cout << std::fixed << std::setprecision(1) << "float: " << f << "f" << std::endl;
    std::cout << std::fixed << std::setprecision(1) << "double: " << d << std::endl;
}

void convertNumber(std::string input)
{
    char c;
    int i;
    float f;
    double d;

    try
    {
        long l = std::atol(input.c_str());
        if (l > std::numeric_limits<int>::max() || l < std::numeric_limits<int>::min())
        {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
        }
        else
        {
            i = std::atoi(input.c_str());
            c = static_cast<char>(i);
            if (i >= 32 && i <= 126)
                std::cout << "char: '" << c << "'" << std::endl;
            else if (i < 0 || i > 255)
                std::cout << "char: impossible" << std::endl;
            else
                std::cout << "char: non displayable" << std::endl;
            i = std::atoi(input.c_str());
            std::cout << "int: " << i << std::endl;
        }
    }
    catch (const std::out_of_range&)
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
    }

    try
    {
        f = std::atof(input.c_str());
        if (f > std::numeric_limits<float>::max() || f < -std::numeric_limits<float>::max())
            std::cout << "float: impossible" << std::endl;
        else
        {
		    std::cout << "float: " << f << "f" << std::endl;
        }
    }
    catch (const std::out_of_range&)
    {
        std::cout << "float: impossible" << std::endl;
    }

    try
    {
        d = static_cast<double>(std::atof(input.c_str()));
		if (d > std::numeric_limits<double>::max() || d < -std::numeric_limits<double>::max())
            std::cout << "double: impossible" << std::endl;
        else
		    std::cout << "double: " << d << std::endl;
    }
    catch (const std::out_of_range&)
    {
        std::cout << "double: impossible" << std::endl;
    }
}

void convertFloat(std::string input)
{
    char c;
    int i;
    float f;
    double d;

    try
    {
        long l = std::atol(input.c_str());
        if (l > std::numeric_limits<int>::max() || l < std::numeric_limits<int>::min())
        {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
        }
        else
        {
            i = static_cast<int>(std::atoi(input.c_str()));
            c = static_cast<char>(i);
            if (i >= 32 && i <= 126)
                std::cout << "char: '" << c << "'" << std::endl;
            else if (i < 0 || i > 255)
                std::cout << "char: non displayable" << std::endl;
            else
                std::cout << "char: impossible" << std::endl;
            i = std::atoi(input.c_str());
            std::cout << "int: " << i << std::endl;
        }
    }
    catch (const std::out_of_range&)
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
    }
    f = std::atof(input.c_str());
    std::cout << "float: " << f << "f" << std::endl;
    d = static_cast<double>(std::atof(input.c_str()));
    std::cout << "double: " << d << std::endl;
}

void convertDouble(std::string input)
{
    char c;
    int i;
    float f;
    double d;

    try
    {
        long l = std::atol(input.c_str());
        if (l > std::numeric_limits<int>::max() || l < std::numeric_limits<int>::min())
        {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
        }
        else
        {
            i = static_cast<int>(std::atoi(input.c_str()));
            c = static_cast<char>(i);
            if (i >= 32 && i <= 126)
                std::cout << "char: '" << c << "'" << std::endl;
            else if (i < 0 || i > 255)
                std::cout << "char: non displayable" << std::endl;
            else
                std::cout << "char: impossible" << std::endl;
            i = std::atoi(input.c_str());
            std::cout << "int: " << i << std::endl;
        }
    }
    catch (const std::out_of_range&)
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
    }
    f = static_cast<float>(std::atof(input.c_str()));
    if (f > std::numeric_limits<double>::max() || f < -std::numeric_limits<double>::max())
        std::cout << "float: impossible" << std::endl;
    else
        std::cout << "float: " << f << "f" << std::endl;
    d = std::atof(input.c_str());
    std::cout << "double: " << d << std::endl;
}

// detecting input data type
bool isNumber(const std::string input)
{
    size_t i = 0;

    if (input[0] == '-') {
        if (input.size() == 1 || !std::isdigit(input[1]))
            return (false);
        i++;
    }
    while (i < input.size())
    {
        if (!std::isdigit(input[i++]))
            return (false);
    }
    return (true);
}

bool isFloat(const std::string input)
{
    unsigned int i = 0;
    bool withDecimalPrt = false;

    if (input[0] == '-')
    {
        if (input.size() == 1 || !std::isdigit(input[1]))
            return (false);
        i++;
    }
    while (i < input.size())
    {
        if (i == input.size() - 1 && input[i] == 'f')
            break;
        if (input[i] == '.')
        {
            if (withDecimalPrt)
                return (false);
            withDecimalPrt = true;
        }
        else if (!std::isdigit(input[i]))
            return (false);
        i++;
    }
    if (!withDecimalPrt)
        return (false);
    float result = static_cast<float>(std::atof(input.c_str()));
    if (result > std::numeric_limits<float>::max() || result < -std::numeric_limits<float>::max())
        return (false);
    if (input[input.size() - 1] != 'f')
        return (false);
    return (true);
}

bool isDouble(const std::string input)
{
    unsigned int i = 0;
    bool withDecimalPrt = false;

    if (input[0] == '-')
    {
        if (input.size() == 1 || !std::isdigit(input[1]))
            return (false);
        i++;
    }
    while (i < input.size() - 1)
    {
        if (input[i] == '.')
        {
            if (withDecimalPrt)
                return (false);
            withDecimalPrt = true;
        }
        else if (!std::isdigit(input[i]))
            return (false);
        i++;
    }
    double result = static_cast<double>(std::atof(input.c_str()));
    if (result > std::numeric_limits<double>::max() || result < -std::numeric_limits<double>::max())
       return (false);
    return (true);
}

bool isChar(const std::string input)
{
    if (input.size() != 1)
        return (false);
    int i = std::atoi(input.c_str());
    if (i < 0 || i > 255)
        return (false);
    return (true);
}

void detectType(std::string input)
{
    if (isNumber(input))
        convertNumber(input);
    else if (isFloat(input))
        convertFloat(input);
    else if (isDouble(input))
        convertDouble(input);
    else if (isChar(input))
        convertChar(input);
    else
        printValue("impossible", "impossible", "impossible", "impossible");
}

// convert member function
void ScalarConverter::convert(std::string input)
{
	if (toupperStr(input) == "NAN" || toupperStr(input) == "NANF")
		printValue("impossible", "impossible", "nanf", "nan");
	else if (toupperStr(input) == "+INF" || toupperStr(input) == "+INFF")
		printValue("impossible", "impossible", "+inff", "+inf");
	else if (toupperStr(input) == "-INF" || toupperStr(input) == "-INFF")
		printValue("impossible", "impossible", "-inff", "-inf");
	else
        detectType(input);
}
