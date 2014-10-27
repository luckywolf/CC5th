/*
Write an algorithm to find the ¡®next¡¯ node (i.e., in-order successor) of a given node in a binary search tree
where each node has a link to its parent.
*/
#include <iostream>
#include <cstring>
using namespace std;

const int maxn = 100;
struct TreeNode{
    int val;
    TreeNode *left, *right, *parent;
    TreeNode(int x = -1): val(x), left(NULL), right(NULL), parent(NULL) {}
};
TreeNode *p, node[maxn];
int cnt;

void init(){
    p = NULL;
    memset(node, '\0', sizeof(node));
    cnt = 0;
}
void create_minimal_tree(TreeNode* &head, TreeNode *parent, int a[], int start, int end){
    if(start <= end){
        int mid = (start + end)>>1;
        node[cnt].val = a[mid];
        node[cnt].parent = parent;
        head = &node[cnt++];
        create_minimal_tree(head->left, head, a, start, mid-1);
        create_minimal_tree(head->right, head, a, mid+1, end);
    }
}

TreeNode* getLeftMost(TreeNode* head){
    if(!head) {
        return NULL;
    }
    TreeNode *p = head;
    while(p->left) {
        p = p->left;
    }
    return p;
}

TreeNode* getInorderNext(TreeNode* node){
    if(!node) {
        return NULL;
    }
    if(node->right) {
        return getLeftMost(node->right);
    }
    TreeNode *p = node->parent;
    while(p){
        if (p->left == node) {
            return p;
        } else {
           node = p;
           p = p->parent;
        }
    }
    return p;
}
    
int main(){
    int a[] = {
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9
    };
    init();
    TreeNode *head = NULL;
    create_minimal_tree(head, NULL, a, 0, 9);
    cout<<"the head is "<< head->val << endl;
    TreeNode *n1 = getInorderNext(head);
    cout<<"the Inorder next of head is: "<< n1->val<< endl;
    TreeNode *n2 = getInorderNext(n1);
    cout<<"the next one is: "<< n2->val<< endl;
    return 0;
}
