#pragma once
#include<vector>
#include<utility>
#include"Cow.h"
using namespace std;
enum ProduceStatus{
    FULL,HALF,ZERO
};
class Farm
{
    public:
    int n;
    double milk;
    vector<pair<Cow,int>> cows;
    vector<ProduceStatus> ps;
    
    Farm(int n):n(n),milk(0.0){}
    void addCow(Cow cow)
    {
        cows.push_back({cow,0});
        ps.push_back(ZERO);
    }
    void supply(string name, int a)
    {
        for(auto&it:cows){
            if(it.first.name == name){
                it.second +=a;
            }
        }
    }
    
    void startMeal()
    {
        for(int i=0;i<cows.size();i++){
            if(cows[i].second>=cows[i].first.u){
                cows[i].second-=cows[i].first.u;
                ps[i]=FULL;
            }else if(cows[i].second>=cows[i].first.l){
                cows[i].second=0;
                ps[i]=FULL;
            }else if(cows[i].second>0){
                cows[i].second=0;
                ps[i]=HALF;
            }else{
                cows[i].second=0;
                ps[i]=ZERO;
            }
        }
    }
    void produceMilk()
    {
        double sum = 0;
        for(int i=0;i<cows.size();i++){
            if(ps[i]==FULL){
                sum+=(double)cows[i].first.m;
            }else if(ps[i]==HALF){
                sum+=(double)cows[i].first.m/2.f;
            }else{
                ;
            }
        }
        milk += sum;
    }
    double getMilkProduction(){
        return milk;
    }
};