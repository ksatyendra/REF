#include<iostream>
#include<stdlib.h>
#include<queue>
#define MAX 25

using namespace std;
//tree declaration
struct btnode
{
    int data;
    btnode *lchild;
    btnode *rchild;
};
typedef btnode * bptr;
int isLeaf(bptr root)
{
    if(root->lchild==NULL && root->rchild==NULL)
        return 1;
    return 0;
}
int minTwo(int a,int b)
{
    if(a!=-1 && b!=-1){
        if(a<b){
            b = -1;
            return a;
        }
        else{
            a = -1;
            return b;
        }
    }
    else if(a!=-1)
        return a;
    else if(b!=-1)
        return b;
    return -1;
}
void makeQueue(bptr root,queue<bptr> &q,int );
bptr new_btnode()
{
    bptr t;
    t = new btnode;
    cout<<"\nEnter Node data : "; cin>>t->data;
    t->lchild = t->rchild = NULL;
    return t;
}
void createNode(queue<bptr> &q)
{
    int ans=1; bptr t;
    while(ans)
    {
        t = new_btnode();
        q.push(t);
        cout<<"\nWanna Continue (1/0) ? ";
        cin>>ans;
    }
}
bptr createTree(bptr r,bptr l)
{
    bptr t;
    t = new btnode;
    t->data = minTwo(r->data,l->data);
    t->lchild = l; t->rchild = r;
    return t;
}
bptr dequeue(queue<bptr> &Q)
{
    bptr t = Q.front();
    Q.pop();
    return t;
}
int main()
{
    bptr root,t; queue<bptr> Q;
    createNode(Q);
    //Q.display();
    cout<<"\n\n=======Displaying In Sorted Order======\n\n";
    while(root->data!=-1)
    {
        while(Q.front()!=Q.back())
        {
            root = createTree(dequeue(Q),dequeue(Q));
            Q.push(root);
        }
        root = dequeue(Q);
        if(root->data!=-1)
        cout<<"  "<<root->data;
        makeQueue(root,Q,root->data);
    }
    cout<<"\n\n=======================================\n";
    return 0;
}
void makeQueue(bptr root,queue<bptr> &q,int k)
{
    if(root!=NULL)
    {
        makeQueue(root->lchild,q,k);
        if(isLeaf(root))
        {
            if(root->data == k)
                root->data = -1;
            q.push(root);
        }
        makeQueue(root->rchild,q,k);
    }
}
