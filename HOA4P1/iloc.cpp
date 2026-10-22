#include <iostream>
#include <string>

#define MAX 100

class ArrayStack {
private:
    char arr[MAX];
    int top;

public:
    ArrayStack() : top(-1) {}

    void push(char c) {
        if (top >= MAX - 1) {
            std::cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = c;
    }

    char pop() {
        if (top < 0) {
            return '\0'; // Stack Underflow
        }
        return arr[top--];
    }

    bool isEmpty() {
        return top < 0;
    }
};

bool isBalanced(const std::string &expr) {
    ArrayStack stack;
    for (char c : expr) {
        if (c == '(' || c == '{' || c == '[') {
            stack.push(c);
        } else if (c == ')' || c == '}' || c == ']') {
            if (stack.isEmpty()) return false;
            char topChar = stack.pop();
            if ((c == ')' && topChar != '(') ||
                (c == '}' && topChar != '{') ||
                (c == ']' && topChar != '[')) {
                return false;
            }
        }
    }
    return stack.isEmpty();
}

int main() {
    std::string expressions[] = {
        "(A+B)+(C-D)",
        "((A+B)+(C-D)",
        "((A+B)+[C-D])",
        "((A+B)+[C-D]}"
    };

    for (const auto &expr : expressions) {
        std::cout << expr << " is "
                  << (isBalanced(expr) ? "Valid" : "Invalid")
                  << std::endl;
    }

    return 0;
}