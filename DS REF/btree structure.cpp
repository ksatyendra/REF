#include<iostream>
#include <queue>
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
    { //cout<<"Leaf node"<<endl;
      int flag2=fillnode(b,k);//flag2 gives whether the leaf node has space or not(0)
      if(flag2==0)
      {
      int k_parent=split(b,lchild,rchild,k);//The median value to be inserted in parent
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
      else
      {//cout<<"filled node"<<endl;
      return 0;
      }
    }
    else
    {
      for(i=0;i<2*d;i++)
       {
        if(k==b->key[i]) {cout<<"Element already exists..\n";return 0;}
        if(b->key[i]==-1||k<b->key[i])
        break;
      }
      int value=insert(b->child[i],k);
     // cout<<"Value "<<value<<endl;
       if(value!=0)
      {// cout<<"Inserting in parent"<<endl;  
        int flag3;
        flag3=insert_in_parent(b,lchild,rchild,value);
        if(flag3!=0&&root==b)
          {//cout<<"changing root"<<endl;
          btreenode* t=new btreenode;
          t->key[0]=flag3;
          t->child[0]=lchild;
          t->child[1]=rchild;
          lchild=rchild=NULL;
          b=t;
          root=t;
          return 0;
          }
          if(flag3==0){//cout<<"parent node filled"<<endl;
           return 0;}
          else
          {//cout<<"returning value to parent node"<<endl;
          return flag3;
          }
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
    if(b->key[i]==k) {cout<<"Element already exists..\n";
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
void display2(btreenode* b)
{
  if(b!=NULL)
  {
    for(int i=0;i<2*d+1;i++)
    cout<<b->key[i]<<" ";
  }
  cout<<endl;
} 
int split(btreenode* &b,btreenode* &bt1,btreenode* &bt2,int k)
{
//cout<<"split"<<endl;
btreenode* left=bt1;
btreenode* right=bt2;
bt1=NULL;
bt2=NULL;
bt1=new btreenode;
bt2=new btreenode;
int a[2*d+1],i,j,l,m;//Sorted Array formation
 if(k>b->key[2*d-1])
 {
    a[2*d]=k;
    for(i=0;i<2*d;i++)
    a[i]=b->key[i];
  }
  else
  {
 for(i=0,j=0;i<2*d+1;i++,j++)
 {
    if(b->key[j]<k)
    {
      a[i]=b->key[j];
    }
    else
      {
       a[i]=k;//i &j is the index at which k is inserted
       break;
      } 
  }
  for(m=j;m<2*d;m++)
  {
    a[m+1]=b->key[m];
  }
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
      /*for(i=0;i<2*d+2;i++)
      display2(ptrs[i]);
      cout<<"display over"<<endl;*/
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
int insert_in_parent(btreenode* &b,btreenode* &t,btreenode* &r,int k)
{
    int i;
    if(b->key[2*d-1]==-1)//if the parent node is not full
    {//cout<<"parent node not full"<<endl;
                  for(i=2*d-1;i>0;i--)
                  {
                   if(b->key[i-1]==-1)
                   continue;
                   if(b->key[i-1]>k)
                   {//cout<<"shifting"<<endl;
                                  b->key[i]=b->key[i-1];
                                  b->child[i+1]=b->child[i];
                   }
                   else
                   {//cout<<"putting key"<<endl;
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
int main()
{
  btreenode* tree=NULL;
  int choice,i,num;
  cout<<"Enter d:";
  cin>>d;
  choice=1;
  while(1)
  {
    //cout<<"Enter choice: ";
    //cin>>choice;
    switch(choice)
    {
      case 1:{
        //cout<<"Enter number: ";
        //cin>>num;
        num=rand()%100;
        cout<<"**********n="<<num<<"*******\n";
        insert(tree,num); 
        display(tree);
        system("pause");
        cout<<"--------------------------------------------------------\n";
      }break;
      case 2:display(tree);break;
      case 3:exit(1);break;
    }
  }
  system("pause");
}
