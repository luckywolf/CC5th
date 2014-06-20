#include <iostream>
#include <cstdlib>
#include <stack>
#include <queue>
using namespace std;

void qsort(stack<int> &s){
    priority_queue< int,vector<int>,greater<int> > q;
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
    while(!q.empty()){
        s.push(q.top());
        q.pop();
    }
}

stack<int> ssort(stack<int> s){
    stack<int> res;
    while(!s.empty()){
        int temp = s.top();
        s.pop();
        while(!res.empty() && res.top() > temp){
            s.push(res.top());
            res.pop();
        }
        res.push(temp);
    }
    return res;
}
int main(){
    srand((unsigned)time(0));
    stack<int> s;
    
    for(int i = 0; i < 10; ++i)
        s.push((rand() % 100));
    s = ssort(s);
//    qsort(s);
    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
    return 0;
}