#include <iostream>

class A {
public:
	virtual void a() const
	{
		std::cout << "baseA" << "\n";
	}
};

class C {
public:
	virtual void c() const
	{
		std::cout << "baseC" << "\n";
	}
};

class B : public A, public C {
	void a() const override {
		std::cout << "bA" << "\n";
	}
	void c() const override {
		std::cout << "bC" << "\n";
	}
};

void m1(const A* aa)
{
	aa->a();
}
void m2(const C* ce)
{
	ce->c();
}

int main() {
	B b;

	m1(&b);
	m2(&b);
}