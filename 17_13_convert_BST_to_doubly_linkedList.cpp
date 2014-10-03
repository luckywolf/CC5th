/*
Consider a simple node-like data structure called BiNode, which has pointers to two
other nodes.
public class BiNode {
    public BiNode node1, node2;
    public int data;
}
The data structure BiNode could be used to represent both binary tree (where node1 is the 
left node and node2 is the right node) or a doubly linked list (where node1 is the previous
node and node2 is the next node). Implement a method to convert a binary search tree (implemented
in BiNode) into a doubly linked list. The values should be kept in the order and the operation
should be performed in place (that is, on the original data structure).
*/
#include <iostream>
#include <cstring>
#include <unordered_set>
using namespace std;

struct BiNode{
    int val;
    BiNode *node1, *node2;
    BiNode(int x): val(x), node1(NULL), node2(NULL) {}
};

/* version 1*/
BiNode *BSTToCircularDList_1(BiNode *root){
    if (!root) {
        return NULL;
    }
    BiNode *left = BSTToCircularDList_1(root->node1);
    BiNode *right = BSTToCircularDList_1(root->node2);
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

/* version 2 */
void BSTToDList_2(BiNode *root, BiNode*& start, BiNode*& end){
    start = end = root; // be cautious, possible bugs
    if (root->node1) {
        BiNode *lstart = NULL, *lend = NULL;
        BSTToDList_2(root->node1, lstart, lend);
        lend->node2 = root;
        root->node1 = lend;
        start = lstart;  // be cautious, possible bugs
    }
    if (root->node2) {
        BiNode *rstart = NULL, *rend = NULL;
        BSTToDList_2(root->node2, rstart, rend);
        rstart->node1 = root;
        root->node2 = rstart;
        end = rend; // be cautious, possible bugs
    }
}

BiNode* BSTToCircularDList_2(BiNode *root){
    if (!root) {
        return NULL;
    }
    BiNode *start = NULL, *end = NULL;
    BSTToDList_2(root, start, end);
    start->node1 = end;
    end->node2 = start;
    return start;
}

/* for print */
BiNode *BSTToDListForPrint(BiNode *root){
    if (!root) {
        return NULL;
    }
    // BiNode *head = BSTToCircularDList_1(root);
    BiNode *head = BSTToCircularDList_2(root);
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
    
    BiNode *head = BSTToDListForPrint(binode4);
    print(head);
    return 0;
}