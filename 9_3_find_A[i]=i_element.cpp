/*
A magic index in an array A[0...n-1] is defined to be an index such that A[i] = i.
Given a sorted array, write a method to find a magic index, if one exists, in array A.
FOLLOW UP
What if the values are not distinct?
*/
#include <iostream>
using namespace std;

int getMagicIndex(int A[], int n) {
    int start = 0, end = n - 1;
    while (start <= end) {
        int mid = (start + end) / 2;
        if (mid == A[mid]) {
            return mid;
        } else if (A[mid] > mid) {
            end = mid - 1;
        } else {
            start  = mid + 1;
        }
    }
    return -1;
}

/*
A[]:   -10  -5  2  2  2  3  4  7  9  12  13
index:  0    1  2  3  4  5  6  7  8  9   10
mid = 5, A[mid] = 3 in first round
*/
int getMagicIndexDupRe(int A[], int n, int start, int end) {
    if (start < 0 || end >= n || end < start) {
        return -1;
    }
    int mid = (start + end) / 2;
    if (A[mid] == mid) {
        return mid;
    }
    
    // 1) because A[mid] != mid, we need to eliminate mid, so end is at most = mid - 1
    // 2) if A[mid] < mid, end is at most = A[mid]
    // combine 1) and 2), we have end = min(A[mid], mid - 1)
    int left = getMagicIndexDupRe(A, n, start, min(A[mid], mid-1));
    if (left >= 0) {
        return left;
    }
    // 1) because A[mid] != mid, we need to eliminate mid, so start is at least = mid + 1
    // 2) if A[mid] > mid, start is at least = A[mid]
    // combine 1) and 2), we have start = max(A[mid], mid + 1)
    int right = getMagicIndexDupRe(A, n, max(A[mid], mid+1), end);
    return right;
}

int getMagicIndexDup(int A[], int n) {
    return getMagicIndexDupRe(A, n, 0, n-1);
}


int main()
{
    int n = 11;
    int a[] = {
        -40, -20, -1, 1, 2, 3, 5, 7, 9, 12, 13
    };
    int b[] = {
        -10, -5, 1, 1, 2, 3, 4, 7, 9, 12, 13
    };
    
    cout << getMagicIndex(a, n) << endl;
    cout << getMagicIndexDup(b, n) << endl;
    return 0;
}
