#include "inc/Pizza.h"
#include "inc/CheesePizza.h"
#include "inc/GreekPizza.h"
#include "inc/PizzaStore.h"

int main(){
    PizzaStore *newpizza = new PizzaStore();
    newpizza->PizzaOrder(CHEESE);
    newpizza->PizzaOrder(GREEK);
    return 0;
}