#include <iostream>
#include <cstring>
using namespace std;

string replaceSpace(string &s){
    int counter = 0;
    int len = s.size();
    for (int i = 0; i < len; ++i) {
        if (s[i] == ' ') {
            ++counter;
        }
    }
    if (counter == 0) {
        return s;
    }
    s.append(" ", 2 * counter);
    for (int i = len - 1, j = len - 1 + 2 * counter; i >= 0 && counter > 0; --i) {
        if (s[i] == ' ') {
            s[j--] = '0';
            s[j--] = '2';
            s[j--] = '%';
        } else {
            s[j--] = s[i];
        }
    }
    return s;
}

int main(){
    string c(10, ' ');
    cout<< replaceSpace(c) << endl;
    return 0;
}