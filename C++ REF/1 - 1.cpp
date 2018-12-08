#include<bits/stdc++.h>
using namespace std;
struct Heap
{
    int N; int in;
    Heap(){ N = INT_MAX; in = -1; }
    Heap(const Heap &H){
        N = H.N;
        in = H.in;
    }
};
int getKey(list<int> A[], int in){
    int k;
    if(!A[in].empty()){
        k = A[in].front(); A[in].pop_front();}
    else
        k = INT_MAX;
    return k;
}
void display(vector<Heap> H, int n){
    cout<<"\nHeap Elements are : ";
    for(int i=0; i<n; i++)
        printf(" %d,%d ", H[i].N, H[i].in);
    cout<<"\n";
}
void heapify(vector<Heap> &H, int n){
    int s,f,i;
    for (int i = 1; i < n; ++i)
    {
        Heap val = H[i]; s = i; f = (s-1)/2;
        while(s>0 && H[f].N > val.N){
            H[s] = H[f]; s = f; f = (s-1)/2;
        }
        H[s] = val;
    }
    display(H,n);
}

bool isComplete(vector<Heap> H, int n){
    for(int i=0; i<n; i++){
        if(H[i].N != INT_MAX)
            return false;
    }
    return true;
}
int main()
{
    vector<Heap> v(10);  list<int> A[4];  A[0].push_back(5); A[0].push_back(15); A[0].push_back(51);
    A[1].push_back(2);  A[1].push_back(8); A[1].push_back(12);
    A[2].push_back(1);  A[2].push_back(3); A[2].push_back(7);
    A[3].push_back(2);  A[4].push_back(6); A[3].push_back(9);
    int n=4,i=0;
    while(!isComplete(v,n)){
        if(i!=4){
            for(int j=0; j<n; j++){
                v[j].N = getKey(A, j);
                v[j].in = j;
            }
        }
        heapify(v,n);
        cout<<" "<<v[0].N;
        v[0].N = getKey(A, v[0].in);
    }
    return 0;
}
