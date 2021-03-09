#include <iostream>
using namespace std;

/*Factory method is a creational design pattern that provides an interface for creating object in superclass, 
but allows subclass to alter type of objects which that will be created.*/ 
class Transportlogistics
{
private:
    /* data */
public:
    virtual ~Transportlogistics(){};
    virtual string doStuff() = 0;
};

class RoadLogistic : public Transportlogistics
{
private:
    /* data */
public:
    string doStuff(){
        return "This is RoadLogistics\n";
    }
};

class SeaLogistic : public Transportlogistics
{
private:
    /* data */
public:
    string doStuff(){
        return "This is SeaLogistics\n";
    }
};

class Creator
{
private:
    /* data */
public:
    virtual ~Creator(){};
    virtual Transportlogistics* FactoryMethod() = 0;
    string SomeOperation(){
        Transportlogistics* transport = this->FactoryMethod();
        string result = "Creator: " + transport->doStuff();
        delete transport;
        return result;
    }
};
class CreatorRoad : public Creator
{
private:
    /* data */
public:
    Transportlogistics* FactoryMethod(){
        return new RoadLogistic();
    }
};
class CreatorSea : public Creator
{
private:
    /* data */
public:
    Transportlogistics* FactoryMethod(){
        return new SeaLogistic();
    }
};

void ClientCode(Creator &creator){
    cout << "Client: " << creator.SomeOperation() << endl;
}

int main(int argc, char const *argv[])
{
    cout << "Create a RoadLogistics\n";
    Creator* truck = new CreatorRoad();
    ClientCode(*truck);
    delete truck;
    return 0;
}
