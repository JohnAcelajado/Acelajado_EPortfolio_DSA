#include<iostream>

int main(){
    double num1 = 7.8;
    double num2 = 9.1;

    std::cout << "Before Swapping: " << '\n' << "a:" << num1 << " " << "b:" << num2 << '\n' << std::endl;

    double temp = num1;
    num1 = num2;
    num2 = temp;

    std::cout << "After Swapping: " << '\n' << "a:" << num1 << " " << "b:" << num2 << '\n' << std::endl;

    return 0;
}