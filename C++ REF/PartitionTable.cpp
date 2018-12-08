#include<bits/stdc++.h>
#include<stdio.h>
#define k 3
#define size 4
struct Poly{
    int val;
    int prtn;
    Poly(){ val = 0; prtn = 0;}
};
bool isComplete(Poly P[],int count){
    for(int i=0; i <= k; i++){
        if(P[i].prtn == count)
            return true;
    }
    return false;
}
using namespace std;
int main(){
    int i,j; char ch[8]; int count=0,tmp = k, t = k-1;
    /*fstream file[k+1],KeyFile;
    KeyFile.open("key.txt", ios::in|ios::in);
    for(i=0; i<=k; i++){
        strcpy(ch,"file");
        ch[4] = '0';
        ch[5]=(char)i+48; ch[6] = '\0';
        file[i].open(ch, ios::in|ios::out|ios::trunc);
    }
    while(KeyFile>>j)
    count++;*/
    count = 102;
    while(count%size != 0)
        count++;
    int p = ceil((double)count/size);
    int mid = ceil((double)p/k);
    int pre = mid+1;
    int post = p - mid - pre;

    Poly P[10]; j=0;
    P[0].val = pre; P[1].val = mid; P[2].val = post; P[3].val = 0;
    P[0].prtn = P[1].prtn = P[2].prtn = size; P[3].prtn = 0;
    for(i=0; i<=k; i++)
            cout<<" ["<<P[i].val<<", "<<P[i].prtn<<"]";
    while(!isComplete(P,count)){
        cout<<"\n";
        while(P[t].val!=0){
            for(i=0; i <= k; i++){
                if(i==tmp || i==t ||P[i].val == 0)
                    continue;
                P[i].val--;
            }
            P[tmp].val++; P[t].val--;
        }
        for(i=0; i <= k ; i++){
            if(i==tmp)
                continue;
            P[tmp].prtn += P[i].prtn;
        }
        P[t].prtn = 0;
        if(t!= 0) t--;
        else{
            while(P[t].val==0)
                t++;
        }
        if(tmp!=0 ) tmp--; else tmp++;
        for(i=0; i <=k; i++)
            if(P[i].val==0)
            P[i].prtn = 0;
        for(i=0; i<=k; i++)
            cout<<" ["<<P[i].val<<", "<<P[i].prtn<<"]";
    }
    //KeyFile.close();
    //for(i=0; i<= k; i++)
        //file[i].close();
    return 0;
}
