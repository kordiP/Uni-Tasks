#include <iostream>

class Animal {
public:
    virtual void speak() {
        std::cout << "Some generic animal sound\n";
    }
};

class Dog : public Animal {
public:
    void speak() override {
        std::cout << "Bau bau\n";
    }

    void sniff() {
        std::cout << "Sniffing\n";
    }
};

class Cat : public Animal {
public:
    void speak() override {
        std::cout << "Meow\n";
    }
};

int main() {
    Dog d;
    Cat c;

    Animal animals[2];
    animals[0] = d;
    animals[1] = c;

    for (int i = 0; i < 2; ++i) {
        animals[i].speak(); // Ще извика Animal::speak() за всеки обект
    }
}