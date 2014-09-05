#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>
using namespace std;
 
// Takes an integer n, and determine between 0 and n how many integers contain 5 in it.
// E.g, countHas5(52) will return 8 (5, 15, 25, 35, 45, 50, 51, 52)
int countHas5(int n){
       int origN = n;
    if (n <= 4) { // if n is negative, return 0
       return 0;
    }
    // save all the digits of the input integer into a vector in reversed order
    vector<int> digits;
    while(n > 0) {
       digits.push_back(n % 10);
       n /= 10;
    }
    int len = digits.size();
    // a quick lookup table for pow(9, n) ( 0 <= n <= len-1)
    vector<int> pow9(len, 1);
    for (int i = 1; i < len; i++) {
       pow9[i] = pow9[i-1] * 9;
    }
 
    int notHas5 = 0;
    // beginning from the highest bits to process every bit and log how many
    // integers don't contain 5
    // e.g, given 525,
    // 9 * 9 integers don't contain 5 in the range [0, 99], and there are
    // 5 ranges ([0, 99], [100, 199], [200, 299], [300, 399], [400, 499]).
    for (int i = len-1; i >= 0; --i) {
       notHas5 += digits[i] * pow9[i];
        if (digits[i] == 5) {
             break;
        } else if (digits[i] > 5) {
               notHas5 -= pow9[i];
        }
    }
    if (digits[0] == 0) {
       notHas5 += 1;  // handle integers (>= 2 bits) ending with "0"
    }
   
    return origN + 1 - notHas5; // count range is [0, origN]
}
 
int main(){
    int n = -1;
    cout << "n = " << n << ", countHas5(n) = " << countHas5(n) << endl;
    n = 0;                           
    cout << "n = " << n << ", countHas5(n) = " << countHas5(n) << endl;
    n = 1;
    cout << "n = " << n << ", countHas5(n) = " << countHas5(n) << endl;
    n = 5;
    cout << "n = " << n << ", countHas5(n) = " << countHas5(n) << endl;
    n = 8;
    cout << "n = " << n << ", countHas5(n) = " << countHas5(n) << endl;
    n = 15;
    cout << "n = " << n << ", countHas5(n) = " << countHas5(n) << endl;
    n = 55;
    cout << "n = " << n << ", countHas5(n) = " << countHas5(n) << endl;
    n = 60;
    cout << "n = " << n << ", countHas5(n) = " << countHas5(n) << endl;
    n = 525;
    cout << "n = " << n << ", countHas5(n) = " << countHas5(n) << endl;
    n = 599;
    cout << "n = " << n << ", countHas5(n) = " << countHas5(n) << endl;
    n = 600;
    cout << "n = " << n << ", countHas5(n) = " << countHas5(n) << endl;
    n = 620;
    cout << "n = " << n << ", countHas5(n) = " << countHas5(n) << endl;
 
    return 0;
}
