#include<iostream>

const double NUM1 = 17.5;
const double NUM2 = 4.0;

const double VARA = 20.0;
const double VARB = 30.0;

const bool BOOLX = true;
const bool BOOLY = false;

class functionProt{
    public:
        void displaySum(double num1, double num2);
        bool isGreaterthan(double varA, double varB);
        bool boolean(bool x, bool y);
};

int main(){
    functionProt func;

    func.displaySum(NUM1, NUM2);

    std::cout << "Is A greater than B? "
              << (func.isGreaterthan(VARA, VARB) ? "Yes" : "No")
              << std::endl;

    func.boolean(BOOLX, BOOLY);

    return 0;
}

void functionProt::displaySum(double num1, double num2){
    std::cout << "Sum: " << (num1 + num2) << std::endl;
}

bool functionProt::isGreaterthan(double varA, double varB){
    return varA > varB;
}

bool functionProt::boolean(bool x, bool y){
    std::cout << std::boolalpha;
    std::cout << "AND: " << (x && y) << " | OR: " << (x || y) << " | NOT X: " << (!x) << " | NOT Y: " << (!y) << std::endl;
    return true;
}