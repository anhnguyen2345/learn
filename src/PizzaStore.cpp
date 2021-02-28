#include "inc/PizzaStore.h"

void PizzaStore::PizzaOrder(int type){
        Pizza *pizza;
        switch (type){
        case CHEESE:
                pizza = new CheesePizza();
            break;
        case GREEK:
                pizza = new CheesePizza();
            break;
        default: 
            break;
        }
        pizza->Prepare();
        pizza->Bake();
        pizza->Cut();
        pizza->Box();
    }