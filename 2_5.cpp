/*
You have two numbers represented by a linked list, where each node contains 
a single digit. The digits are stored in reverse order, such that the 1¡¯s 
digit is at the head of the list. Write a function that adds the two numbers 
and returns the sum as a linked list.

EXAMPLE
Input: (7 -> 1 -> 6) + (5 -> 9 -> 2). That is, 617 + 295.
Output: 2 -> 1 -> 9. That is, 912.

FOLLOW UP
Suppose the digits are stored in forward order. Repeat the above problem.
EXAMPLE
Input: (6 -> 1 -> 7) + (2 -> 9 -> 5). That is, 617 + 295.
Output: 9 -> 1 -> 2. That is, 912.

*/
#include <iostream>
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

ListNode *reverse(ListNode *head) {
    ListNode dummy(0);
    dummy.next = head;
    ListNode *pre = &dummy;
    ListNode dummy2(0);
    ListNode *ret = &dummy2;
    while(pre->next) {
        ListNode *mov = pre->next;
        pre->next = mov->next;
        mov->next = ret->next;
        ret->next = mov;
    }
    return dummy2.next;
}

int getLength(ListNode *head) {
    int ret = 0;
    while (head) {
        ++ret;
        head = head->next;
    }
    return ret;
}

ListNode *prepend(ListNode *head, int n) {
    ListNode dummy(0);
    dummy.next = head;
    ListNode *pre = &dummy;
    for (int i = 0; i < n; ++i) {
        ListNode *temp = pre->next;
        pre->next = new ListNode(0);
        pre->next->next = temp;
    }
    return dummy.next;
}

ListNode *addNumber(ListNode *l1, ListNode *l2) {
    if (!l1) {
        return l2;
    }
    if (!l2) {
        return l1;
    }
    int len1 = getLength(l1);
    int len2 = getLength(l2);
    if (len1 < len2) {
        l1 = prepend(l1, len2 - len1);
    } else if (len1 > len2) {
        l2 = prepend(l2, len1 - len2);
    }
    int len = max(len1, len2);
    l1 = reverse(l1);
    l2 = reverse(l2);
    ListNode *ret = l1;
    int carry = 0;
    for (int i = 0; i < len; ++i) {
        l1->val += l2->val + carry;
        carry = l1->val / 10;
        l1->val %= 10;
        l1 = l1->next;
        l2 = l2->next;
    }
    ret = reverse(ret);
    if (carry) {
        ListNode *newret = new ListNode(carry);
        newret->next = ret;
        return newret;
    } else {
        return ret;
    }
}


ListNode *addNumber2(ListNode *l1, ListNode *l2) {
    if (!l1) {
        return l2;
    }
    if (!l2) {
        return l1;
    }
    l1 = reverse(l1);
    l2 = reverse(l2);
    ListNode dummy(0);
    ListNode *res = &dummy;
    int carry = 0;
    while (l1 || l2 || carry) {
        int temp = carry;
        if (l1) {
            temp += l1->val;
            l1 = l1->next;
        }
        if (l2) {
            temp += l2->val;
            l2 = l2->next;
        }
        carry = temp / 10;
        res->next = new ListNode(temp % 10);
        res = res->next;
    }
    res = dummy.next;
    res = reverse(res);
    return res;
}


int main(){
    int n = 4;
    int a[] = {
        1, 2, 3, 4
    };
    int m = 3;
    int b[] = {
        5, 8, 9
    };
    ListNode *p = init(a, n);
    ListNode *q = init(b, m);
    if (p) {
        print(p);
    }
    if (q) {
        print(q);
    }
    ListNode *res = addNumber2(p, q);
    if (res) {
        print(res);
    }
    return 0;
}