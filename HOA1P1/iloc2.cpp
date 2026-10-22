#include <iostream>

class Converter {
public:
    double getFahrenheit(double celsius);
};

int main() {
    Converter con;

    double kelvin = 270.1;

    double celsius = kelvin - 273.15;
    double fahrenheit = con.getFahrenheit(celsius);

    std::cout << "Kelvin to Fahrenheight: " << std::endl;
    std::cout << "    " << "Kelvin: " << kelvin << std::endl;
    std::cout << "    " << "Fahrenheit: " << fahrenheit << std::endl;

    return 0;
}

double Converter::getFahrenheit(double celsius) {
    return (celsius * 1.8) + 32;
}