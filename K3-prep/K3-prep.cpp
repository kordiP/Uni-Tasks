#include <iostream>

class Button
{
private:
    int id;
public:
    virtual void render() const = 0;
};

class Window : public Button
{
public:
    void render() const override
    {
        std::cout << "Render mi window";
    }
};

class HTML : public Button
{
public:
    void render() const override
    {
        std::cout << "HTML";
    }
};

class Dialog : public Button
{
public:
    void render() const override
    {
        std::cout << "bolin";
    }
    Button& createProduct();
};

int main()
{
    
}
