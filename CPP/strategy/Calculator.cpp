#include <iostream>
using namespace std;

class Istrategy
{
private:
    
public:
    virtual ~Istrategy() {}
    virtual int execute(int a, int b) = 0;
};

class AddStrategy : public Istrategy
{
public:
    int execute(int a, int b){
        return a + b;
    }
};
class SubStrategy : public Istrategy
{
public:
    int execute(int a, int b){
        return a - b;
    }
};

class Context
{
private:
    Istrategy *strategy_;
public:
    Context(Istrategy *strategy = nullptr) : strategy_(strategy){
    };
    ~Context(){
        delete this->strategy_;
    };
    void setStrategy(Istrategy *strategy){
        delete this->strategy_;
        this->strategy_ = strategy;
    }
    int excuteStrategy(int a, int b){
        this->strategy_->execute(a,b);
    }
};

int main(int argc, char const *argv[])
{
    Context* calculator = new Context(new AddStrategy);
    int value = calculator->excuteStrategy(3,5);
    cout << "Calculator : " <<  value << endl ;
    calculator->setStrategy(new SubStrategy);
    value = calculator->excuteStrategy(3,5);
    cout << "Calculator : " <<  value << endl ;
    delete calculator;
    return 0;
}
