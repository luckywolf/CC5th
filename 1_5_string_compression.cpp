/*
Implement a method to perform basic string compression using the counts of repeated
characters. For example, the string aabcccccaaa would become a2b1c5a3. If the 
"compressed" string would not become smaller than the original string, your method
should return the original string.
*/
#include <iostream>
#include <cstring>
using namespace std;

// One scan, 2n space
string compress(string s){
    int len = s.size();
    int i = 0, j = 0, counter = 0;
    string res(s + s);
    for (; i < len && j < len; ++i) {
        ++counter;
        if (i < len - 1 && s[i] == s[i+1]) {
            continue;
        } else {
            res[j++] = s[i];
            int start = j;
            while (counter) {
                res[j++] = counter % 10 + '0';
                counter /= 10;
            }
            int end = j - 1;
            while (start < end) {
                swap(res[start++], res[end--]);
            }
        }
    }
    
    if (j >= len) {
        return s;
    } else {
        res.resize(j);
        return res;
    }
}

// two scan, miminum space
int getComLength(string s) {
    int res = 0;
    int len = s.size();
    for (int i = 0, counter = 0; i < len; ++i) {
        ++counter;
        if (i ==  len - 1 || s[i] != s[i + 1]) {
            ++res;
            while (counter) {
                ++res;
                counter /= 10;
            }
        }
    }
    return res;
}

string compress2(string s){
    int len = s.size();
    int comlen = getComLength(s);
    if (comlen >= len) {
        return s;
    }
    string res(comlen, ' ');
    for (int i = 0, j = 0, counter = 0; i < len; ++i) {
        ++counter;
        if (i == len - 1 || s[i] != s[i+1]) {
            res[j++] = s[i];
            int start = j;
            while (counter) {
                res[j++] = counter % 10 + '0';
                counter /= 10;
            }
            int end = j - 1;
            while (start < end) {
                swap(res[start++], res[end--]);
            }
        }
    }
    return res;
}


int main(){
    string c("aaaaaaaaaaaaaaaaaabbbbbbbcccabcc");
    cout<< compress(c) << endl;
    cout<< compress2(c) << endl;
    return 0;
}