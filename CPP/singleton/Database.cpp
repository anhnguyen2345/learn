// #include <iostream>                                                 
// using namespace std;

// class Database
// {
// private:
//     int mRecord;
//     string mName;
// public:
//     Database(string name){
//         mRecord = 0;
//         mName = name;
//     };
//     ~Database();
//     void editRecord(string operation)
//     {
//         cout << "Performing a " << operation <<
//                 "operation on record " << mRecord <<
//                 " in database " << mName << endl;
//     }
 
//     string getName()
//     {
//         return mName;
//     }
// };

// int main(int argc, char const *argv[])
// {
//     Database* db_one = new Database("one");
//     cout << db_one->getName() << endl;
//     Database* db_two = new Database("two");
//     cout << db_two->getName() << endl;
//     return 0;
// }
#pragma region 
// #include <string>                                         
// #include <iostream>      

// using namespace std;

// class Database
// {
// private:
//     int mRecord;
//     string mName;
//     static Database* UniqueInstance;
//     Database(string name){
//         mRecord = 0;
//         mName = name;
//     };
// public:

//     ~Database();
//     void editRecord(string operation)
//     {
//         cout << "Performing a " << operation <<
//                 "operation on record " << mRecord <<
//                 " in database " << mName << endl;
//     }
 
//     string getName()
//     {
//         return mName;
//     }
//     static Database* GetInstance(string name){
//         if (nullptr == UniqueInstance)
//         {
//             UniqueInstance = new Database(name);
//         }
//         return UniqueInstance;
//     }
// };
// Database* Database::UniqueInstance = nullptr;

// int main(int argc, char const *argv[])
// {
//     Database* database;
//     database = Database::GetInstance("one");
//     cout << database->getName() << endl;
//     database = Database::GetInstance("two");
//     cout << database->getName() << endl;
//     return 0;
// }
#pragma endregion


#include <string>                                           
#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>
using namespace std;

class Database
{
private:
    int mRecord;
    string mName;
    static std::mutex mLocker;
    static Database* UniqueInstance;
    //to prevent other objects from using the new operator with the Singleton class.
    Database(string name){
        mRecord = 0;
        mName = name;
    };
public:

    ~Database();
    void editRecord(string operation)
    {
        cout << "Performing a " << operation <<
                "operation on record " << mRecord <<
                " in database " << mName << endl;
    }
 
    string getName()
    {
        return mName;
    }
    static Database* GetInstance(string name){
        if (nullptr == UniqueInstance){
            std::lock_guard<std::mutex> lock(mLocker);
            if (nullptr == UniqueInstance)
            {
                UniqueInstance = new Database(name);
            }
        }
        return UniqueInstance;
    }
};
Database* Database::UniqueInstance{nullptr};
std::mutex Database::mLocker;

void ThreadFoo(){
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    Database* db_foo = Database::GetInstance("FOO");
    cout << db_foo->getName() << "\n";
}
void ThreadYaa(){
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    Database* db_yaa = Database::GetInstance("YAA");
    cout << db_yaa->getName() << "\n";
}
int main(int argc, char const *argv[])
{
    // Database* database;
    // database = Database::GetInstance("one");
    // cout << database->getName() << endl;
    // database = Database::GetInstance("two");
    // cout << database->getName() << endl;
    thread t1(ThreadFoo);
    thread t2(ThreadYaa);
    t1.join();
    t2.join();
    return 0;
}