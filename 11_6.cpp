#include <iostream>
#include <cstdio>
using namespace std;

const int N_MAX = 5;

int searchMatrix(int mat[][N_MAX], int m, int n, int target){
    int row = 0, col = n-1;
    if (target < mat[0][0] || target > mat[m-1][n-1]) {
        return -1;
    }
    while(row < m && col >= 0){
        if(mat[row][col] == target) {
            return row * n + col;
        }
        else if(mat[row][col] < target) {
            ++row;
        }
        else {
            --col;
        }
    }
    return -1;
}
int main(){
    int m = 5, n = 5;
    int matrix[5][5] = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}};
    int k = searchMatrix(matrix, m, n, 13);
    if(k == -1) {
        cout << "not found" << endl;
    } else {
        cout << "position: " << k/n << " "<< k%n << endl;
    }
    return 0;
}