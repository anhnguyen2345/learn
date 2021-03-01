#include "inc/Pizza.h"
void Pizza::Prepare(){
        cout << "Preparing the " + name + " pizza" <<endl;
        cout << "Preparing the " + dough <<endl;
        cout << "Preparing the " + sauce <<endl;
        cout << "Preparing the ";
        for (int  index = 0; index < (int)toppings.size(); index++)
        {
            cout << toppings[index] + ", ";
        }
        cout << endl;
    }
void Pizza::Bake(){
        cout <<"Baking the pizza in 30mins" <<endl;
    }
void Pizza::Cut(){
        cout <<"Cutting the pizza" <<endl;
    }
void Pizza::Box(){
        cout <<"Boxxing the pizza" <<endl;
    }