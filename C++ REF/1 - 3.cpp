#include<bits/stdc++.h>
#define k 3
#define size 4
#define INF INT_MAX
using namespace std;

struct Poly{
    int nop;
    int psize;
    Poly(){ nop = psize = 0; }
};

int min_index(int A[],int tmp);
bool countComplete(int A[],Poly P[],int tmp);
bool isAtMax(int A[], int tmp);
void FileClear(fstream &file,int t);

int main(){
    int i,j; char ch[8]; int count=0,tmp=0,t=0; int A[4]={}, c[4] = {};
    fstream file[k+1],fin;
    fin.open("key.txt", ios::in|ios::out);
    for(i=0; i<=k; i++){
        strcpy(ch,"file");
        ch[4] = '0';
        ch[5]=(char)i+48; ch[6] = '\0';
        file[i].open(ch, ios::in|ios::out|ios::trunc);
    }
    Poly P[5]; i=0;
    P[0].nop = 14; P[1].nop = 11; P[2].nop = 6; P[3].nop = 0;
    P[0].psize = P[1].psize = P[2].psize = 1; P[3].psize = 0;
    while(!fin.eof())
            fin>>t;
            if(fin.eof()) continue;
            if(c[tmp] == P[tmp].nop)
            file[tmp]<<" "<<T;
            c[tmp]++;
        }
    }
    tmp = k; t = k-1;  for(i=0; i<=k; i++){ A[i] = c[i] = 0; file[i].seekg(0,ios::beg); }
    for(j=0; j <=k; j++){
        if(j!=0){
            P[tmp].psize = P[0].psize + P[1].psize + P[2].psize + P[3].psize;
            count = P[t].nop; P[tmp].nop = P[t].nop;
            for(i=0; i<=k; i++){ if(i!=tmp) P[i].nop = P[i].nop-count;} P[t].psize = 0;
            FileClear(file[t],t); file[tmp].seekg(0,ios::beg); t--; if(t==-1) t=1; tmp--; count = 0;
        }
        while(!file[t].eof()){
            for(i=0; i<=k; i++){
                if(i==tmp)
                    continue;
                if(!A[i] && c[i]!=P[i].psize){
                    if(file[i]>>A[i]);
                    else A[i] = INF;
                    c[i]++;
                }
            }
            int in = min_index(A,tmp);
            //printf("\n%d", in);
            file[tmp]<<" "<<A[in];
            //cout<<" "<<A[in];
            A[in] = 0;
            if(c[in] == P[in].psize)
                A[in] = INF;
            if(countComplete(c,P,tmp) && isAtMax(A, tmp)){
                for(i=0; i<=k; i++){
                    if(i==tmp)
                        continue;
                    A[i] = c[i] = 0;
                }
                count++;
            }
            if(count == P[t].nop)
                break;
        }
    }
    fin.close();
    for(i=0; i<=k; i++)
        file[i].close();
    return 0;
}

int min_index(int A[],int tmp){
    int min = INF, in  = 0;
    for(int i=0; i <= k; i++){
        if(i==tmp)
            continue;
        if(A[i] < min){
            in = i;
            min = A[i];
        }
    }
    return in;
}

bool countComplete(int A[],Poly P[],int tmp){
    for(int i=0; i <= k; i++){
        if(i==tmp)
            continue;
        if(A[i] != P[i].psize)
            return false;
    }
    return true;
}

bool isAtMax(int A[],int tmp){
    for(int i=0; i <= k; i++){
        if(i==tmp)
            continue;
        if(A[i] != INF)
            return false;
    }
    return true;
}

void FileClear(fstream &file,int t){
    char ch[8];
    strcpy(ch,"file");
    ch[4] = '0';   ch[5]=(char)t+48; ch[6] = '\0';
    file.close();
    file.open(ch, ios::in|ios::out|ios::trunc);
}
