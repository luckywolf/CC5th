#include <iostream>
#include <algorithm>
#include <queue>
#include <cstdlib>
using namespace std;

class Median{
private:
    priority_queue<int,vector<int>,less<int> > max_heap; // left part
    priority_queue<int,vector<int>,greater<int> > min_heap; // right part
    
public:
    void insert(int v);
    float getMedian();
};

void Median::insert(int v){
    if (max_heap.empty() || v < max_heap.top()) { // v is needed to insert to max_heap
        if (max_heap.size() > min_heap.size()) {
            min_heap.push(max_heap.top());
            max_heap.pop();
            max_heap.push(v);
        } else {
            max_heap.push(v);
        }
    } else if (min_heap.empty() || v > min_heap.top()) { // v is needed to insert to min_heap
        if (min_heap.size() < max_heap.size()) {
            min_heap.push(v);
        } else {
            max_heap.push(min_heap.top());
            min_heap.pop();
            min_heap.push(v);
        }
    } else { // v may be inserted to max_hea or min_heap
        if (max_heap.size() > min_heap.size()) {
            min_heap.push(v);
        } else {
            max_heap.push(v);
        }
    }
}

float Median::getMedian(){
    if(max_heap.empty() && min_heap.empty()) {
        return INT_MIN;
    }
    if(max_heap.size() > min_heap.size()) {
        return (float) max_heap.top();
    } else {
        return ( (float) max_heap.top() + (float) min_heap.top()) / 2;
    }
}

int main(){
    srand((unsigned)time(0));
    Median md;
    vector<int> vi;
    int num = rand() % 30; //数量是30以内的随机数
    for(int i = 0; i<num; ++i){
        int data = rand() % 100; //元素是100内的数
        vi.push_back(data);
        md.insert(data);
    }
    sort(vi.begin(), vi.end());
    cout << "total numbers: " << num << endl;
    for(int i = 0; i < num; ++i)
        cout << vi.at(i) << " "; //排序的序列
    cout << endl << "Meidan: " << md.getMedian()<< endl; //中位数
    return 0;
}
