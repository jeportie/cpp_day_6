/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 13:08:42 by jeportie          #+#    #+#             */
/*   Updated: 2025/05/06 08:04:57 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

enum LiteralType
{
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    INVALID
};

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

    static void caseChar(char c);
    static void caseInt(int i);
    static void caseFloat(float f);
    static void caseDouble(double d);


	static LiteralType determineLiteralType(const std::string& literal);
};
#endif  // ********************************************** SCALARCONVERTER_HPP //
