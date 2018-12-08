#include<iostream>
#include"queuetemplate.cpp"
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
int insert(btreenode* &b,int k);
int fillnode(btreenode* &b,int k);
int split(btreenode* &b,btreenode* &t,int k);
int insert_in_parent(btreenode* &b,int k);
int insert(btreenode* &b,int k)
{
  static int count=0;
  static btreenode* temp=NULL;
  if(b==NULL)
  {
    b=new btreenode();
    b->key[0]=k;
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
      int k_parent=split(b,temp,k);//The median value to be inserted in parent
      if(count==0)
      {
        btreenode* t=new btreenode;
        t->key[0]=k_parent;
        t->child[0]=b;
        t->child[1]=temp;
        b=t;
      }
      else
      return k_parent;
      }  
      else
      return 0;
    }
    else
    {
      for(i=0;i<2*d;i++)
       {
        if(k==b->key[i]) {cout<<"Element already exists..\n";return 0;}
        if(b->key[i]==-1||k<b->key[i])
       break;
      }
      count++;
      int value=insert(b->child[i],k);
      count--;
      if(value!=0)
      { int flag3;
        flag3=insert_in_parent(b,value);
        if(flag3!=0)
        return flag3;
      }
    } 
  }
}    
int fillnode(btreenode* &b,int k)
{
  int i,j;
  for(i=0;i<2*d;i++)
  {
    if(b->key[i]==-1) break;
  }
  if(i==2*d) return 0;
  if(i==1)
   {
    if(b->key[0]>k) {b->key[1]=b->key[0];b->key[0]=k;}
    else
    b->key[1]=k;
  }
  //cout<<i<<endl;
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
int split(btreenode* &b,btreenode* &t,int k)
{
 t=new btreenode;
 int a[2*d+1],i,j;
 for( i=0,j=0;j<2*d&&i<2*d+1;j++,i++)
 {
    if(k>b->key[j])
        a[i]=b->key[j];
    else
        {
                a[i]=k;
                i++;
        }
  }
        for(i=0;i<d;i++)
        {b->key[i]=a[i];}
        for(i=d;i<2*d;i++)
        b->key[i]=-1;
        for(i=d+1,j=0;i<2*d+1;i++,j++)
        t->key[j]=a[i];

}
int insert_in_parent(btreenode* &b,int k)
{
    int i;
    if(b->key[2*d-1]==-1)//if the parent node is not full
    {
                  for(i=2*d-2;i>=0;i--)
                  {
                   if(b->key[i]==-1)
                   continue;
                   if(b->key[i-1]>k)
                   {
                                  b->key[i+1]=b->key[i];
                                  b->child[i+1]=b->child[i];
                   }
                   else
                   {
                       b->key[i+1]=k;
                       
                       }
                  }
    }
}
void display(btreenode *root)
{
        if(root==NULL)
        return;
        queue<btreenode*> q(20);
        btreenode *temp;
        q.enqueue(root);
        q.enqueue(NULL);
        while(!q.empty())
        {
                temp=q.dequeue();
                if(temp!=NULL)
                {
                        for(int i=0;i<2*d;i++)
                        if(temp->key[i]!=-1)
                                            cout<<temp->key[i]<<" ";
                        else
                                            break;
                        for(int i=0;i<2*d+1;i++)
                        if(temp->child[i]!=NULL)
                        q.enqueue(temp->child[i]);
                        else
                        break;
                }
                else
                if(!q.empty())
                {
                        cout<<endl;
                        q.enqueue(NULL);
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
  while(1)
  {
    cout<<"Enter choice: ";
    cin>>choice;
    switch(choice)
    {
      case 1:{
        cout<<"Enter number: ";
        cin>>num;
        insert(tree,num); 
      }break;
      case 2:display(tree);break;
      case 3:exit(1);break;
    }
  }
  system("pause");
}
