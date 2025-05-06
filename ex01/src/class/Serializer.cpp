/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 20:55:27 by jeportie          #+#    #+#             */
/*   Updated: 2025/05/06 21:57:25 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ostream>
#include <stdint.h>
#include "Serializer.hpp"
#include "../../include/Data.hpp"

Serializer::Serializer(void)
{
    std::cout << "[Serializer] - default constructor called - " << std::endl;
}

Serializer::Serializer(const Serializer& src)
{
    std::cout << "[Serializer] - copy constructor called - " << std::endl;
    *this = src;
    return;
}

Serializer::~Serializer(void)
{
    std::cout << "[Serializer] - destructor called - " << std::endl;
    return;
}

Serializer& Serializer::operator=(const Serializer& rhs)
{
    std::cout << "[Serializer] - copy assignment operator called - " << std::endl;
	(void) rhs;
    return (*this);
}

uintptr_t Serializer::serialize(Data* ptr) { return (reinterpret_cast<uintptr_t>(ptr)); }

Data* Serializer::deserialize(uintptr_t raw) { return (reinterpret_cast<Data*>(raw)); }
