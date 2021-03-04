#include <iostream>
#include <list>
using namespace std;

class ISubcriber
{
public:
    virtual ~ISubcriber(){};
    virtual void Update(string &messages_from_publisher) = 0;
};

class IPublisher
{
public:
    virtual ~IPublisher(){};
    virtual void AddSubcriber(ISubcriber *subcriber) = 0;
    virtual void RemoveSubcriber(ISubcriber *subcriber) = 0;
    virtual void Notify() = 0;
};
class Publisher : IPublisher
{
private:
    string _message;
    list<ISubcriber*> ListSubcriber;
public:
    virtual ~Publisher() {
        std::cout << "Goodbye, I was the Publisher.\n";
    }
    void AddSubcriber(ISubcriber *subcriber){
        ListSubcriber.push_back(subcriber);
    }
    void RemoveSubcriber(ISubcriber *subcriber){
        ListSubcriber.remove(subcriber);
    }
    void Notify(){
        list<ISubcriber*>::iterator iterator = ListSubcriber.begin();
        while (iterator != ListSubcriber.end())
        {
            (*iterator)->Update(_message);
            iterator++;
        }
    }
    void CreateMessage(string message = "Empty"){
        this->_message = message;
        Notify();
    }
    void SomeBusinessLogic() {
        this->_message = "change message message";
        Notify();
        std::cout << "I'm about to do some thing important\n";
    }
};
class Subcriber : public ISubcriber
{
private:
    Publisher &mPublisher;
    string _messages_from_publisher;
    static int number_subcribers;
    int number_;
public:
    Subcriber(Publisher &publisher) : mPublisher(publisher){
        this->mPublisher.AddSubcriber(this);
        cout << "Hi. I'm the Subcriber " << ++Subcriber::number_subcribers << endl;
        this->number_ = Subcriber::number_subcribers;
    };
    virtual ~Subcriber(){
        std::cout << "Goodbye, I was the Observer \"" << this->number_ << "\".\n";
    };
    void Update(string &messages_from_publisher){
        _messages_from_publisher = messages_from_publisher;
        PrintInfo();
    }
    void PrintInfo(){
        cout << "This is message from Subcriber \"" << this->number_ << "\" " << this->_messages_from_publisher << endl;
    }
    void RemoveMeFromTheList(){
        mPublisher.RemoveSubcriber(this);
        cout << "Subcriber \"" << number_ << "\" removed from the list \n";
    }


};
int Subcriber::number_subcribers = 0;
int main(int argc, char const *argv[])
{
    Publisher* publisher = new Publisher();
    Subcriber* subcriber1 = new Subcriber(*publisher);
    Subcriber* subcriber2 = new Subcriber(*publisher);
    Subcriber* subcriber3;
    Subcriber* subcriber4;
    subcriber1->RemoveMeFromTheList();
    publisher->CreateMessage("Helloworld");
    subcriber2->RemoveMeFromTheList();
    delete subcriber1;
    delete subcriber2;
    publisher->SomeBusinessLogic();
    subcriber3 = new Subcriber(*publisher);
    subcriber4 = new Subcriber(*publisher);
    publisher->CreateMessage("Helloworld again");
    delete subcriber3;
    delete subcriber4;
    return 0;
}


