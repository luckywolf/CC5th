#include <iostream>
#include <cstring>
#include <unordered_set>
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

ListNode *removeDulicate(ListNode *head){
    unordered_set<int> lookup;
    ListNode dummy(0);
    dummy.next = head;
    ListNode *pre = &dummy;
    while(pre->next){
        if (lookup.find(pre->next->val) != lookup.end()) {
            ListNode *del = pre->next;
            pre->next = del->next;
            delete del;
        } else {
            lookup.insert(pre->next->val);
            pre = pre->next;
        }
    }
    return dummy.next;
}

ListNode *removeDulicate1(ListNode *head){
    ListNode dummy(0);
    dummy.next = head;
    ListNode *pre = &dummy;
    while(pre->next){
        ListNode *q = pre->next;
        while (q->next) {
            if (pre->next->val == q->next->val) {
                ListNode *del = q->next;
                q->next = del->next;
                delete del;
            } else {
                q = q->next;
            }
        }
        pre = pre->next;
    }
    return dummy.next;
}

void print(ListNode *head){
    while(head){
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}
int main(){
    int n = 10;
    int a[] = {
        3, 2, 1, 3, 5, 6, 2, 6, 3, 1
    };
    ListNode *head = init(a, n);
    removeDulicate(head);
    //removeDulicate1(head);
    print(head);
    return 0;
}