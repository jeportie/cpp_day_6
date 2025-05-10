/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 12:50:20 by jeportie          #+#    #+#             */
/*   Updated: 2025/05/10 20:06:16 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/class/Base.hpp"
#include "src/class/A.hpp"
#include "src/class/B.hpp"
#include "src/class/C.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

Base* generate(void)
{
    int r = double(rand()) / (RAND_MAX + 1.0) * (31);

    if (r < 11)
    {
        A* a = new A;
        return (static_cast<Base*>(a));
    }
    if (r > 10 && r < 21)
    {
        B* b = new B;
        return (static_cast<Base*>(b));
    }
    if (r > 20 && r < 31)
    {
        C* c = new C;
        return (static_cast<Base*>(c));
    }
    std::cout << "ERROR!" << std::endl;
    return (NULL);
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
}

void identify(Base& p)
{
    if (dynamic_cast<A*>(&p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(&p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(&p))
        std::cout << "C" << std::endl;
}

int main()
{
    std::srand(std::time(NULL));

    for (int i = 0; i < 10; ++i)
    {
        Base* obj = generate();
        std::cout << "Test " << i + 1 << ": " << std::endl;
        std::cout << "Id by pointer" << std::endl;
        identify(obj);
        std::cout << "Id by ref" << std::endl;
        identify(*obj);
        delete obj;
        std::cout << "------" << std::endl;
    }

    return 0;
}
