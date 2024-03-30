

/*【问题描述】

若两个正整数的乘积，等于两正整数各自逆序后的乘积，则称其为逆序乘积式。编写程序读入两个正整数，然后判断这两个正整数能否构成逆序乘积式。假设两个正整数的乘积不会超过int数据类型的表示范围。

【输入形式】

从控制台输入以一个空格分隔的两个正整数。

【输出形式】

若两个正整数能够构成逆序乘积式，则输出两个正整数及其逆序的乘积形式，并且中间用一个等号相连；若不能构成逆序乘积式，则输出两个正整数及其逆序的乘积形式，并且中间用一个不等号相连。
注意：输出的字符之间没有空格分隔。若逆序后最高位为0，则为0的最高位不输出。
*/

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