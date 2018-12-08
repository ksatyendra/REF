btreenode* search(btreenode* b,int k)
{   int i;
    if(b!=NULL)
    {
      for(i=0;i<2*d;i++)
       {
        if(k==b->key[i]) return b;
        if(b->key[i]==-1||k<b->key[i])
        break;
      }
      return(search(b->child[i],k));
    }
      return NULL;
}
int max_element(btreenode* b)//gives largest element in a node
{
   int i;
   for(i=0;i<2*d-1;i++)
   {
        if(b->key[i+1]==-1)
        return b->key[i];
    }
    return b->key[2*d-1];  
}
bool underflow(btreenode* b)
{int i;
  for(i=0;i<2*d;i++)
  if(b->key[i]==-1)
  break;
  if(i>=d)
  {// cout<<" NO Undeflow\n";
        return false;
    }
  else
  {//cout<<"Underflow\n";
  return true;
    }
}
bool underflow_after_deletion(btreenode* b)
{int i;
  for(i=0;i<2*d;i++)
  if(b->key[i]==-1)
  break;
  i--;
  if(i>=d) return false;
  else
  return true;
}
void delete_safely(btreenode* &b,int k)
{ if(b->key[1]==-1&&b->key[0]==k)
   {
    //  btreenode* temp=b;
      b=NULL;
      //root=NULL;
    //  delete temp;
      return;
    }
   int i,j;
  for(i=0;i<2*d;i++)
  {
    if(b->key[i]==k)
    b->key[i]=-1;
    }
    for(i=0;i<2*d-1;i++)
    {
    if(b->key[i]==-1)
    {
        if(b->key[i+1]!=-1)
        {
            b->key[i]=b->key[i+1];
            b->key[i+1]=-1;
        }
    }
  }
  //cout<<"deleted"<<endl;

}
bool key_distribution(btreenode* b,int index)
{  //cout<<"checking key redistribution is possible or not :index: "<<index<<endl;
     int flag,i,j;
    if(index<2*d)
    if(b->child[index+1]!=NULL)
    { // cout<<"after checking"<<endl;
    if(!underflow_after_deletion(b->child[index+1]))
    {//cout<<"left\n";
  //  delete_safely(b->child[index],k);
    fillnode(b->child[index],b->key[index]);
    b->child[index]->child[d]=b->child[index+1]->child[0];
    b->key[index]=b->child[index+1]->key[0];
    delete_safely(b->child[index+1],b->key[index]);
    for(i=0;i<2*d;i++)
    {
      b->child[index+1]->child[i]=b->child[index+1]->child[i+1];
      b->child[index+1]->child[i+1]=NULL;
    }
    return true; 
    }
    }
  if(index>0)
  if(b->child[index-1]!=NULL)
    {//cout<<"after left checking"<<endl;
         if(!underflow_after_deletion(b->child[index-1]))
       {//cout<<"right"<<endl;
      // delete_safely(b->child[index],k);
        flag=fillnode(b->child[index],b->key[index-1]);
        for(i=d;i>0;i--)
        b->child[index]->child[i]=b->child[index]->child[i-1];
        for(j=0;j<2*d;j++)
        if(b->child[index-1]->key[j]==-1)
        break;
        b->child[index]->child[0]=b->child[index-1]->child[j];
        b->child[index-1]->child[j]=NULL;
        int max=max_element(b->child[index-1]);
        b->key[index-1]=max;
        delete_safely(b->child[index-1],max);
         return true; 
     }
    }
    //cout<<"kD not possible"<<endl;
    return false;
}
int findmin(btreenode* b)
{ cout<<b->key[0]<<endl;
  if(b->child[0]==NULL)
  return b->key[0];
  else
  return(findmin(b->child[0]));
}
bool combine(btreenode* &b,int index)
{int j;
  if(index<2*d)
  if(b->child[index+1]!=NULL&&underflow_after_deletion(b->child[index+1]))
  {
    //fillnode(b->child[index],b->key[index]);
    b->child[index]->key[d-1]=b->key[index];
    for(j=0;j<d;j++)
    {
      b->child[index]->key[j+d]=b->child[index+1]->key[j];
      b->child[index]->child[j+d]=b->child[index+1]->child[j];
      if(j==d-1)
      b->child[index]->child[2*d]=b->child[index+1]->child[d];
    }
    for(j=index;j<2*d-1;j++)
   { 
      b->key[j]=b->key[j+1];
      b->key[j+1]=-1;
      b->child[j+1]=b->child[j+2];
      b->child[j+2]=NULL;
    }
    return true;
  }
  if(index>0)
  if(b->child[index-1]!=NULL&&underflow_after_deletion(b->child[index-1]))
  {
    b->child[index]->key[2*d-1]=b->child[index]->key[0];
    b->child[index]->child[2*d]=b->child[index]->child[1];
    b->child[index]->child[2*d-1]=b->child[index]->child[0];
    for(j=0;j<d;j++)
    {
      b->child[index]->key[j]=b->child[index-1]->key[j];
      b->child[index]->child[j]=b->child[index-1]->child[j];
      if(j==d-1)
       {
          b->child[index]->key[d]=b->key[index-1];
          b->child[index]->child[d]=b->child[index-1]->child[d];
      }
      }
      if(index==2*d) 
      {
        b->key[index-1]=-1;
        b->child[index-1]=b->child[2*d];
        b->child[2*d]=NULL;
        }
      for(j=index-1;j<2*d-1;j++)
      {
        b->key[j]=b->key[j+1];
        b->key[j+1]=-1;
        b->child[j]=b->child[j+1];
        b->child[j+1]=NULL;
        if(j==2*d-2)
        b->child[j+1]=b->child[2*d];
        }
    return true;
    }
  return false;
  }
  btreenode* root;
int delete_no(btreenode* &b,int k)
{   
    int flag=0,i,value;//flag denoting the search status of element
    if(b!=NULL)
    {
       
        for(i=0;i<2*d;i++)
        {
        if(k==b->key[i]) 
        {
          flag=1; //element found
          break;
        }
        if(b->key[i]==-1||k<b->key[i])
        break;
        }
        if(b==root&&is_leaf(b))
        {
          delete_safely(b,k);
          return 0;
        }
        
      //  cout<<"flag: "<<flag<<i<<endl;
          if(flag==0) // the element is not found in this node
          {
            if(is_leaf(b->child[i])&&underflow_after_deletion(b->child[i]))
            {
                delete_safely(b->child[i],k);
                if(key_distribution(b,i))
                return 0;
                else
                  {
                    if(combine(b,i))
                    {
                    if(b->key[0]==-1)//root
                     { // btreenode* temp=b;
                        b=b->child[0];
                        root=b;
                      //  temp->child[0]=NULL;
                      //  delete temp;
          //              cout<<"changing root"<<endl;
                      }
                    return 0;}
                   
                  }  
            }
            else
            value=delete_no(b->child[i],k);
                  if(b->key[0]==-1)//root
                     { // btreenode* temp=b;
                        b=b->child[0];
                        root=b;
                      //  temp->child[0]=NULL;
                      //  delete temp;
            //            cout<<"changing root"<<endl;
                      }
                      if(value==1)
                      {
                        for(int j=0;j<2*d;j++)
                        if(underflow(b->child[i]))
                        key_distribution(b,i);
                        }
            if(underflow(b->child[i]))
            {
              if(combine(b,i))
              return 0;
              else
              return 1;
            }
        }
        
    }
    if(flag==0)
   {// cout<<"You are mistaken!!!! Element doen't exist...\n"<<endl;
   return 0;}
    else if(is_leaf(b))//checking for leaf node
    {
      if(!underflow_after_deletion(b))
      delete_safely(b,k);
    }
    else//non leaf node
    { //cout<<"non_leaf node"<<b->key[i]<<endl;
      b->key[i]=findmin(b->child[i+1]);
      if(is_leaf(b->child[i+1])&&underflow_after_deletion(b->child[i+1]))
       { delete_safely(b->child[i+1],b->key[i]);
        if(key_distribution(b,i+1))
        return 0;
        else
        {     
          if(combine(b,i))
          return 0;
          else
          return 1;
        }    
      }
      else
      delete_no(b->child[i+1],b->key[i]);
            if(b->key[0]==-1)//root
                     { // btreenode* temp=b;
                        b=b->child[0];
                        root=b;
                      //  temp->child[0]=NULL;
                      //  delete temp;
        //                cout<<"changing root"<<endl;
                      }
      if(underflow(b->child[i+1])) 
      {
         if(combine(b,i))
          return 0;
          else
          return 1;
      }
    } 
}
