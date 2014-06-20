#include <iostream>
#include <cstdlib>
using namespace std;


int countIs(int n, int i){
    if(i < 1 || i > 9) return -1; //i is among 1-9; 0 is special
    
    int factor = 1;
    int count = 0;
    int low = 0, cur = 0, high = 0;
    while (factor <= n) {
        low = n % factor;  // lower bits
        cur = (n / factor) % 10; // cur bit
        high = n /  (factor * 10); // higher bits
        
        if (cur < i) {
            count += high * factor;
        } else if (cur == i) {
            count += high * factor + low + 1;
        } else {
            count += (high + 1) * factor;
        }
        factor *= 10;
    }
    
    return count;
}

int main(){
    int i = 3, n = 62523;
    cout << countIs(n, i) << endl;
    return 0;
}