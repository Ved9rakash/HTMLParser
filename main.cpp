#include <iostream>

namespace calculations {
    auto multiply = [](int number) {return number*323;};
}

int main() {

    std::cout << calculations::multiply(32);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
