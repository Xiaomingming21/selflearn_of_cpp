#include <iostream>
#include <vector>

using namespace std;

// 函数声明
void readMatrix(vector<vector<int>>& matrix, int n);
void matrixMultiply(const vector<vector<int>>& A, const vector<vector<int>>& B, vector<vector<int>>& result, int n);
void printMatrix(const vector<vector<int>>& matrix, int n);

int main() {
    int n, dataCount;
    cin >> n >> dataCount;

    vector<vector<int>> matrix1(n, vector<int>(n, 0));
    vector<vector<int>> matrix2(n, vector<int>(n, 0));
    vector<vector<int>> result(n, vector<int>(n, 0));

    readMatrix(matrix1, n);
    readMatrix(matrix2, n);

    matrixMultiply(matrix1, matrix2, result, n);

    printMatrix(result, n);

    return 0;
}

// 读取矩阵数据
void readMatrix(vector<vector<int>>& matrix, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            int data;
            cin >> data;
            matrix[i][j] = data;
            if (i != j) {
                matrix[j][i] = data;
            }
        }
    }
}

// 矩阵乘法
void matrixMultiply(const vector<vector<int>>& A, const vector<vector<int>>& B, vector<vector<int>>& result, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < n; ++k) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// 打印矩阵
void printMatrix(const vector<vector<int>>& matrix, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
