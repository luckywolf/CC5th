/*
Implement a function to check if a linked list is a palindrome.
*/
#include <iostream>
#include <stack>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
};

ListNode* init(int a[], int n){
    ListNode *head, *p;
    for(int i = 0; i < n; ++i){
        ListNode *nd = new ListNode(a[i]);
        if(i == 0){
            head = p = nd;
            continue;
        }
        p->next = nd;
        p = nd;
    }
    return head;
}

void print(ListNode *head){
    while(head){
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int getLength(ListNode *head) {
    int ret = 0;
    while (head) {
        ++ret;
        head = head->next;
    }
    return ret;
}


bool isPalindrome(ListNode *head) {
    if (!head) {
        return true;
    }
    int len = getLength(head);
    stack<int> half;
    ListNode *p = head;
    for (int i = len / 2; i > 0; --i) {
        half.push(p->val);
        p = p->next;
    }
    if (len % 2) {
        p = p->next;
    }
    while (p) {
        if (p->val == half.top()) {
            p = p->next;
            half.pop();
        } else {
            return false;
        }
    }
    return true;
}

bool isPalindromeRe(ListNode *& front, ListNode *& back, int len) {
    if (len == 1) {
        back = front;
        return true;
    } else if (len == 2) {
        back = front->next;
        return front->val == back->val;
    } else {
        bool pre = isPalindromeRe(front->next, back, len - 2);
        if (!pre) {
            return false;
        } else {
            back = back->next;
            return front->val == back->val;
        }
    }
}

bool isPalindrome2(ListNode *head) {
    if (!head) {
        return true;
    }
    ListNode *front = head, *back = NULL;
    int len = getLength(head);
    return isPalindromeRe(front, back, len);
}


int main(){
    int n = 9;
    int a[] = {
        1, 2, 3, 4, 5, 4, 3, 2, 1
    };
    ListNode *p = init(a, n);
    if (p) {
        print(p);
    }
    bool res = isPalindrome(p);
    cout << res << endl;
    bool res2 = isPalindrome2(p);
    cout << res2 << endl;
    return 0;
}