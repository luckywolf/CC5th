/*
Given two strings, write a method to decide if one is a permutation of the other.
*/
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

bool isAnagram(string s1, string s2){
    int len = s1.size();
    if(len != s2.size()) {
        return false;
    }
    
    int counter[256] = {0};
    for(int i = 0; i < len; ++i){
        ++counter[s1[i]];
    }
    
    for(int i = 0; i < len; ++i) {
        if(counter[s2[i]] == 0) {
            return false;
        } else {
            --counter[s2[i]];
        }
    }
    return true;
}
int main()
{
    string s = "aaabbb";
    string t = "ababab";
    cout<< isAnagram(s, t )<< endl;
    return 0;
}