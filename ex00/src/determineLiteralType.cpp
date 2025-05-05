/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   determineLiteralType.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 15:31:54 by jeportie          #+#    #+#             */
/*   Updated: 2025/05/05 15:32:58 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/LiteralType.hpp"
#include "class/ScalarConverter.hpp"
#include <string>

LiteralType determineLiteralType(const std::string& literal)
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
