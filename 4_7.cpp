/*
Design an algorithm and write code to find the first common ancestor of two nodes
in a binary tree. Avoid storing additional nodes in a data structure. 
NOTE: This is not necessarily a binary search tree.
*/
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

const int maxn = 100;
struct TreeNode{
    unsigned int val;
    TreeNode *left, *right, *parent;
    TreeNode(int x = 0): val(x), left(NULL), right(NULL), parent(NULL) {}
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
        int mid = (start + end) >> 1;
        node[cnt].val = a[mid];
        node[cnt].parent = parent;
        head = &node[cnt++];
        create_minimal_tree(head->left, head, a, start, mid-1);
        create_minimal_tree(head->right, head, a, mid+1, end);
    }
}

TreeNode* search(TreeNode* head, int x){
    while (head) {
        if (x == head->val) {
            return head;
        } else if (x < head->val) {
            head = head->left;
        } else if (x > head->val) {
            head = head->right;
        }
    }
    return NULL;
}

int getLengthToRoot(TreeNode* node){
    int res = 0;
    while(node) {
        ++res;
        node = node->parent;
    }
    return res;
}

TreeNode* lowestCommonAncestor(TreeNode* t1, TreeNode *t2){
    if(!t1 || !t2) {
        return NULL;
    }
    if (t1 == t2) {
        return t1;
    }
    int len1 = getLengthToRoot(t1);
    int len2 = getLengthToRoot(t2);
    int diff = abs(len1 - len2);
    if (len1 < len2) {
        while (diff) {
            t2 = t2->parent;
            --diff;
        }
    } else {
        while (diff) {
            t1 = t1->parent;
            --diff;
        }
    }
    while (t1 != t2) {
        t1 = t1->parent;
        t2 = t2->parent;
    }
    return t1;
}

bool getPathFromRoot(TreeNode *node, TreeNode *head, vector<TreeNode *> &path) {
    if (!head || !node) {
        return false;
    }
    path.push_back(head);
    if (node == head) {
        return true;
    }
    bool found = false;
    if (head->left) {
        found = getPathFromRoot(node, head->left, path);
    }
    if (!found && head->right){
        found = getPathFromRoot(node, head->right, path);
    }
    if (!found) {
        path.pop_back();
    }
    return found;
}

void printPath(vector<TreeNode *> &path) {
    if (path.empty()) {
        return;
    }
    cout << "path : ";
    for (vector<TreeNode *>::iterator it = path.begin(); it != path.end(); ++it){
        cout << (*it)->val << "  ";
    }
    cout << endl;
    
}

TreeNode *lowestCommonAncestor2(TreeNode *t1, TreeNode *t2, TreeNode *head) {
    vector<TreeNode *> path1, path2;
    getPathFromRoot(t1, head, path1);
    getPathFromRoot(t2, head, path2);
//    printPath(path1);
//    printPath(path2);

    if (path1.empty() || path2.empty()) {
        return NULL;
    }
    vector<TreeNode *>::iterator it1 = path1.begin();
    vector<TreeNode *>::iterator it2 = path2.begin();
    TreeNode *res = NULL;
    while (it1 != path1.end() && it2 != path2.end() && (*it1 == *it2)) {
        res = *it1;
        ++it1;
        ++it2;
    }
    return res;
}

/*
                4
          2           7
       0     3     5     8
          1           6     9
*/
    
int main(){
    int a[] = {
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9
    };
    init();
    TreeNode *head = NULL;
    create_minimal_tree(head, NULL, a, 0, 9);
    TreeNode *n1 = search(head, 6);
    TreeNode *n2 = search(head, 9);
    cout << n1->val << " " << n2->val << endl;
    TreeNode *ans = lowestCommonAncestor(n1, n2);
    cout << ans->val << endl;
    TreeNode *ans2 = lowestCommonAncestor2(n1, n2, head);
    cout << ans2->val << endl;
    return 0;
}