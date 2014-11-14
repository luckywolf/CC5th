/*
Given a directed graph, design an algorithm to find out whether 
there is a route between two nodes.
*/
#include <iostream>
#include <queue>
#include <unordered_set>
#include <cstring>
#include <cstdio>
using namespace std;

//  Use adjacent matrix
bool hasRoute(int src, int dst, bool g[][5], int n){
    queue<int> q;
    unordered_set<int> visited;
    q.push(src);
    visited.insert(src);
    while(!q.empty()){
        int current = q.front();
        q.pop();
        if(current == dst) {
            return true;
        }
        for(int i = 0; i < n; ++i)
            if(g[current][i] && visited.find(i) == visited.end()){
                q.push(i);
                visited.insert(i);
            }
    }
    return false;
}

struct adjListNode {
    int label;
    adjListNode *next;
    adjListNode(int x): label(x), next(NULL) {}
};

//struct adjList {
//    adjListNode *head;
//    adjList(): head(NULL) {}
//};

class graph {
public:
    graph(int nodeNumber): v(nodeNumber) {
//        arr = new adjList[nodeNumber];
        arr = new adjListNode*[nodeNumber]();
    }
    
    ~graph() {
        for (int i = 0; i < v; ++i) {
//            adjListNode *p = arr[i].head;
            adjListNode *p = arr[i];
            while (p) {
                adjListNode *del = p;
                p = p->next;
                delete del;
            }
        }
        delete[] arr;
    }
    
    void addEdge(int src, int dst) {
        adjListNode *newNode = new adjListNode(dst);
//        newNode->next = arr[src].head;
//        arr[src].head = newNode;
        newNode->next = arr[src];
        arr[src] = newNode;
    }
    
    void printGraph() {
        for (int i = 0; i < v; ++i) {
//            adjListNode* p = arr[v].head;
            adjListNode* p = arr[v];
            cout << endl << "Adjacent list of vertex" << v << endl << "  head ";
            while (p) {
                cout << "-> " << p->label;
                p = p->next;
            }
        }
        cout << endl;
    }
    
//    adjList *getArr(){
    adjListNode **getArr(){
        return arr;
    }

private:
    int v;
//    adjList *arr;
    adjListNode **arr;
};

// Use adjacent list
bool hasRoute2(int src, int dst, graph& g){
    queue<int> q;
    unordered_set<int> visited;
    q.push(src);
    visited.insert(src);
    while(!q.empty()){
        int current = q.front();
        q.pop();
        if(current == dst) {
            return true;
        }
//        adjListNode *ptr = g.getArr()[current].head;
        adjListNode *ptr = g.getArr()[current];
        while (ptr) {
            if(visited.find(ptr->label) == visited.end()){
                q.push(ptr->label);
                visited.insert(ptr->label);
            }
            ptr = ptr->next;
        }
    }
    return false;
}



int main(){
    int n = 5;
    /*
             4 ------------
             ^ ^           |
             | |           |
             |   |         |
             |      |      ^
     0 ----> 1 ---> 2 ---> 3
     |              ^
     |              |
     |---------------
     
    */
    bool g[5][5] = {
        { false, true,  true,  false, false },
        { false, false, true,  false, true },
        { false, false, false, true,  true },
        { false, false, false, false, false },
        { false, false, false, true,  false },
    };
    cout << hasRoute(0, 4, g, 5) << endl;
    
    graph g2(5);
    g2.addEdge(0, 1);
    g2.addEdge(0, 2);
    g2.addEdge(1, 2);
    g2.addEdge(1, 4);
    g2.addEdge(2, 3);
    g2.addEdge(2, 4);
    g2.addEdge(4, 3);
    cout << hasRoute2(0, 4, g2) << endl;
    return 0;
}
