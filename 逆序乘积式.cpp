#include <iostream>
#include <string>
#include <algorithm>

std::string reverseNumber(std::string num) {
    std::reverse(num.begin(), num.end());
    while (!num.empty() && num.front() == '0') {
        num.erase(0, 1);
    }
    return num;
}

int main() {
    std::string num1, num2;
    std::cin >> num1 >> num2;

    long long int product1 = std::stoll(num1) * std::stoll(num2);
    std::string reversedNum1 = reverseNumber(num1), reversedNum2 = reverseNumber(num2);
    long long int reversedProduct = std::stoll(reversedNum1) * std::stoll(reversedNum2);

    std::cout << num1 << "*" << num2;
    if (product1 == reversedProduct) {
        std::cout << "=";
    }
    else {
        std::cout << "!=";
    }
    std::cout << reversedNum1 << "*" << reversedNum2 << std::endl;

    return 0;
}
