#pragma once

class Hero
{
private:
	int health;
	const int attack;
protected:
	virtual void takeDamage(int damage) = 0;
	void setHealth();
public:
	Hero(int hp, int att);
	virtual void attackHero(Hero* attacked) = 0;
	virtual void print() const = 0;
	virtual Hero* clone() = 0;
	int getHealth() const;
	int getAttck() const;
};