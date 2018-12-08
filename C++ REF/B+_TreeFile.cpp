#include<bits/stdc++.h>
#define d 1

using namespace std;
struct MyType{
    int key;
    int in;
};
typedef struct bdnode
{
	int count, index;
	MyType *data;
	bdnode **ptrs;
	bdnode()
	{
		int i;
		count = 0; index = -1;
		data = new MyType[2*d+1];
		ptrs = new bdnode * [2*d+2];
		for( i=0; i<=2*d; i++)
			data[i].key = data[i].in = -1;
		for(i =0; i<=2*d+1; i++)
			ptrs[i] = NULL;
	}
}* bdptr;
bdptr head;
int searchLoc(bdptr root, int key);
void display(bdptr root);  //In-order display function
int isLeaf(bdptr root);    // return true if any node is leaf node
bdptr insert(bdptr root, int k, int in);  // Insert a key into the tree
bdptr adjustNode(bdptr root,bdptr parent);  // Adding a key to leaf node & sort elements
bdptr splitNode(bdptr root);
void unpack(string &s,string &field){
	int t = s.find("|");
	field = s.substr(0, t);
	s.erase(0, t+1);
}
int ToInt(string s){
	int t;
	istringstream convert(s);
	t = ((convert>>t) ? t : -1);
	return t;
}
bool compare(const MyType &a, const MyType &b){
    return (a.key < b.key);
}
int getHeight(bdptr T)
{
   if(T==NULL)
   return 0;
   return getHeight(T->ptrs[0])+1;
}
void numLevel(bdptr T,int level)
{
	if(T==NULL)
        return;
	if(level ==0)
	{
		cout<<"[";
		for(int i=0; i<T->count; i++){
            cout<<T->data[i].key<<","<<T->data[i].in<<" ";
		}
		cout<<"]";
	}
	else
	{
		for(int j=0;j<=T->count;j++)
		numLevel(T->ptrs[j],level-1);
	}
}
void writeFile(bdptr T, int level, ofstream &fout){
    if(T==NULL)
        return;
    if(level == 0){
        if(T->ptrs[0] == NULL)
        { fout<<"-1 "; cout<<"-1 ";}
        else { fout<<T->ptrs[0]->index<<" "; cout<<T->ptrs[0]->index<<" "; }
        fout<<T->data[0].key<<" "<<T->data[0].in<<" "; cout<<T->data[0].key<<" "<<T->data[0].in<<" ";
        if(T->ptrs[1] == NULL)
        { fout<<"-1 "; cout<<"-1 ";}
        else { fout<<T->ptrs[1]->index<<" "; cout<<T->ptrs[1]->index<<" "; }
        fout<<T->data[1].key<<" "<<T->data[1].in<<" ";  cout<<T->data[1].key<<" "<<T->data[1].in<<" ";
        if(T->ptrs[2] == NULL)
        { fout<<"-1 "; cout<<"-1 ";}
        else { fout<<T->ptrs[1]->index<<" "; cout<<T->ptrs[1]->index<<" "; }
        fout<<"\n"; cout<<"\n";
    }
    else{
        for(int j=0;j<=T->count;j++)
            writeFile(T->ptrs[j],level-1, fout);
    }
}
void print(bdptr T)
{
	cout<<"\n\n Level Order Traversal \n";
	int h=getHeight(T);
	numLevel(T,h-1);
	cout<<"\n\n";
    ofstream fout("index.txt");
    writeFile(T, h-1, fout);
    fout.close();
}
//===============================Main function============================================
int main()
{
	bdptr root = NULL;  int k; vector<int> V; ifstream fin("record.txt"); string s,key;
	k=1; int i=0;
	while(getline(fin,s))
	{
		if(s.length() < 3) continue;
		unpack(s, key);
		k = ToInt(key);
		cout<<k<<"\n";
        V.push_back(k);
		root = insert(root, k, i++);
	}
	fin.close();
	cout<<"\n\nCreating Index File......\n";
        print(root);
	return 0;
}
//====================================
//------Functions Definition----------
//====================================
void display(bdptr root)
{
	if(root)
	{
	    int i;
	    for(i=0; i < root->count; i++)
        {
            display(root->ptrs[i]);
            cout<<" "<<root->data[i].key<<", "<<root->data[i].in<<" ";
        }
        display(root->ptrs[i]);
	}
}
//--------------------------------------
int isLeaf(bdptr root)
{
	for(int i=0; i<= root->count ; i++)
		if(root->ptrs[i]!= NULL)
			return 0;
	return 1;
}
//=========================================
int searchLoc(bdptr root, int key)
{
	int i=0;
	while(i < root->count && root->data[i].key < key )
		++i;
	return i;
}
//-------------------------------------------
bdptr insert(bdptr root, int key, int in)
{
	int i; bdptr parent;
	if(!root)
	{
		root = new bdnode;
		root->data[0].key = key;
		root->data[0].in = in;
		root->count++;
		return root;
	}
	else
	{
		if(isLeaf(root))
		{
			if(root->count != 2*d)
			{
			    root->data[root->count].in = in;
				root->data[root->count++].key = key;
				sort(root->data, root->data+root->count, compare);
				return root;
			}
			else
			{
				root->data[root->count].in = in;
				root->data[root->count++].key = key;
				sort(root->data, root->data+root->count, compare);
				return splitNode(root);
			}
		}
		else
		{
			int i = searchLoc(root, key);
			//cout<<"\ni = "<<i;
			parent = insert(root->ptrs[i], key, in);
			if(parent->count == 1 && parent!= root->ptrs[i])
			{
				//cout<<"\nAdjusting";
				root = adjustNode(root,parent);
			}
			else
			{
				//cout<<"\nNothing";
				root->ptrs[i] = parent;
			}
			if(root->count > 2*d)
				root = splitNode(root);
			return root;
		}
	}
}
//=========================================
bdptr adjustNode(bdptr root,bdptr parent)
{
	bdptr temp; int i=-1;
	temp = new bdnode;
	//cout<<"\n"<<parent->data[0].key<<"\n"<<parent->data[0].in;
	while(root->data[++i].key < parent->data[0].key && i < root->count )
	{
		temp->data[i].key = root->data[i].key;
		temp->data[i].in = root->data[i].in;
		temp->ptrs[i] = root->ptrs[i];
	}
	temp->data[i].key = parent->data[0].key;
    temp->data[i].in = parent->data[0].in;
	temp->ptrs[i] = parent->ptrs[0];
	temp->ptrs[++i] = parent->ptrs[1];
	for(; i<root->count+1; ++i)
	{
		temp->data[i].key = root->data[i-1].key;
		temp->data[i].in = root->data[i-1].in;
		temp->ptrs[i+1] = root->ptrs[i];
	}
	temp->count = root->count+1;
	return temp;
}
//==========================================
bdptr splitNode(bdptr root)
{
	bdptr ch1,ch2,par; int i,c=0, k=0;
	par = new bdnode;
	ch1 = new bdnode; ch2 = new bdnode;
	if(isLeaf(root)){
        for(i=0; i < root->count; i++)
        {
            if(i < d)
            {
                ch1->data[ch1->count].in = root->data[i].in;
                ch1->data[ch1->count++].key = root->data[i].key;
            }
            else if(i >= d)
            {
                ch2->data[ch2->count].in = root->data[i].in;
                ch2->data[ch2->count++].key = root->data[i].key;
            }
            if(i==d){
                par->data[par->count].in = root->data[i].in;
                par->data[par->count++].key = root->data[i].key;
            }
        }
	}
	else{
        for(i=0; i < root->count; i++)
        {
            if(i < d)
            {
                ch1->data[ch1->count].in = root->data[i].in;
                ch1->data[ch1->count++].key = root->data[i].key;
            }
            else if(i > d)
            {
                ch2->data[ch2->count].in = root->data[i].in;
                ch2->data[ch2->count++].key = root->data[i].key;
            }
            else{
                par->data[par->count].in = root->data[i].in;
                par->data[par->count++].key = root->data[i].key;
            }
        }
	}
	for(i=0; i<=root->count; i++)
	{
		if(i<=d)
			ch1->ptrs[c++] = root->ptrs[i];
		else
			ch2->ptrs[k++] = root->ptrs[i];
	}
	par->ptrs[0] = ch1;
	par->ptrs[1] = ch2;
	return par;
}
