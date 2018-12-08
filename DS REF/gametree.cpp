#include<iostream>
#include"doublyendedqueue.cpp"
using namespace std;
struct btnode
{
        int score ;
        char name;
        btnode* lchild;
        btnode* rchild;
        btnode()
        {
        lchild=rchild=NULL;
        }
};

btnode* construct(queue<btnode*> queue)
{
        while(queue.l->right!=NULL)
        {
        btnode* b=new btnode;
        b->lchild=queue.dequeue_front();
        b->rchild=queue.dequeue_front();
        b->score=-1;
        b->name=' ';
        queue.enqueue_end(b);
        }
        return(queue.dequeue_front());
}
int max(int x,int y)
{
if(x>=y)
return x;
else
return y;
}
int game(btnode* b)
{
if(b->lchild==NULL&&b->rchild==NULL)
return(b->score);
else if(b->score==-1)
{
b->score=max(game(b->lchild),game(b->rchild));
if(b->lchild->score==b->score)
b->name=b->lchild->name;
else
b->name=b->rchild->name;
return(max(b->lchild->score,b->rchild->score));
}

}
int main()
{
        char ch;
        queue<btnode*> q;
        int points,n,i;
        cout<<"Enter number of players: ";
        cin>>n;
        for(i=0;i<n;i++)
 cout<<"Enter the name and points of "<<i+1<<" player: ";
 cin>>ch;
 cin>>points;
 btnode* node=new btnode;
 node->name=ch;
 node->score=points;
 q.enqueue_end(node);
 }
 btnode* root=construct(q);
 game(root);
 cout<<"The winner is "<<root->name<<" with score= "<<root->score<<endl;



}