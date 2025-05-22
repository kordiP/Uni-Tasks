#pragma once
#include "Hero.h"

class Knight : public Hero
{
private:
	int armor;
public:
	void attackHero(Hero* hero) override;
	void print() override;
	Hero* clone() override;
};