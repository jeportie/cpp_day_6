/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 13:10:32 by jeportie          #+#    #+#             */
/*   Updated: 2025/05/05 15:36:43 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <limits>
#include <cmath>
#include <cctype>

ScalarConverter::ScalarConverter(void) {}

ScalarConverter::ScalarConverter(const ScalarConverter& src) { *this = src; }

ScalarConverter::~ScalarConverter(void) { return; }

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& rhs)
{
    (void) rhs;
    return (*this);
}

bool ScalarConverter::isCharLiteral(std::string const& str)
{
    if (str.size() == 1 && std::isprint(str[0]) && !std::isdigit(str[0]))
        return (true);
    else
        return (false);
}

bool ScalarConverter::isIntLiteral(std::string const& str)
{
    if (str.empty())
        return false;

    std::istringstream ss(str);
    int                value;
    return (ss >> value) && ss.eof();
}

bool ScalarConverter::isFloatLiteral(std::string const& str)
{
    if (str == "nanf" || str == "+inff" || str == "-inff")
        return true;

    if (str.size() < 2)
        return false;

    if (str[str.size() - 1] != 'f')
        return false;

    std::string        core = str.substr(0, str.size() - 1);
    std::istringstream ss(core);
    float              value;
    return (ss >> value) && ss.eof();
}

bool ScalarConverter::isDoubleLiteral(std::string const& str)
{
    if (str == "nan" || str == "+inf" || str == "-inf")
        return true;

    std::istringstream ss(str);
    double             value;
    return (ss >> value) && ss.eof();
}

void ScalarConverter::fromChar(char c)
{
    std::cout << "char: '" << c << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;

    float f = static_cast<float>(c);
    std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;

    double d = static_cast<double>(c);
    std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
}

void ScalarConverter::fromInt(int i)
{
    if (i >= 0 && i <= 127 && std::isprint(i))
        std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
    else if (i >= 0 && i <= 127)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: impossible" << std::endl;

    std::cout << "int: " << i << std::endl;

    float f = static_cast<float>(i);
    std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;

    double d = static_cast<double>(i);
    std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
}

void ScalarConverter::fromFloat(float f)
{
    if (std::isnan(f) || std::isinf(f))
        std::cout << "char: impossible" << std::endl;
    else if (f >= 0 && f <= 127 && std::isprint(static_cast<int>(f)))
        std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
    else if (f >= 0 && f <= 127)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: impossible" << std::endl;

    if (std::isnan(f) || std::isinf(f) || f < std::numeric_limits<int>::min()
        || f > std::numeric_limits<int>::max())
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(f) << std::endl;

    std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;

    double d = static_cast<double>(f);
    std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
}

void ScalarConverter::fromDouble(double d)
{
    if (std::isnan(d) || std::isinf(d))
        std::cout << "char: impossible" << std::endl;
    else if (d >= 0 && d <= 127 && std::isprint(static_cast<int>(d)))
        std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
    else if (d >= 0 && d <= 127)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: impossible" << std::endl;

    if (std::isnan(d) || std::isinf(d) || d < std::numeric_limits<int>::min()
        || d > std::numeric_limits<int>::max())
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(d) << std::endl;

    float f = static_cast<float>(d);
    if (std::isnan(f))
        std::cout << "float: nanf" << std::endl;
    else if (std::isinf(f))
        std::cout << "float: " << (f < 0 ? "-inff" : "+inff") << std::endl;
    else
        std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;

    if (std::isnan(d))
        std::cout << "double: nan" << std::endl;
    else if (std::isinf(d))
        std::cout << "double: " << (d < 0 ? "-inf" : "+inf") << std::endl;
    else
        std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
}

LiteralType ScalarConverter::determineLiteralType(const std::string& literal)
{
    if (isCharLiteral(literal))
        return CHAR;
    if (isIntLiteral(literal))
        return INT;
    if (isFloatLiteral(literal))
        return FLOAT;
    if (isDoubleLiteral(literal))
        return DOUBLE;
    return INVALID;
}

void ScalarConverter::convert(std::string const& literal)
{
    switch (determineLiteralType(literal))
    {
        case CHAR:
            fromChar(literal[0]);
            break;
        case INT:
        {
            std::istringstream ss(literal);
            int                i;
            ss >> i;
            fromInt(i);
            break;
        }
        case FLOAT:
        {
            bool pseudo = (literal == "nanf" || literal == "+inff" || literal == "-inff");
            if (pseudo)
            {
                std::string core = literal.substr(0, literal.size() - 1);
                std::cout << "char: impossible" << std::endl;
                std::cout << "int: impossible" << std::endl;
                std::cout << "float: " << core << "f" << std::endl;
                std::cout << "double: " << core << std::endl;
            }
            else
            {
                std::string        core = literal.substr(0, literal.size() - 1);
                std::istringstream ss(core);
                float              f;
                ss >> f;
                fromFloat(f);
            }
            break;
        }
        case DOUBLE:
        {
            bool pseudo = (literal == "nan" || literal == "+inf" || literal == "-inf");
            if (pseudo)
            {
                std::cout << "char: impossible" << std::endl;
                std::cout << "int: impossible" << std::endl;
                std::cout << "float: " << literal << "f" << std::endl;
                std::cout << "double: " << literal << std::endl;
            }
            else
            {
                std::istringstream ss(literal);
                double             d;
                ss >> d;
                fromDouble(d);
            }
            break;
        }
        case INVALID:
        default:
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: impossible" << std::endl;
            std::cout << "double: impossible" << std::endl;
            break;
    }
}
