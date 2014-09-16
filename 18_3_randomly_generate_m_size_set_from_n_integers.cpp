/*
Write a method to randomly generate a set of m integers from an array of size n. 
Each element must have equal probability of being chosen.
*/
#include <iostream>
#include <cstdlib>
using namespace std;

void pickMRandomly(int a[], int n, int m){
    for(int i = 0; i < m; ++i){
        int index = rand() % (n-i) + i;
        swap(a[i], a[index]);
    }
}

int main(){
    srand((unsigned)time(0));
    int n = 9, m = 5;
    int a[] = {
        1, 2, 3, 4, 5, 6, 7, 8, 9
    };

    pickMRandomly(a, n, m);
    for(int i = 0; i < m; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}