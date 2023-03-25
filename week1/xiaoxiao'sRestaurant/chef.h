#pragma once
#include <string>
class Chef {
private:
    std::string name, signatureDish;
public:
    Chef(std::string _name, std::string _signatureDish);
    bool isSignatureDish(std::string dish);
    void cook(std::string dish);
};