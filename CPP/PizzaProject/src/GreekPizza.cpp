#include "inc/GreekPizza.h"
GreekPizza::GreekPizza(){
        name = "Greek";
        dough = "Verry  thin dough";
        sauce = "Very spicy sauce";
        toppings.push_back("Black olives");
        toppings.push_back("Cheese");    
};
void GreekPizza::Box(){
        cout << "Boxxing GreekPizza\n" << endl;
}