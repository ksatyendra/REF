#include<bits/stdc++.h>
using namespace std;
#define k 3
#define size 4
struct Poly{
    int nop;
    int psize;
    Poly() { nop = psize = 0; }
};
bool WorkComplete(fstream file[],int t){
    for(int i=0; i<=k; i++){
        if(i==t)
            continue;
        if(file[i].eof())
            return true;
    }
    return false;
}
int min_index(int A[]){
    int min = A[0], in  = 0;
    for(int i=0; i < k; i++)
        if(A[i]<min){
            in = i;
            min = A[i];
        }
    return in;
}
int main(){
    fstream fin("key.txt",ios::in|ios::out);    Poly P[k+1];  char ch[8];
    fstream file[k+1];  int i,j,a,b=0,count = 0,tmp=0; int A[k+1]={}; int c[k+1] = {};
    for(i=0; i <= k; i++){
        char ch[8];
        strcpy(ch,"file");
        ch[4] = '0'; ch[5]=(char)i+48; ch[6] = '\0';
        file[i].open(ch, ios::trunc|ios::in|ios::out);
    }i=0;
    P[0].nop = 7; P[1].nop = 6; P[2].nop = 4; P[3].nop = 0;
    P[0].psize = P[1].psize = P[2].psize = size; P[3].psize = 0;
    while(!fin.eof()){
        fin>>a;
        if(i<size)
            A[i++] = a;
        if(i==size || fin.eof()){
            if(fin.eof()) i--;
            sort(A,A+i);
            for(j=0; j < i; j++){
                file[tmp]<<A[j]<< " ";
                cout<<" "<<A[j];
            }
            c[tmp]++;
            tmp = (tmp+1)%(size-1);  i=0;
            while(c[tmp]>=P[tmp].nop && b!=size){
                tmp = (tmp+1)%(size-1);
                b++;
            }
            b=0;
        }
        count++;
    }
    for(i=0; i<=k; i++){
        file[i].seekg(0,ios::beg);
        A[i] = c[i] = 0;
    }
    tmp = 0; b = size-1;
    while(!file[b-1].eof()){
        for(i=0; i<k; i++){
            if(A[i]==0 && c[i]!=P[i].psize){
                if(file[i]>>A[i])
                    c[i]++;
                else A[i] = INT_MAX;
            }
        }
        int index = min_index(A);
        file[b]<<" "<<A[index]; cout<<" "<<A[index];
        A[index] = 0;
        if(c[i]==P[i].psize)
            A[index] = INT_MAX;
        if(A[0]==INT_MAX||A[1]==INT_MAX||A[2]==INT_MAX){
            for(j=0;j<k; j++)
                A[i] = c[i] = 0;
        }
        tmp++;
        if(tmp==6)
        break;
    }
    fin.close();
    for(i=0; i<=k; i++)
        file[i].close();
    return 0;
}
