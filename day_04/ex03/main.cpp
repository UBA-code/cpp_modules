#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "ICharacter.hpp"
#include "MateriaSource.hpp"

void test1()
{    
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* me = new Character("me");

    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    me->unequip(1);

    ICharacter* bob = new Character("bob");

    me->use(0, *bob);
    me->use(1, *bob);

    delete bob;
    delete me;
    delete src;
    delete tmp;
}

void test2()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice);
	src->learnMateria(new Ice);
	src->learnMateria(new Cure);
	src->learnMateria(new Ice);
	Ice* ice = new Ice();
	src->learnMateria(ice);

	AMateria *tmp = src->createMateria("cure");
	Character *me = new Character("moi");
	Character *you = new Character("toi");
	me->equip(tmp);
	me->unequip(0);
	me->equip(src->createMateria("ice"));
	me->equip(NULL);

	me->use(0, *you);
	me->use(1, *you);
	me->use(3, *you);
	me->use(300, *you);
	delete src;
	delete me;
	delete tmp;
	delete you;
	delete ice;
}

int main()
{
    test1();
    // test2();
    system("leaks interface");
    return 0;
}
