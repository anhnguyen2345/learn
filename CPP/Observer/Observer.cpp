#include <iostream>
#include <list>
using namespace std;

class IObserver
{
public:
    virtual ~IObserver(){};
    virtual void update(string operation, string record) = 0;
};
class ISubject
{
private:
    /* data */
public:
    virtual ~ISubject(){};
    virtual void AddObserver(IObserver* obs) = 0;
    virtual void removeObserver(IObserver* obs) = 0;
    virtual void Notify() = 0;
};

class Database : public ISubject
{
private:
    string mOperation;
    string mRecord;
    list<IObserver*> mObservers;
public:
    virtual ~Database(){};
    void AddObserver(IObserver* obs){
        mObservers.push_back(obs);
    }
    void removeObserver(IObserver* obs){
        mObservers.remove(obs);
    }
    void Notify(){
        HowManyObserver();
        for (auto& obs : mObservers) {
            obs->update(mOperation, mRecord);
        }
    }
    void editRecord(string operation, string record) {
        mOperation = operation;
        mRecord = record;
        Notify();
    }
    void HowManyObserver() {
    std::cout << "There are " << mObservers.size() << " observers in the list.\n";
  }
};
class Client : public IObserver
{
public:
    Client() {}
 
    void update(string operation, string record) {
        cout << "Client: " << operation << " opeation was performed on " << record << endl;
    }
};
 
class Developer : public IObserver
{
public:
    Developer() {}
 
    void update(string operation, string record) {
        cout << "Developer: " << operation << " opeation was performed on " << record << endl;
    }
};
 
class Boss : public IObserver
{
public:
    Boss() {}
 
    void update(string operation, string record) {
        cout << "Boss: " << operation << " opeation was performed on " << record << endl;
    }
};

int main()
{    
    Database database;
    Developer dev;
    Client client;
    Boss boss;
    database.AddObserver(&dev);
    database.AddObserver(&client);
    database.AddObserver(&boss);
    database.editRecord("delete", "record1");
    database.removeObserver(&client);
    database.editRecord("delete", "record2");
    return 0;
}
