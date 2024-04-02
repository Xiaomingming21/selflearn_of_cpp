#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <set>

using namespace std;

// 函数声明
void mergeAndFilter(vector<int>& nums1, vector<int>& nums2, set<int>& mergedSet);
bool isMultiple(int num, const set<int>& numbers);

int main() {
    int n1, n2;
    cin >> n1;
    vector<int> nums1(n1);
    for (int i = 0; i < n1; ++i) {
        cin >> nums1[i];
    }

    cin >> n2;
    vector<int> nums2(n2);
    for (int i = 0; i < n2; ++i) {
        cin >> nums2[i];
    }

    set<int> mergedSet;
    mergeAndFilter(nums1, nums2, mergedSet);

    for (auto num : mergedSet) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

// 合并并过滤整数
void mergeAndFilter(vector<int>& nums1, vector<int>& nums2, set<int>& mergedSet) {
    for (int num : nums1) {
        mergedSet.insert(num);
    }
    for (int num : nums2) {
        mergedSet.insert(num);
    }

    for (auto it = mergedSet.begin(); it != mergedSet.end(); ) {
        if (isMultiple(*it, mergedSet)) {
            it = mergedSet.erase(it);
        }
        else {
            ++it;
        }
    }
}

// 检查一个数是否是集合中另一个数的倍数
bool isMultiple(int num, const set<int>& numbers) {
    for (int factor = 2; factor <= num / 2; ++factor) {
        if (num % factor == 0 && numbers.find(factor) != numbers.end()) {
            return true;
        }
    }
    return false;
}
