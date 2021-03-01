#ifndef __PIZZA_H__
#define __PIZZA_H__

#include <string.h>
#include <iostream>
#include <vector>
using namespace std;
class Pizza{
    private:
    protected:
        std::string name;
        std::string dough;
        std::string sauce;
        vector<std::string> toppings;
    public : 
        void Prepare();
        void Bake();
        void Cut();
        virtual void Box();
};
#endif // __PIZZA_H__