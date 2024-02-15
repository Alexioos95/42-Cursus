/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:05:36 by apayen            #+#    #+#             */
/*   Updated: 2023/11/07 13:58:24 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int main(void)
{
	// std::cout << "*** SUBJECT TEST ***" << std::endl;
	// IMateriaSource* src = new MateriaSource();
	// src->learnMateria(new Ice()); // LEAK!
	// src->learnMateria(new Cure()); // LEAK!

	// ICharacter* me = new Character("me");

	// AMateria* tmp;
	// tmp = src->createMateria("ice");
	// me->equip(tmp);
	// tmp = src->createMateria("cure");
	// me->equip(tmp);

	// ICharacter* bob = new Character("bob");

	// me->use(0, *bob);
	// me->use(1, *bob);

	// delete bob;
	// delete me;
	// delete src;
	// std::cout << std::endl;

	std::cout << "*** CURE/ICE TEST ***" << std::endl;
	ICharacter* dummy = new Character("name_dummy");
	AMateria	*ice = new Ice;
	ice->use(*dummy);
	AMateria	*cure = new Cure;
	cure->use(*dummy);
	AMateria	*newice = ice->clone();
	newice->use(*dummy);
	AMateria	*newcure = cure->clone();
	newcure->use(*dummy);
	std::cout << std::endl;

	std::cout << "*** CHARACTER TEST ***" << std::endl;
	dummy->equip(ice);
	dummy->equip(cure);
	dummy->equip(newice);
	dummy->equip(newcure);
	dummy->equip(ice); // Can't equip

	dummy->use(1, *dummy);
	dummy->unequip(1);
	dummy->use(1, *dummy); // Can't use

	delete dummy;
	// delete ice; // Beware, SEGFAULT!
	delete cure; // Was unequiped
	std::cout << std::endl;

	std::cout << "*** COPY CHARACTER TEST ***" << std::endl;
	Character	*char_one = new Character("One");
	Character	*char_two = new Character("Two");
	Ice	*icechar = new Ice;
	char_one->equip(icechar);
	char_one->use(0, *char_two);
	char_two->use(0, *char_one); // No Materia
	*char_two = *char_one;
	delete char_one;
	char_two->use(0, *char_two);
	std::cout << std::endl;

	std::cout << "*** MATERIASOURCE TEST ***" << std::endl;
	MateriaSource	*bag = new MateriaSource;
	AMateria		*search1 = bag->createMateria("ice"); // Not found
	std::cout << search1 << std::endl;
	Ice				*ice1 = new Ice;
	Ice				*ice2 = new Ice;
	Ice				*ice3 = new Ice;
	Cure			*cure1 = new Cure;
	bag->learnMateria(ice1);
	bag->learnMateria(ice2);
	bag->learnMateria(ice3);
	bag->learnMateria(cure1);
	bag->learnMateria(ice1); // Can't be learned
	AMateria		*search2 = bag->createMateria("ice");
	search2->use(*char_two);
	AMateria		*search3 = bag->createMateria("fire");
	std::cout << search3 << std::endl;

	delete char_two;
	delete bag;
	delete ice1;
	delete ice2;
	delete ice3;
	delete cure1;
	delete search1;
	delete search2;
	delete search3;
	return 0;
}
