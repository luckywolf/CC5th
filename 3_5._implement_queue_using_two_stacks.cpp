/*
Implement a MyQueue class which implements a queue using two stacks.
*/
#include <iostream>
#include <stack>
using namespace std;

template <typename T>
class MyQueue{
public:
    MyQueue(){
    }
    
    ~MyQueue(){
    }
    
    void push(T val) {
        newest.push(val);
    }
    
    void pop() {
        move(newest, oldest);
        oldest.pop();
    }
    
    T front() {
        move(newest, oldest);
        return oldest.top();
    }
    
    T back() {
        move(oldest, newest);
        return newest.top();
    }
    
    int size() {
        return oldest.size() + newest.size();
    }
    
    bool empty() {
        return oldest.empty() && newest.empty();
    }

private:
    stack<T> oldest, newest;
    void move(stack<T> &src, stack<T> &dst) {
        if (dst.empty()) {
            while (!src.empty()) {
                dst.push(src.top());
                src.pop();
            }
        }
    }
};

int main(){
    MyQueue<int> q;
    for(int i = 0; i < 10; ++i){
        q.push(i);
    }
    
    cout << q.front() << " " << q.back() << endl;
    cout << endl;
    q.pop();
    q.push(10);
    cout << q.front() << " " << q.back() << endl;
    cout << endl;
    cout << q.size() << " " << q.empty() << endl;
    return 0;
}