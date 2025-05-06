/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 13:10:32 by jeportie          #+#    #+#             */
/*   Updated: 2025/05/06 08:11:53 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <sstream>
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

/*static void printScalar()*/

void ScalarConverter::convert(std::string const& literal)
{
    switch (determineLiteralType(literal))
    {
        case CHAR:
            caseChar(literal[0]);
            break;
        case INT:
        {
            std::istringstream ss(literal);
            int                i;
            ss >> i;
            caseInt(i);
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
                caseFloat(f);
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
                caseDouble(d);
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
