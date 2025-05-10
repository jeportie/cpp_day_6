/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 12:50:20 by jeportie          #+#    #+#             */
/*   Updated: 2025/05/06 21:59:21 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "src/class/Serializer.hpp"
#include "include/Data.hpp"

int main()
{
    Data data = { 1, "Test", 3.14f };

    std::cout << std::endl;
    std::cout << "Data:" << std::endl;
    std::cout << "id: " << data.id << " | name: " << data.name << " | value: " << data.value
              << std::endl;
    std::cout << std::endl;

    std::cout << "Serialization ..." << std::endl;
    uintptr_t raw = Serializer::serialize(&data);
    std::cout << "raw: " << raw << std::endl;
    std::cout << std::endl;

    std::cout << "Deserialization ..." << std::endl;
    std::cout << "Deserialized data:" << std::endl;
    Data* deserializedData = Serializer::deserialize(raw);
    std::cout << "id: " << deserializedData->id << " | name: " << deserializedData->name
              << " | value: " << deserializedData->value << std::endl;
    std::cout << std::endl;

    if (deserializedData == &data)
	{
        std::cout << "Serialization and deserialization successful!" << std::endl;
	}
    else
	{
        std::cout << "Serialization and deserialization failed!" << std::endl;
	}
    std::cout << std::endl;
    return 0;
}
