#include<iostream>
#include<queue>
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
bool key_redistribution(btreenode* b,int index,int k);
bool is_node_empty(btreenode* b);
bool is_leaf(btreenode* b)//checking whether it is leaf or not
{ if(b==NULL) return false;
    for(int i=0;i<2*d+1;i++)
    {
    if(b->child[i]!=NULL)
    return false;
    }
    return true;
}
int insert(btreenode* &b,int k)
{ if(k==-1)
{//cout<<"-1 inserting"<<endl;
    return 0;}
     static btreenode* root=NULL;
  if(b==NULL)
  {
    b=new btreenode();
    b->key[0]=k;
    root=b;  
  }
  else
  { int i,value;
    if(is_leaf(b)&&root==b)
    { 
      int flag=fillnode(b,k);//flag2 gives whether the leaf node has space or not(0)
      if(flag==0)
      {  
      int k_parent=split(b,lchild,rchild,k);//The median value to be inserted in parent
        btreenode* t=new btreenode;
        t->key[0]=k_parent;
        t->child[0]=lchild;
        t->child[1]=rchild;
        lchild=rchild=NULL;
        b=t;
        root=t;
      }  
      else return 0;
    }
    else if(is_leaf(b))
    {//cout<<"leaf node"<<endl;
      int flag=fillnode(b,k);
      if(flag==0) 
      return(split(b,lchild,rchild,k));
      else
      return 0;  
    }
    else
    {
      for(i=0;i<2*d;i++)
       {
        if(k==b->key[i]) {cout<<k<<" checking Element already exists..\n";return 0;}
        if(b->key[i]==-1||k<b->key[i])
        break;
      }
      if(is_leaf(b->child[i]))
      {//cout<<"LEAF NODE"<<endl;
        int flag=fillnode(b->child[i],k);
        if(flag==0)//leaf node is full
        {
          if(key_redistribution(b,i,k))
          {//cout<<"00000000000\n";
          return 0;}
          else
          {//cout<<"moved to split"<<endl;
          value=insert(b->child[i],k);}
        }
        else
        return 0;
      }  
      else
      value=insert(b->child[i],k);
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
          //cout<<"parent root changed"<<endl;
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
bool is_node_empty(btreenode* b)
{
  if(b->key[2*d-1]==-1)
  return true;
  else
  return false;
}  
bool key_redistribution(btreenode* b,int index,int k)
{//cout<<"checking key redistribution is possible or not :index: "<<index<<endl;
 int flag;
  if(index<2*d)
  if(b->child[index+1]!=NULL)
  {  
    if(is_node_empty(b->child[index+1]))
    {//cout<<"left\n";
    flag=fillnode(b->child[index+1],b->key[index]);
    if(flag==1)
    {
    int a[2*d+1],i,j;//Sorted Array formation
    for(i=0;i<2*d;i++)
    a[i]=b->child[index]->key[i];
    a[2*d]=k;
    for(i=2*d;i>0;i--)
    {
    if(a[i]<a[i-1])
    swap(a[i],a[i-1]);
    }
    for(i=0;i<2*d;i++)
    b->child[index]->key[i]=a[i];
    b->key[index]=a[2*d];
    }
    return true; 
    }
  }
  if(index>0)
  if(b->child[index-1]!=NULL)
    { if(is_node_empty(b->child[index-1]))
       {//cout<<"entered"<<endl;
      int flag=fillnode(b->child[index-1],b->key[index-1]);
     if(flag==1)
    {
     int a[2*d+1],i,j;//Sorted Array formation
    for(i=0;i<2*d;i++)
    a[i]=b->child[index]->key[i];
    a[2*d]=k;
    for(i=2*d;i>0;i--)
    {
    if(a[i]<a[i-1])
    swap(a[i],a[i-1]);
    }
    for(i=1,j=0;i<2*d+1;i++,j++)
    b->child[index]->key[j]=a[i];
    b->key[index-1]=a[0];
  }
    return true; 
  }
  }

 //cout<<"key distribution not possible"<<endl;
  return false; 
}
int fillnode(btreenode* &b,int k)
{
  int i,j;
  for(i=0;i<2*d;i++)
  {
      if(b->key[i]==k) {cout<<k<<" while filling Element already exists..\n";return 1;}
    if(b->key[i]==-1) break;
  }
  if(i==2*d) return 0;
   for(j=i-1;j>=0;j--)
   {
                      if(k>b->key[j])
                      {
                                     b->key[j+1]=k;
                                   // cout<<"filled\n";
                                    return 1;
                      }
    else
    {
      b->key[j+1]=b->key[j];
      b->key[j]=k;
    }
  }
 // cout<<"filled"<<endl;
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
          //cout<<"a[i]"<<a[i]<<endl;
          bt2->child[j]=ptrs[i];
          if(i==2*d) bt2->child[j+1]=ptrs[2*d+1];
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
                       // if(temp->key[i]!=-1)
                                            cout<<temp->key[i]<<" ";
                        //else
                           //                break;
                        cout<<"/";
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
clock_t start=clock();
#include"deletion_btree.cpp"
int main()
{
  btreenode* tree=NULL;
  int choice,i=0,num;
  cout<<"Enter d:";
  cin>>d;
 // d=2;
 // choice=1;
 // while(i<5000000)
 while(1)
  {
    cout<<"Enter choice: ";
   cin>>choice;
    switch(choice)
    {
      case 1:{
        //cout<<"Enter numbers: ";
        //cin>>num;
      //num=rand()%500;
        //cout<<"**********n="<<num<<"*******\n";
       cout<<"Enter numbers: \n";
      cin>>num;
        while(num!=-1)
      {
        insert(tree,num);
        cin>>num;
      }   
        display(tree);
        //display(tree);
        //system("pause");
     //   cout<<"--------------------------------------------------------\n";
      }break;
      case 2:display(tree);break;
      case 3:exit(1);break;
      case 4:{cout<<"Enter no to be deleted: ";
                cin>>num;
                 while(num!=-1)
                   {root=tree;
                     delete_no(tree,num);
                     cin>>num;
                     display(tree);
                     }   
                 //  display(tree);
            }
    }
  //  i++;
  }
  cout<<(double)(clock()-start)/(double)CLOCKS_PER_SEC<<"seconds"<<endl;
 system("pause");
}

