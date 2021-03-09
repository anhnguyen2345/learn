#include <iostream>
using namespace std;

/*Factory method is a creational design pattern that provides an interface for creating object in superclass, 
but allows subclass to alter type of objects which that will be created.*/ 

class Product
{
private:
    /* data */
public:
    virtual ~Product(){};
    virtual string DoStuff() = 0;
};

class ConcreteProductA : public Product
{
private:
    /* data */
public:
    string DoStuff(){
        return "This is a ProductA.";
    }
};

class ConcreteProductB : public Product
{
private:
    /* data */
public:
    string DoStuff(){
        return "This is a ProductB.";
    }
};

//Creator : superclass -> must have Factory Method (creatorProduct return type of objects)
class Creator
{
private:
    /* data */
public:
    ~Creator(){};
    virtual Product* creatorProduct() = 0; // Factorymethod
    string SomeOperation(){
        Product* product = this->creatorProduct(); //currency instance (Ex: ConcreteCreatorA->creatorProduct()) create concrete product
        string result = "Creator: don't know requires but " + product->DoStuff(); 
        delete product;
        return result;
    }
};
class ConcreteCreatorA : public Creator
{
private:
    /* data */
public:
    Product* creatorProduct(){
        return new ConcreteProductA();
    }
};

class ConcreteCreatorB : public Creator
{
private:
    /* data */
public:
    Product* creatorProduct(){
        return new ConcreteProductB();
    }
};

void ClientCode(Creator &creator){
    cout << "Client: " + creator.SomeOperation(); //SomeOperation() run FactoryMethod (creatorProduct) and do somethings
}

int main(int argc, char const *argv[])
{
    Creator* productA = new ConcreteCreatorA();
    ClientCode(*productA);
    delete productA;
    cout << endl;
    Creator* productB = new ConcreteCreatorB();
    ClientCode(*productB);
    delete productB;
    return 0;
}
