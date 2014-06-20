#include <iostream>
#include <cstring>
#include <unordered_set>
using namespace std;

struct BiNode{
    int val;
    BiNode *node1, *node2;
    BiNode(int x): val(x), node1(NULL), node2(NULL) {}
};


BiNode *BSTToCircularDList(BiNode *root){
    if (!root) {
        return NULL;
    }
    BiNode *left = BSTToCircularDList(root->node1);
    BiNode *right = BSTToCircularDList(root->node2);
    BiNode *head = root;
    if (left) {
        head = left;
        left->node1->node2 = root;
        root->node1 = left->node1;
    }
    BiNode *tail = root;
    if (right) {
        tail = right->node1;
        right->node1 = root;
        root->node2 = right;
    }
    head->node1 = tail;
    tail->node2 = head;
    return head;
}

BiNode *BSTToDList(BiNode *root){
    if (!root) {
        return NULL;
    }
    BiNode *head = BSTToCircularDList(root);
    BiNode *tail = head->node1;
    head->node1 = NULL;
    tail->node2 = NULL;
    return head;
}


void print(BiNode *head){
    while(head){
        cout << head->val << " ";
        head = head->node2;
    }
    cout << endl;
}

/* 
               4
        2           5
     1     3           6
   0
*/
 
int main(){
    BiNode *binode0 = new BiNode(0);
    BiNode *binode1 = new BiNode(1);
    BiNode *binode2 = new BiNode(2);
    BiNode *binode3 = new BiNode(3);
    BiNode *binode4 = new BiNode(4);
    BiNode *binode5 = new BiNode(5);
    BiNode *binode6 = new BiNode(6);
    binode4->node1 = binode2;
    binode4->node2 = binode5;
    binode5->node2 = binode6;
    binode2->node1 = binode1;
    binode2->node2 = binode3;
    binode1->node1 = binode0;
    
    BiNode *head = BSTToDList(binode4);
    print(head);
    return 0;
}