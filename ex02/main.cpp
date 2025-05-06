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

int main() {
    Data data = {1, "Test", 3.14f};

    uintptr_t raw = Serializer::serialize(&data);
    Data* deserializedData = Serializer::deserialize(raw);

    if (deserializedData == &data) {
        std::cout << "Serialization and deserialization successful!" << std::endl;
    } else {
        std::cout << "Serialization and deserialization failed!" << std::endl;
    }

    return 0;
}
