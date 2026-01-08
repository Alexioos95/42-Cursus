/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 09:55:18 by apayen            #+#    #+#             */
/*   Updated: 2023/11/20 10:30:57 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void)
{
	int		i;
	Base	*b;

	i = rand();
	if (i % 3 == 0)
		b = new A;
	else if (i % 3 == 1)
		b = new B;
	else
		b = new C;
	return (b);
}

void identify(Base* p)
{
	A	*a;
	B	*b;
	C	*c;

	a = dynamic_cast<A *>(p);
	if (a != NULL)
	{
		std::cout << "Object pointed is of type A" << std::endl;
		return ;
	}
	b = dynamic_cast<B *>(p);
	if (b != NULL)
	{
		std::cout << "Object pointed is of type B" << std::endl;
		return ;
	}
	c = dynamic_cast<C *>(p);
	if (c != NULL)
	{
		std::cout << "Object pointed is of type C" << std::endl;
		return ;
	}
	std::cout << "Error: Couldn't determine the type of the object" << std::endl;
}

void identify(Base& p)
{
	try
	{
		A	&a = dynamic_cast<A &>(p);
		std::cout << "Object referenced is of type A" << std::endl;
		static_cast<void>(a);
		return ;
	}
	catch(std::exception	&e) {}
	try
	{
		B	&b = dynamic_cast<B &>(p);
		std::cout << "Object referenced is of type B" << std::endl;
		static_cast<void>(b);
			return ;
	}
	catch(std::exception	&e) {}
	try
	{
		C	&c = dynamic_cast<C &>(p);
		std::cout << "Object referenced is of type C" << std::endl;
		static_cast<void>(c);
		return ;
	}
	catch(std::exception	&e) {}
	std::cout << "Error: Couldn't determine the type of the object" << std::endl;
}

int	main(void)
{
	std::cout << "** Identify per pointer Test **" << std::endl;
	Base	*a1 = new A;
	std::cout << "Give a type A" << std::endl;
	identify(a1);
	Base	*b1 = new B;
	std::cout << "Give a type B" << std::endl;
	identify(b1);
	Base	*c1 = new C;
	std::cout << "Give a type C" << std::endl;
	identify(c1);
	std::cout << std::endl;

	std::cout << "** Identify per reference Test **" << std::endl;
	Base	&a2 = *a1;
	std::cout << "Give a type A" << std::endl;
	identify(a2);
	Base	&b2 = *b1;
	std::cout << "Give a type B" << std::endl;
	identify(b2);
	Base	&c2 = *c1;
	std::cout << "Give a type C" << std::endl;
	identify(c2);
	delete a1;
	delete b1;
	delete c1;
	std::cout << std::endl;

	std::cout << "** Identify Random Test **" << std::endl;
	Base	*r1 = generate();
	identify(r1);
	Base	*r2 = generate();
	identify(r2);
	Base	*r3	 = generate();
	identify(r3);
	Base	*r4 = generate();
	identify(r4);
	delete r1;
	delete r2;
	delete r3;
	delete r4;
}
