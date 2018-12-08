#include<bits/stdc++.h>
using namespace std;
#define size 4

int get_Decimal(int key, int d){
    char in[25]; char str[25];
    itoa(key, str, 2);
    if(strlen(str) > d){
        for(int i=0; i<d; i++){
            in[d-1-i] = str[strlen(str)-1-i];
        }
        in[d] = '\0';
    }
    else
        strcpy(in,str);
    int k = 0; int len = strlen(in);
    for(int i=0; i < len; i++){
        k += pow(2, len-1-i)*(int)(in[i]-'0');
    }
    return k;
}

struct Bucket{
    int dp;
    int *Data;
    int count;
    Bucket() { }
    Bucket(int d){
        dp = d; count = 0;
        Data = new int [size];
    }
};
class ExHash{
    private:
        int d;
        vector<Bucket*> ptrs;
    public:
        ExHash(int dp){
            d = dp; int n = pow(2,d);
            ptrs.resize(n,NULL);
            for(int i=0; i < n; i++)
                ptrs[i] = new Bucket(d);
        }
        void insert(int key);
        void print();
        void SplitDirectory(int in,int key);
        void SplitBucket(int in, int key);
};

void ExHash::insert(int key){
    int in = get_Decimal(key, d);
    if(ptrs[in]->count != size){
        ptrs[in]->Data[ptrs[in]->count++] = key;
    }
    else{
        if(d == ptrs[in]->dp)
            SplitDirectory(in, key);
        else{
            printf("\nBucket\n");
            SplitBucket(in, key);
        }
    }
}
void ExHash::SplitDirectory(int in, int key){
    int dr = pow(2,d);
    ptrs.resize(2*dr, NULL);
    for(int i=dr; i < 2*dr; i++)
        ptrs[i] = new Bucket(d);
    vector<int> tmp;
    for(int i=0; i<ptrs[in]->count; i++)
        tmp.push_back(ptrs[in]->Data[i]);
    tmp.push_back(key);  ptrs[in]->count = 0; ptrs[in+dr]->count = 0;
    for(int i=0; i<size+1; i++){
        if(get_Decimal(tmp[i], d+1) == in)
            ptrs[in]->Data[ptrs[in]->count++] = tmp[i];
        else
            ptrs[in+dr]->Data[ptrs[in+dr]->count++] = tmp[i];
    }
    for(int i=0; i<dr; i++){
        if(i!=in){
            ptrs[i+dr] = ptrs[i];
        }
    }
    ptrs[in]->dp++; ptrs[in+dr]->dp++;
    d = d+1;
}
void ExHash::SplitBucket(int in, int key){
    in = get_Decimal(key, d-1);
    int dr = pow(2,d-1);
    vector<int> tmp;
    for(int i=0; i<ptrs[in]->count; i++)
        tmp.push_back(ptrs[in]->Data[i]);
    tmp.push_back(key);
    delete [] ptrs[in]->Data;
    ptrs[in]->Data = new int[size];
    ptrs[in]->dp++; ptrs[in]->count=0;
    ptrs[in+dr] = new Bucket(ptrs[in]->dp);
    for(int i=0; i<=size; i++){
        int in = get_Decimal(tmp[i], d);
        ptrs[in]->Data[ptrs[in]->count++] = tmp[i];
    }
}
void ExHash::print(){
    int dr = pow(2, d);
    for(int i=0; i < dr; i++){
        printf("[%d] -->", i );
        for(int j=0; j < ptrs[i]->count; j++)
            cout<<" "<<ptrs[i]->Data[j];
        cout<<"\n";
    }
}

int main(){
    ExHash H(0); int key;
    while(1){
        cout<<"Enter Key ( 0 to stop ) : ";  cin>>key;
        if(!key) break;
        H.insert(key);
        H.print();
    }
    H.print();
    return 0;
}
