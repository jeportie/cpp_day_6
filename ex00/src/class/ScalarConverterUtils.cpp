/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverterUtils.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 07:57:22 by jeportie          #+#    #+#             */
/*   Updated: 2025/05/06 07:59:49 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iomanip>
#include <limits>
#include <iostream>
#include <cmath>
#include <cctype>

void ScalarConverter::caseChar(char c)
{
    std::cout << "char: '" << c << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;

    float f = static_cast<float>(c);
    std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;

    double d = static_cast<double>(c);
    std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
}

void ScalarConverter::caseInt(int i)
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

void ScalarConverter::caseFloat(float f)
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

void ScalarConverter::caseDouble(double d)
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
