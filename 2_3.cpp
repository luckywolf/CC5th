/*
Implement an algorithm to delete a node in the middle of a single linked list, 
given only access to that node.

EXAMPLE

Input: the node ¡®c¡¯ from the linked list a->b->c->d->e R
esult: nothing is returned, but the new linked list looks like a->b->d->e
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


bool deleteNode(ListNode *node) {
    if (!node || !node->next) {
        return false;
    }
    ListNode *del = node->next;
    node->val = del->val;
    node->next = del->next;
    delete del;
    return true;
}

int main(){
    int n = 10;
    int a[] = {
        9, 2, 1, 3, 5, 6, 2, 6, 3, 1
    };
    ListNode *head = init(a, n);
    int cc = 10;
    ListNode *c = head;
    for(int i = 1; i < cc; ++i) {
        c = c->next;
    }
    print(head);
    if(deleteNode(c))
        print(head);
    else
        cout << "failure" << endl;
    return 0;
}