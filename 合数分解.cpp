#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <set>

using namespace std;

// 函数声明
void primeFactors(int n, set<int>& factors);
void findPrimeFactors(const vector<int>& numbers, set<int>& primeSet);

int main() {
    int n;
    cin >> n;
    vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    set<int> primeSet;
    findPrimeFactors(numbers, primeSet);

    for (auto prime : primeSet) {
        cout << prime << " ";
    }
    cout << endl;

    return 0;
}

// 对合数进行素数分解
void primeFactors(int n, set<int>& factors) {
    for (int i = 2; i <= n / i; ++i) {
        while (n % i == 0) {
            factors.insert(i);
            n /= i;
        }
    }
    if (n > 1) {
        factors.insert(n);
    }
}

// 找出所有合数的素数分解，并构建最小素数集
void findPrimeFactors(const vector<int>& numbers, set<int>& primeSet) {
    for (int num : numbers) {
        primeFactors(num, primeSet);
    }
}
