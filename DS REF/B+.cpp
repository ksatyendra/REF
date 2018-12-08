#include<iostream>
#include<queue>
#include<cstdlib>
#include<time.h>
using namespace std;
int d;
struct btreenode
{
  int *key;
  btreenode* *child;
  btreenode()
  {
    key=new int[2*d];
    child=new btreenode*[2*d+1];
    for(int i=0;i<2*d;i++)
    {
      key[i]=-1;
    }
    for(int i=0;i<2*d+1;i++)
    {
      child[i]=NULL;
    }
  }
};
btreenode *lchild=NULL,*rchild=NULL;
int insert(btreenode* &b,int k);
int fillnode(btreenode* &b,int k);
int split(btreenode* &b,btreenode* &t,btreenode* &r,int k);
int insert_in_parent(btreenode* &b,btreenode* &t,btreenode* &r,int k);
int split_leaf(btreenode* &b,btreenode* &bt1,btreenode* &bt2,int k);
int insert(btreenode* &b,int k)
{  static btreenode* root=NULL;
  if(b==NULL)
  {
    b=new btreenode();
    b->key[0]=k;
    root=b;
  }
  else
  { //checking whether it is leaf or not
    int i,flag=0;
    for(i=0;i<2*d+1;i++)
    {
    if(b->child[i]!=NULL)
    {flag=1;break;}
    }
    if(flag==0)
    {
      int flag2=fillnode(b,k);//flag2 gives whether the leaf node has space or not(0)
      if(flag2==0)
      {
      int k_parent=split_leaf(b,lchild,rchild,k);//The median value to be inserted in parent
      if(root==b)
      {
        btreenode* t=new btreenode;
        t->key[0]=k_parent;
        t->child[0]=lchild;
        t->child[1]=rchild;
        lchild=rchild=NULL;
        b=t;
        root=t;
      }
      else
      return k_parent;
      }
      else return 0;
    }
    else
    {
      for(i=0;i<2*d;i++)
       {
        if(k==b->key[i]) {//cout<<"Element already exists..\n";
            return 0;}
        if(b->key[i]==-1||k<b->key[i])
        break;
      }
      int value=insert(b->child[i],k);
       if(value!=0)
        {
        int flag3;
        flag3=insert_in_parent(b,lchild,rchild,value);
          if(flag3!=0&&root==b)
          {
          btreenode* t=new btreenode;
          t->key[0]=flag3;
          t->child[0]=lchild;
          t->child[1]=rchild;
          lchild=rchild=NULL;
          b=t;
          root=t;
          return 0;
          }
          if(flag3==0) return 0;
          else return flag3;
      }
      else
      return 0;
    }
  }
}
int fillnode(btreenode* &b,int k)
{
  int i,j;
  for(i=0;i<2*d;i++)
  {
    if(b->key[i]==k) {//cout<<"Element already exists..\n";
        return 1;}
    if(b->key[i]==-1) break;
  }
  if(i==2*d) return 0;
   for(j=i-1;j>=0;j--)
   {
                      if(k>b->key[j])
                      {
                                     b->key[j+1]=k;
                                     return 1;
                      }
    else
    {
      b->key[j+1]=b->key[j];
      b->key[j]=k;
    }
  }
  return 1;
}
int split(btreenode* &b,btreenode* &bt1,btreenode* &bt2,int k)
{
btreenode* left=bt1;
btreenode* right=bt2;
bt1=NULL;
bt2=NULL;
bt1=new btreenode;
bt2=new btreenode;
int a[2*d+1],i,j,l,m;//Sorted Array formation
  for(i=0;i<2*d;i++)
  a[i]=b->key[i];
  a[2*d]=k;
 for(i=2*d;i>0;i--)
  {
    if(a[i]<a[i-1])
    swap(a[i],a[i-1]);
  }
  btreenode* ptrs[2*d+2];
  for(i=0,j=0;i<2*d+1;i++,j++)
  {
    if(a[i]!=k)
    ptrs[j]=b->child[i];
    else
    {
      ptrs[j]=left;
      ptrs[j+1]=right;
      j++;
    }
  }
        for(l=0;l<d;l++)
        {
          bt1->key[l]=a[l];
          bt1->child[l]=ptrs[l];
          if(l==d-1) bt1->child[l+1]=ptrs[l+1];
        }
        for(i=d+1,j=0;i<2*d+1;i++,j++)
        {
          bt2->key[j]=a[i];
          bt2->child[j]=ptrs[i];
          if(i==2*d) bt2->child[j+1]=ptrs[2*d+1];
        }
      return a[d];

}
int split_leaf(btreenode* &b,btreenode* &bt1,btreenode* &bt2,int k)
{

bt1=NULL;
bt2=NULL;
bt1=new btreenode;
bt2=new btreenode;
int a[2*d+1],i,j,l,m;//Sorted Array formation
  for(i=0;i<2*d;i++)
  a[i]=b->key[i];
  a[2*d]=k;
 for(i=2*d;i>0;i--)
  {
    if(a[i]<a[i-1])
    swap(a[i],a[i-1]);
  }
        for(l=0;l<d+1;l++)
        {
          bt1->key[l]=a[l];
        }
        for(i=d+1,j=0;i<2*d+1;i++,j++)
        {
          bt2->key[j]=a[i];
        }
      return a[d];

}
int insert_in_parent(btreenode* &b,btreenode* &t,btreenode* &r,int k)
{
    int i;
    if(b->key[2*d-1]==-1)//if the parent node is not full
    {
                  for(i=2*d-1;i>0;i--)
                  {
                   if(b->key[i-1]==-1)
                   continue;
                   if(b->key[i-1]>k)
                   {
                                  b->key[i]=b->key[i-1];
                                  b->child[i+1]=b->child[i];
                   }
                   else
                   {
                       b->key[i]=k;
                       b->child[i]=lchild;
                       b->child[i+1]=rchild;
                       lchild=rchild=NULL;
                       break;
                  }
                  }
                  if(i==0)
                  {
                    b->key[i]=k;
                       b->child[i]=lchild;
                       b->child[i+1]=rchild;
                       lchild=rchild=NULL;
                  }
                  return 0;
    }
    else
    {
      return(split(b,lchild,rchild,k));
    }

}
void display(btreenode *root)
{
        if(root==NULL)
        return;
        queue<btreenode*> q;
        btreenode *temp;
        q.push(root);
        q.push(NULL);
        while(!q.empty())
        {
                temp=q.front();
                q.pop();
                if(temp!=NULL)
                {
                        for(int i=0;i<2*d;i++)
                        if(temp->key[i]!=-1)
                                            cout<<temp->key[i]<<" ";
                        else
                                            break;
                        cout<<"  ";
                        for(int i=0;i<2*d+1;i++)
                        if(temp->child[i]!=NULL)
                        q.push(temp->child[i]);
                        else
                        break;
                }
                else
                if(!q.empty())
                {
                        cout<<endl<<endl;
                        q.push(NULL);
                }
        }
cout<<endl;
}
//clock_t start=clock();
int main()
{
  btreenode* tree=NULL;
  int choice,i,num;
  cout<<"Enter d:";
  //cin>>d;
  d=2;
  choice=1;
  while(1)
  {
    //cout<<"Enter choice: ";
    //cin>>choice;
    switch(choice)
    {
      case 1:{
       // cout<<"Enter number: ";
     // cin>>num;
       num=rand()%500;
        cout<<"**********n="<<num<<"*******\n";
        insert(tree,num);
        display(tree);
        system("pause");
        cout<<"--------------------------------------------------------\n";
      }break;
      case 2:display(tree);break;
      case 3:exit(1);break;
    }
 //   i++;
  }
 // cout<<(double)(clock()-start)/(double)CLOCKS_PER_SEC<<"seconds"<<endl;
 system("pause");
}
