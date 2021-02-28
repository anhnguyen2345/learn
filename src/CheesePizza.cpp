#include "inc/CheesePizza.h"
CheesePizza::CheesePizza(){
        name = "Cheese";
        dough = "Thin dough";
        sauce = "Chilli sauce";
        toppings.push_back("Tomato");
        toppings.push_back("Potato");    
};
void CheesePizza::Box(){
        cout << "Box Cheese Inheritance\n";
}