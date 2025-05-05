/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 13:08:42 by jeportie          #+#    #+#             */
/*   Updated: 2025/05/05 15:35:28 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include "../../include/LiteralType.hpp"

class ScalarConverter
{
public:
    ~ScalarConverter(void);
    static void convert(const std::string& literal);

private:
    ScalarConverter(void);
    ScalarConverter(const ScalarConverter&);
    ScalarConverter& operator=(const ScalarConverter&);

    static bool isCharLiteral(const std::string& s);
    static bool isIntLiteral(const std::string& s);
    static bool isFloatLiteral(const std::string& s);
    static bool isDoubleLiteral(const std::string& s);

    static void fromChar(char c);
    static void fromInt(int i);
    static void fromFloat(float f);
    static void fromDouble(double d);


	static LiteralType determineLiteralType(const std::string& literal);
};
#endif  // ********************************************** SCALARCONVERTER_HPP //
