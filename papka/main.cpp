#include <iostream>
#include "lib/everything.h"

using namespace calculator;

int main() {

    Stack<int> stack1;
    stack1.push(6);
    Stack<int> stack2;
    stack2.push(6);
    std::cout << stack1.top() << " " << stack2.top() << " ";
    std::cout << (stack1 == stack2);
    return 0;
}