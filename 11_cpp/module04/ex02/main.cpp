/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 09:51:10 by apayen            #+#    #+#             */
/*   Updated: 2023/11/07 09:30:24 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;//should not create a leak
	delete i;

	const Animal* k = new Dog();
	const Animal* l = new Cat();
	const Animal*	tab[] = {k, l};

	int	index;
	index = 0;
	while (index < 2)
	{
		std::cout << tab[index]->getType() << " will be deleted" << std::endl;
		delete tab[index];
		index++;
	}

	Cat*	c = new Cat();
	c->setIdea(0, "Idea 1");
	c->setIdea(1, "Idea 2");
	Cat*	d = new Cat();
	d->setIdea(0, "Bad thought 1");
	d->setIdea(1, "Bad thought 2");
	std::cout << "Original idea 0 of c: " << c->getIdea(0) << std::endl;
	std::cout << "Original idea 1 of c: " << c->getIdea(1) << std::endl;
	std::cout << d->getIdea(0) << std::endl;
	std::cout << d->getIdea(1) << std::endl;
	*c = *d;
	std::cout << "New idea 0 of c: " << c->getIdea(0) << std::endl;
	std::cout << "New idea 1 of c: " << c->getIdea(1) << std::endl;
	std::cout << d->getIdea(0) << std::endl;
	std::cout << d->getIdea(1) << std::endl;
	delete d;
	std::cout << "After delete idea 0 of c: " << c->getIdea(0) << std::endl;
	std::cout << "After delete idea 1 of c: " << c->getIdea(1) << std::endl;
	delete c;

	// const Animal* x = new Animal();

	return (0);
}
