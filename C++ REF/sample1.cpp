#include <bits/stdc++.h>
using namespace std;

typedef struct bnode{
    int key;
    int loc;
    bnode * left;
    bnode * right;
    bnode(){
        loc = 0; left = right = NULL;
    }
}* bptr;

bptr insert(bptr root, int key, int loc){
    if(!root){
        root = new bnode;
        root->key = key;
        root->loc = loc;
        return root;
    }
    if(root->key > key)
        root->left = insert(root->left , key, loc-1);
    else if(root->key < key)
        root->right = insert(root->right , key, loc+1);
    return root;
}
void inorder(bptr root){
    if(!root) return;
    inorder(root->left);
    printf(" %d,%d ", root->key, root->loc);
    inorder(root->right);
}
void topview(bptr root,vector<int> &V, map<int, bool> &M){
    if(!root) return;
    topview(root->left, V, M);
    if(!M[root->loc]){
        V.push_back(root->key);
        M[root->loc] = true;
    }
    topview(root->right,V, M);
}
void min_node(bptr root, int &min){
    if(!root) return;
    min_node(root->left, min);
    if(root->loc < min)
        min = root->loc;
    min_node(root->right, min);
}
void max_node(bptr root, int &max){
    if(!root) return;
    max_node(root->left, max);
    if(root->loc > max)
        max = root->loc;
    max_node(root->right, max);
}
void vertical_print(bptr root, int k){
    if(!root) return;
    vertical_print(root->left,k);
    if(root->loc == k)
        cout<<" "<<root->key;
    vertical_print(root->right,k);
}
void vertical_order(bptr root, int min, int max){
    for(int i=min ; i<=max; i++){
        cout<<"\n";
        vertical_print(root, i);
    }
}
int main()
{
    bptr root = NULL; int k;
    while(1){
        cin>>k;
        if(!k) break;
        root = insert(root, k, 0);
        //inorder(root);
    }
    //inorder(root);
    int min =0, max=0;
    min_node(root, min); max_node(root, max);
    cout<<"\n"<<min<<" "<<max<<"\n";
    int size = max - min+1;
    map<int, bool> M;
    for(int i=min; i<=max; i++)
        M[i] = false;
    vector<int> V;
    topview(root, V, M);
    cout<<"\n";
    for(int i=0; i<V.size(); i++)
        cout<<" "<<V[i];
    cout<<"\n\n";
    vertical_order(root, min, max);
    return 0;
}
