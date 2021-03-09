#include <iostream>
using namespace std;

// Abstract Factory is a creational design pattern that lets you produce families of related objects without specifying their concrete classes.

/*Abstract Products => declare  interfaces for a set of distinct 
    but related products which make up a product family.  (AbstractProductA, AbstractProductB,...)*/
class AbstractProductA
{
private:
    /* data */
public:
    virtual ~AbstractProductA(){};
    virtual string UsefulFunctionA() = 0;
};
class ConcreteProductA1 : public AbstractProductA
{
private:
    /* data */
public:
    string UsefulFunctionA(){
        return "The result of the product A1.";
    }
};
class ConcreteProductA2 : public AbstractProductA
{
private:
    /* data */
public:
    string UsefulFunctionA(){
        return "The result of the product A2.";
    }
};

//Interface of another product
class AbstractProductB
{
private:
    /* data */
public:
    virtual ~AbstractProductB(){};
    virtual string UsefulFunctionB() = 0;
    virtual string AnotherUsefulFunctionB(AbstractProductA &collaborator) = 0;
};

class ConcreteProductB1 : public AbstractProductB
{
private:
    /* data */
public:
    string UsefulFunctionB(){
        return "The result of the product B1.";
    }
    string AnotherUsefulFunctionB(AbstractProductA &collaborator){
        return "The result of the product B1 with " + collaborator.UsefulFunctionA();
    }
};

class ConcreteProductB2 : public AbstractProductB
{
private:
    /* data */
public:
    string UsefulFunctionB(){
        return "The result of the product B2.";
    }
    string AnotherUsefulFunctionB(AbstractProductA &collaborator){
        return "The result of the product B2 with " + collaborator.UsefulFunctionA();
    }
};

class AbstractFactory
{
private:
    /* data */
public:
    virtual ~AbstractFactory(){};
    virtual AbstractProductA *CreateProductA() = 0;
    virtual AbstractProductB *CreateProductB() = 0;
};
class ConcreteFactory1 : public AbstractFactory
{
private:
    /* data */
public:
    AbstractProductA *CreateProductA(){
        return new ConcreteProductA1();
    }
    AbstractProductB *CreateProductB(){
        return new ConcreteProductB1();
    }
};

class ConcreteFactory2 : public AbstractFactory
{
private:
    /* data */
public:
    AbstractProductA *CreateProductA(){
        return new ConcreteProductA2();
    }
    AbstractProductB *CreateProductB(){
        return new ConcreteProductB2();
    }
};
void ClientCode(AbstractFactory &factory){
    AbstractProductA *product_a = factory.CreateProductA();
    AbstractProductB *product_b = factory.CreateProductB();
    cout << product_b->UsefulFunctionB();
    cout << product_b->AnotherUsefulFunctionB(*product_a);
    delete product_a;
    delete product_b;
}

int main(int argc, char const *argv[])
{
    cout << "Client: Testing client code with the first factory type:\n";
    ConcreteFactory1 *f1 = new ConcreteFactory1();
    ClientCode(*f1);
    delete f1;
    cout << endl;
    cout << "Client: Testing the same client code with the second factory type:\n";
    ConcreteFactory2 *f2 = new ConcreteFactory2();
    ClientCode(*f2);
    delete f2;
    return 0;
}