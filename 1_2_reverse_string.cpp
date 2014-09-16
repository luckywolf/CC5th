/*
Implement a function void reverse(char* str) in c or C++ which reverses a null-terminated string.
*/
#include <iostream>
#include <cstring>
using namespace std;

//void swap(char &a, char &b){
//    a = a^b;
//    b = a^b;
//    a = a^b;
//}

void reverse1(char *str){
    if(!str || *str == '\0') {
        return;
    }
    char *tail = str;
    while(*tail != '\0') {
        tail++;
    }
    --tail;
    while(str < tail )
        swap(*str++, *tail--);
}

int main(){
    char s[] = "1234567890";
    reverse1(s);
    cout<< s << endl;
    return 0;
}