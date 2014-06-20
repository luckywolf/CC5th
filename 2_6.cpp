#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
};

ListNode* init(int a[], int n, int m){
    ListNode *head, *p, *q;
    for(int i = 0; i < n; ++i){
        ListNode *nd = new ListNode(a[i]);
        if(i == m) q = nd;
        if(i == 0){
            head = p = nd;
            continue;
        }
        p->next = nd;
        p = nd;
    }
    p->next = q;
    return head;
}


ListNode *loopStart(ListNode *head) {
    if (!head) {
        return NULL;
    }
    ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            break;
        }
    }
    if (!fast || !fast->next) {
        return NULL;
    }
    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}


int main(){
    int n = 10, m = 9;// m<n
    int a[] = {
        3, 2, 1, 3, 5, 6, 2, 6, 3, 1
    };
    ListNode *head = init(a, n, m);
    ListNode *p = loopStart(head);
    if(p)
        cout << p->val << endl;
    return 0;
}