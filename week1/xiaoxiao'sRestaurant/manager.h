#pragma once
#include"chef.h"
#include<vector>
using namespace std;
class Manager
{
    vector<Chef> chefs;
public:
    void newChef(Chef chef);
    void order(string dish);
    void order(string dish, int chefId);
};