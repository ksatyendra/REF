#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<sstream>
using namespace std;

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
struct stu{
    string id;
    string name;
    char offset;
    stu(){ id =""; name=""; offset = '*'; }
};
struct bnode{
    string key;
    char loc;
    bnode * left;
    bnode * right;
    bnode(){
        left = NULL; right = NULL;
    }
};
bnode * newNode(string key, char loc){
    bnode * t = new bnode;
    t->key = key;
    t->loc = loc;
    return t;
}

void display(stu S[], int n){
    for(int i=0; i< n; i++)
        cout<<S[i].id<< " "<<S[i].name<< " "<<S[i].offset<<"\n";
}
void sort(stu S[], int n){
    for(int i=0; i< n; i++)
        for(int j=0; j < n-1-i; j++)
        if(S[j].id > S[j+1].id){
            swap(S[j].id, S[j+1].id);
            swap(S[j].name, S[j+1].name);
            swap(S[j].offset, S[j+1].offset);
        }
}
bnode * createTree(stu S[],int start,int end){
    int i=0;
    if(start > end)
        return NULL;
    i = (start+end)/2;
    cout<<" i = "<<i<<"\n";
    bnode * t = newNode(S[i].id, S[i].offset);
    if(start == end)
        return t;
    t->left = createTree(S , start, i-1);
    t->right = createTree(S , i+1, end);
    return t;
}
void inorder(bnode * root){
    if(root!=NULL){
        inorder(root->left);
        cout<<" ["<<root->key<<","<<root->loc<<"]";
        inorder(root->right);
    }
}
int height(bnode * root){
   if (root==NULL)
       return 0;
    else
      return (1+max(height(root->left),height(root->right)));
}
void PrintTree(bnode * root, int level, ofstream &fout){
  if(root == NULL)
    return;
  if(level == 1){
    fout<<root->key<<"|";
    if(root->left)
        fout<<root->left->loc<<"|";
    if(root->right)
        fout<<root->right->loc<<"|";
    fout<<"#\n";
  }
  else if(level > 1){
    PrintTree(root->left, level-1, fout);
    PrintTree(root->right, level-1, fout);
  }
}
int main(){
    stu S[15]; bnode * root = NULL;
    int k,r,i,n=0; string t,field1,field2;
	ifstream fin("record.txt");
	while(getline(fin, t)){
		if(t.length() < 2)
			continue;
		unpack(t, field1);
		unpack(t, field2);
		S[n].id = field1; S[n].name = field2; S[n].offset =(char)n+48;
		n++;
	}
	fin.close();
    sort(S, n);
    display(S,n);
    int st=0, end = n-1;
    root = createTree(S,st,end);
    //inorder(root);
    ofstream fout("BST.txt");
    k = height(root);
    for(int i=1; i <= k; i++)
        PrintTree(root, i, fout);
    fout.close();
	return 0;
}
