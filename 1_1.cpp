/*
Implement an algorithm to determine if a string has all unique characters. 
What if you can not use additional data structures?
*/
#include <iostream>
#include <cstring>
using namespace std;

bool isUnique1(string s)
{
    bool lookup[256] = {false};
    for(int i = 0; i < s.size(); ++i)
    {
        if(lookup[s[i]]) {
            return false;
        } else { 
           lookup[s[i]] = true;
        } 
    }
    return true;
}

bool isUnique2(string s)
{
    int lookup[8] = {0};
    for(int i = 0; i < s.size(); ++i)
    {
        int index = s[i] / 32;
        int remainder = s[i] % 32;
        if(lookup[index] & (1 << remainder)) {
            return false;
        } else {
            lookup[index] |=  1 << remainder;
        }
    }
    return true;
}

int main()
{
    string s1 = "i am luckywolf.";
    string s2 = "abcdefghijklmnopqrstuvwxyzABCD1234567890";
    cout << isUnique1(s1) << " " << isUnique1(s2) << endl;
    cout << isUnique2(s1) << " " << isUnique2(s2) << endl;
    return 0;
}
