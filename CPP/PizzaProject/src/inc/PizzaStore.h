#include <iostream>
#include "CheesePizza.h"
#include "GreekPizza.h"
#include <string.h>
using namespace std;

enum {
    CHEESE = 0,
    GREEK,
};

class PizzaStore
{
private:
    /* data */
public:
    void PizzaOrder(int type);
};

