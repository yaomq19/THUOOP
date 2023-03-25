#include"manager.h"
using namespace std;
void Manager::newChef(Chef chef)
{
    chefs.push_back(chef);
}
void Manager::order(string dish)
{
    bool isfind = false;
    for(int i=0;i<chefs.size();i++)
    {
        if(chefs[i].isSignatureDish(dish)){
            isfind = true;
            chefs[i].cook(dish);
            break;
        }
    }
    if(!isfind){
        chefs[0].cook(dish);
    }
}
void Manager::order(string dish, int chefId)
{
    chefs[chefId].cook(dish);
}