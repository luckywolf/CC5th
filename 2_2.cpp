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

/*
 
 1->2->3->4>NULL
    |     |
   k=2   0th to last
 
*/


ListNode* findKthToLast(ListNode *head, int k){
    ListNode *adv = head;
    for (int i = k; i > 0; --i) {
        if (adv) {
            adv = adv->next;
        } else {
            return NULL;
        }
    }
    if (!adv) {
        return NULL;
    }
    ListNode *ret = head;
    while(adv->next){
        adv = adv->next;
        ret = ret->next;
    }
    return ret;
}


int main(){
    int n = 10;
    int a[] = {
        9, 2, 1, 3, 5, 6, 2, 6, 3, 1
    };
    ListNode *head = init(a, n);
    // ListNode *p = findKthToLast(head, 10);
    ListNode *p = findKthToLast(head, 6);
    if(p) {
        cout << p->val << endl;
    } else {
        cout << "the length of link is not long enough" << endl;
    }    return 0;
}