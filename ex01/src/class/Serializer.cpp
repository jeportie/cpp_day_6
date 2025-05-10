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

#include <stdint.h>
#include "Serializer.hpp"
#include "../../include/Data.hpp"

Serializer::Serializer(void) {}

Serializer::Serializer(const Serializer& src) { *this = src; }

Serializer::~Serializer(void) {}

Serializer& Serializer::operator=(const Serializer& rhs)
{
    (void) rhs;
    return (*this);
}

uintptr_t Serializer::serialize(Data* ptr) { return (reinterpret_cast<uintptr_t>(ptr)); }

Data* Serializer::deserialize(uintptr_t raw) { return (reinterpret_cast<Data*>(raw)); }
