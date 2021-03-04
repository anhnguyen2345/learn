#include <iostream>
#include <vector>
#include <algorithm>    // std::for_each

using namespace std;

class Strategy
{
public:
    virtual ~Strategy(){};
    virtual string DoAlgorithm(const vector<string> &data) = 0;
};
class Context
{
private:
    Strategy* _strategy;
public:
    Context(Strategy* strategy) : _strategy(strategy){};
    ~Context(){
        delete this->_strategy;
    };
    void setStrategy(Strategy* strategy){
        delete this->_strategy;
        this-> _strategy = strategy;
    }
    void DoSomeBusinessLogic(){
        cout << "Context: Sorting data using the strategy (not sure how it'll do it)\n";
        string result = this->_strategy->DoAlgorithm(vector<std::string> {"a", "e", "c", "b", "d"});
        cout << result << "\n";
    }
};
class ConcreteStrategyA : public Strategy
{
public:
    string DoAlgorithm(const vector<string> &data){
        string result;
        std::for_each(std::begin(data), std::end(data), [&result](const std::string &letter) {
            result += letter;
        });
        std::sort(std::begin(result), std::end(result));
        return result;
    }
};

class ConcreteStrategyB : public Strategy
{
    string DoAlgorithm(const vector<string> &data)
    {
        std::string result;
        std::for_each(std::begin(data), std::end(data), [&result](const std::string &letter) {
            result += letter;
        });
        std::sort(std::begin(result), std::end(result));
        for (int i = 0; i < result.size() / 2; i++)
        {
            std::swap(result[i], result[result.size() - i - 1]);
        }

        return result;
    }
};

void codeClient(){
    Context* context = new Context(new ConcreteStrategyA);
    std::cout << "Client: Strategy is set to normal sorting.\n";
    context->DoSomeBusinessLogic();
    std::cout << "\n";
    std::cout << "Client: Strategy is set to reverse sorting.\n";
    context->setStrategy(new ConcreteStrategyB);
    context->DoSomeBusinessLogic();
    delete context;
}
int main(int argc, char const *argv[])
{
    codeClient();
    return 0;
}
