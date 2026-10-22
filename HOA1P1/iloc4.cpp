#include <iostream>
#include <cmath>

class Triangle {
    private:
        double totalAngle, angleA, angleB, angleC;
        double num1, num2, num3;
    public:
        Triangle(double A, double B, double C, double n1, double n2, double n3);
        double area();
        double peri();
        void type();
};

int main() {
    Triangle tria(40, 30, 110, 7, 5, 10);

    std::cout << ">>> TRIANGLE RESULTS <<<" << std::endl;
    std::cout << "    " << "Perimeter: " << tria.peri() << std::endl;
    std::cout << "    " << "Area: " << tria.area() << std::endl;
    tria.type();

    return 0;
}

Triangle::Triangle(double A, double B, double C, double n1, double n2, double n3) {
    angleA = A; angleB = B; angleC = C;
    num1 = n1; num2 = n2; num3 = n3;
}

double Triangle::peri() {
    return num1 + num2 + num3;
}

double Triangle::area() {
    double s = (num1 + num2 + num3) / 2.0;
    return std::sqrt(s * (s - num1) * (s - num2) * (s - num3));
}

void Triangle::type() {
    std::cout << "    " << "Type: ";
    if (angleA > 90 || angleB > 90 || angleC > 90) std::cout << "Obtuse\n";
    else if (angleA < 90 && angleB < 90 && angleC < 90) std::cout << "Acute\n";
    else std::cout << "Others\n";
}