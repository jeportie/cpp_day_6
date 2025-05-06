/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverterCheckers.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 08:02:33 by jeportie          #+#    #+#             */
/*   Updated: 2025/05/06 08:14:07 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <sstream>
#include <iostream>
#include <cmath>
#include <cctype>

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
