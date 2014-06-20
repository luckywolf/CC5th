#include <iostream>
#include <string>
using namespace std;

static string digits[10] = {"", "one", "two", "three", "four",
                            "five", "six", "seven", "eight", "nine"};
static string tens[10] = {"", "ten", "twenty", "thirty", "forty", "fifty",
                          "sixty", "seventy", "eighty", "ninety"};
static string teens[9] = {"eleven", "twelve", "thirteen", "fourteen",
    "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
static string bigs[4] = {"", "thousand", "million", "billion"};

string numToString100(int number) {
    string res;
    if (number >= 100) {
        res += digits[number / 100] + " hundred ";
        number %= 100;
    }
    if (number >= 11 && number <= 19) {
        res += teens[number - 11] + " ";
        return res;
    } else if (number == 10 || number >= 20) {
        res += tens[number / 10] + " ";
        number %= 10;
    }
    if (number >= 1 && number <= 9) {
        res += digits[number] + " ";
    }
    return res;
}

string numToString(int number) {
    if (number == 0) {
        return "zero";
    } else if (number < 0) {
        return "negative " + numToString(-1 * number);
    }
    
    string res;
    int count  = 0;
    while (number > 0) {
        if (number % 1000) {
            res = numToString100(number % 1000) + bigs[count] + " " + res;
        }
        number /= 1000;
        ++count;
    }
    return res;
}


int main(){
    int n = -1783732312;
    string res  = numToString(n);
    cout << res << endl;
    return 0;
}