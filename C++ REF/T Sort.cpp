#include<iostream>
#include<stdlib.h>
#include<queue>
#include<list>
using namespace std;

struct btnode{
    int data;
    btnode *lchild;
    btnode *rchild;
};
typedef btnode * bptr;
//---------------------------------------------
bptr new_btnode(){
    bptr t;
    t = new btnode;
    cout << "\nEnter Node data : "; cin>>t->data;
    t->lchild = t->rchild = NULL;
    return t;
}
//----------------------------------------------
void createNode(queue<bptr> &q){
    int ans=1; bptr t;
    while(ans){
        t = new_btnode();
        q.push(t);
        cout << "\nWanna Continue (1/0) ? ";
        cin>>ans;
    }
}
//-----------------------------------------------
bptr createTree(bptr r,bptr l){
    bptr t;
    t = new btnode;
    t->data = min(r->data,l->data);
    t->lchild = l; t->rchild = r;
    return t;
}
//-----------------------------------------------
bptr dequeue(queue<bptr> &Q){
    bptr t = Q.front();
    Q.pop();
    return t;
}
//-----------------------------------------------
int frontItem(list<int> &L){
    int tmp = L.front();
    L.pop_front();
    return tmp;
}
//-----------------------------------------------
bool allListEmpty(list<int> L[], int n){
    for(int i=0; i<n; i++){
        if(!L[i].empty())
            return false;
    }
    return true;
}
//-----------------------------------------------
int getKey(list<int> L[], int n, int in){
    if(in >= n)
        return -1;
    else{
        return frontItem(L[in]);
    }
}
//===============================================
int main(){
    bptr root,t; queue<bptr> Q;
    int N,k,ans=1;
    cout << "\nEnter No. of Lists : "; cin>>N;
    list<int> L[N];
    for(int i=0; i<N; i++){
        while(1){
            cout << "Enter " << i+1 << " List Data : "; cin>>k;
            if(k==0) break;
            L[i].push_back(k);
        }
    }
    cout << "\n\n=======Displaying In Sorted Order======\n\n";
    while(1){

        while( Q.front() != Q.back() ){
            root = createTree(dequeue(Q),dequeue(Q));
            Q.push(root);
        }
        root = dequeue(Q);
        cout << root->data << " ";
        Q.pop();
    }
    cout << "\n\n=======================================\n";
    return 0;
}
