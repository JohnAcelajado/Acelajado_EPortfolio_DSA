#include <iostream>
#include <cmath>

class MyClass {
public:
    int getDist(int x1, int y1, int x2, int y2);
};

int main() {
    MyClass obj;

    int x1 = 3, y1 = 4;
    int x2 = 7, y2 = 7;

    int ans = obj.getDist(x1, y1, x2, y2);

    std::cout << "Total Distance:" << std::endl;
    std::cout << "    " << "Distance: " << ans << std::endl;

    return 0;
}

int MyClass::getDist(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    return std::sqrt((dx * dx) + (dy * dy));
}