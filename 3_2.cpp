#include <iostream>
#include <climits>
using namespace std;

class stack{
public:
    stack(int size = 1000) {
        buf = new int[size];
        cur = -1;
    }
    ~stack() {
        delete[] buf;
    }
    void push(int val) {
        buf[++cur] = val;
        
    }
    void pop() {
        --cur;
    }
    int top() {
        return buf[cur];
    }
    bool empty() {
        return cur == -1;
    }
private:
    int *buf;
    int cur;
    
};

class stackWithMin{
public:
    stackWithMin() {
    }
    ~stackWithMin() {
    }
    void push(int val) {
        if (val <= min()) {
            s2.push(val);
        }
        s1.push(val);
    }
    void pop() {
        if (s2.top() == s1.top()) {
            s2.pop();
        }
        s1.pop();
    }
    int top() {
        return s1.top();
    }
    int min() {
        if (s2.empty()) {
            return INT_MAX;
        } else {
            return s2.top();
        }
    }
    bool empty() {
        return s1.empty();
    }
private:
    stack s1, s2;

};
int main(){
    //cout << INT_MIN << endl;
    stackWithMin mystack; //StackWithMin mystack;
    for(int i = 0; i < 20; ++i)
        mystack.push(i);
    cout << mystack.min() << " " << mystack.top() << endl;
    mystack.push(-100);
    mystack.push(2);
    cout << mystack.min() << " " << mystack.top() << endl;
    mystack.pop();
    cout << mystack.min() << " " << mystack.top() << endl;
    mystack.pop();
    cout << mystack.min() << " " << mystack.top() << endl;
    return 0;
}