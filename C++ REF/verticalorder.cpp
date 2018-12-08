#include<iostream>
using namespace std;
int MAX=0,MIN=0;
struct bstnode
{
    bstnode *left;    int data;    int loc;    bstnode *right;
};
struct topview
{
    int tag;    int loc;    int data[10];
};
struct Queue
{
    int Front;    int Rear;    int Size;    bstnode *Elements[50];
};
int QueueIsFull(Queue *Q)
{
    if((Q->Rear+1)%Q->Size==Q->Front)        return 1;
    return 0;
}
int isEmptyQueued(Queue *Q)
{
    if((Q->Rear==-1)&&Q->Front==-1)        return 1;
    return 0;
}
void EnQueued(Queue *Q,bstnode *k)
{
    if(QueueIsFull(Q))        cout<<"Queue is Full!!!";
    else
    {
        if(Q->Front==-1)
        {
            Q->Front=0;      Q->Rear=0;
        }
        else
        {
            Q->Rear=(Q->Rear+1)%Q->Size;
        }
        Q->Elements[Q->Rear]=k;
    }
}
bstnode *DeQueued(Queue *Q)
{
    bstnode *t;
    if(isEmptyQueued(Q))        cout<"Queue is Empty!!!";
    else
        {
            if(Q->Front==Q->Rear)
            {
                t=Q->Elements[Q->Front];  Q->Front=-1;  Q->Rear=-1;
            }
            else{
                t=Q->Elements[Q->Front];     Q->Front=(Q->Front+1)%Q->Size;
            }
        }
        return t;
}
void insertNode(bstnode **T,int k,int &i)
{
    if((*T)==NULL)
    {
        *T=new bstnode;	 (*T)->data=k;        (*T)->loc=i;
        if(i>MAX)            MAX=i;
        if(i<MIN)            MIN=i;
        (*T)->left=(*T)->right=NULL;
    }
    else if(k<(*T)->data)
        {i=(*T)->loc-1;insertNode(&((*T)->left),k,i);}
    else
        {i=(*T)->loc+1;insertNode(&((*T)->right),k,i);}
}
void TopView(bstnode *B,topview t[],int Size)
{
for(int i=0;i<Size;i++)
{
    t[i].loc=MIN;
    for(int k=0;k<5;k++)
    t[i].data[k]=0;
    MIN++;    //if(MIN==MAX)  break;
}
    Queue *Q;    Q=new Queue;
    Q->Front=-1;  Q->Rear=-1; Q->Size=20;
    bstnode *temp,*null,*p;    null=new bstnode;
    if(!B)        cout<<"error!!";
    EnQueued(Q,B);
    while(!isEmptyQueued(Q))
    {
        int i,k=0;        temp=DeQueued(Q);
        for( i=0;i<Size;i++)
            if(t[i].loc==temp->loc)  break;
            while(t[i].data[k]!=0)  k++;
          t[i].data[k]=temp->data;
            if(temp->left) EnQueued(Q,temp->left);
            if(temp->right) EnQueued(Q,temp->right);
        }
        for(int i=0;i<Size;i++)
            {   int k=0;
                while(t[i].data[k]!=0) cout<<t[i].data[k++]<<"  "; 
				cout<<endl;
            }
    }
int main()
{
    bstnode *B;    B=NULL;int d;int i=0,j=0;char ch='y';
     while(ch=='y')
    {
        cout<<"Enter data:";      cin>>d;
        insertNode(&B,d,i);
        cout<<"Want to add more nodes<y/n>";        cin>>ch;j++;
    }
topview t[j];  //j=MAX-MIN+1;
TopView(B,t,j);
}
