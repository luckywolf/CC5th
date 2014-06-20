#include <iostream>
#include <algorithm>
#include <queue>
#include <cstdlib>
#include <cassert>
using namespace std;

bool myCompare (int i,int j) {
    return i > j;
}

// using min_heap to get k largest element
void getKLargest1(vector<int> &a, int k) {
    int n = a.size();
    assert(n > k && k > 0 && n > 0);
    priority_queue<int, vector<int>, greater<int> > min_heap;
    for (int i = 0; i < k; ++i) {
        min_heap.push(a[i]);
    }
    for (int i = k; i < n; ++i) {
        if (a[i] > min_heap.top()) {
            min_heap.pop();
            min_heap.push(a[i]);
        }
    }
    for (int i = k-1; i >= 0; --i) {
        a[i] = min_heap.top();
        min_heap.pop();
    }
}


// use quick select
int partition(vector<int> &a, int start, int end, int pivotIndex) {
    swap(a[end], a[pivotIndex]);
    int pivot = a[end];
    int swapIndex = start; // element before a[swapIndex] is >= pivot
    for (int i = start; i < end; ++i) {
        if (a[i] >= pivot) {
            swap(a[i], a[swapIndex++]);
        }
    }
    swap(a[swapIndex], a[end]);
    return swapIndex;
}

int getKthLargestRe(vector<int> &a, int start, int end, int k) {
    assert(k >= 1 && k <= a.size());
    while (true) {
        int pivotIndex = rand() % (end - start + 1) + start; // random number in [start, end]
        pivotIndex = partition(a, start, end, pivotIndex);
        int rank = pivotIndex - start + 1;
        if (rank == k) {
            return a[pivotIndex];
        } else if (rank > k) {
            return getKthLargestRe(a, start, pivotIndex - 1, k);
        } else {
            return getKthLargestRe(a, pivotIndex + 1, end, k - rank);
        }
    }
}

void getKLargest2(vector<int> &a, int k) {
    int n = a.size();
    assert(n > k && k > 0 && n > 0);
    int kthLargest = getKthLargestRe(a, 0, n-1, k);
    for (int i = 0, swapIndex = 0; i < n; ++i) {
        if (a[i] >= kthLargest) {
            swap(a[swapIndex++], a[i]);
        }
    }
}



int main(){
    srand((unsigned)time(0));
    vector<int> vi, a1, a2;
    int num = 25;
    for(int i = 0; i < num; ++i){
        int data = rand() % 100; //元素是100内的数
        vi.push_back(data);
        a1.push_back(data);
        a2.push_back(data);
    }
    sort(vi.begin(), vi.end(), myCompare);
    cout << "total numbers: " << num << endl;
    for(int i = 0; i < num; ++i)
        cout << vi.at(i) << " "; //sorted numbers
    cout << endl;
    int k = 10;
    getKLargest1(a1, k);
    cout << "largest " << k << " numbers:" << endl;
    for(int i = 0; i < k; ++i)
        cout << a1.at(i) << " "; //largest k numbers
    cout << endl;
    getKLargest2(a2, k);
    sort(a2.begin(), a2.begin()+k, myCompare);
    cout << "largest " << k << " numbers:" << endl;
    for(int i = 0; i < k; ++i)
        cout << a2.at(i) << " "; //largest k numbers
    cout << endl;
    return 0;
}
