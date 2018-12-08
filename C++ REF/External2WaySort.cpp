#include<bits/stdc++.h>
using namespace std;
#define m 2
#define size 4
int getKey(fstream &file){
    int k;
    if(file>>k)
        return k;
    else
        return INT_MAX;
}
void FileClear(fstream &file, bool i, int in){
    char ch[8];
    strcpy(ch,"file");
    ch[4] = (char)i+48;
    ch[5]=(char)in+48; ch[6] = '\0';
    file.close();
    file.open(ch, ios::trunc|ios::in|ios::out);
    file.seekg(0,ios::beg);
}
int main()
{
    fstream file[2][m]; fstream fin("key.txt", ios::in|ios::out);
    int i,j,k,p,q,n=size,count1=0,count2=0, count;  p = q = count = 0; bool tag = false,tag1=false; char ch[8];
    int A[size];
    for(i=0; i < m; i++){
        strcpy(ch,"file");
        ch[4] = (char)tag+48;
        ch[5]=(char)i+48; ch[6] = '\0';
        file[tag][i].open(ch, ios::in|ios::out|ios::trunc);
        tag = true;
        ch[4] = (char)tag+48;
        file[tag][i].open(ch, ios::in|ios::out|ios::trunc); tag = false;
    }
    i=0;
    while(!fin.eof()){
        fin>>k;
        if(i<size)
            A[i++] = k;
        if(i==size || fin.eof()){
            if(fin.eof()) i--;
            sort(A,A+i);
            for(j=0; j < i; j++){
                file[0][tag]<<A[j]<< " ";
            }
            tag = !tag;  i=0;
        }
        count++;
    }
    tag = false; tag1 = false; count/=m;
    while(n < count){
        file[tag][0].seekg(0,ios::beg); file[tag][1].seekg(0,ios::beg);
        while(1){
            if(p==0 && count1!=n){
                p = getKey(file[tag][0]);
                count1++;
            }
            if(q==0 && count2!=n){
                q = getKey(file[tag][1]);
                count2++;
            }
            if(p<q){
                file[!tag][tag1]<<p<< " ";
                cout<<" "<<p; p=0;
                if(count1==n) p = INT_MAX;
            }
            else if(q<p){
                file[!tag][tag1]<<q<< " ";
                cout<<" "<<q; q=0;
                if(count2==n) q = INT_MAX;
            }
            if(count1==n && count2 == n && p == INT_MAX && q == INT_MAX){
                cout<<"\nArya\n";
                count1 = count2 = 0; p=q=0;
                tag1 = !tag1;
            }
            if(p == INT_MAX && q == INT_MAX)
                break;
        }
        p = q = count1 = count2 = 0; tag1 = false;
        FileClear(file[tag][0], tag, 0); FileClear(file[tag][1], tag, 1);
        tag = !tag;  n*=2; cout<<"\n";
    }
    fin.close(); file[tag][0].seekg(0,ios::beg); file[tag][1].seekg(0,ios::beg);
    fin.open("key.txt", ios::in|ios::out|ios::trunc);
    while(1){
        if(p==0 && count1!=n){
            p = getKey(file[tag][0]);
            count1++;
        }
        if(q==0 && count2!=n){
            q = getKey(file[tag][1]);
            count2++;
        }
        if(p<q){
            fin<<" "<<p;
            cout<<" "<<p; p=0;
            if(count1==n) p = INT_MAX;
        }
        else if( q < p){
            fin<<" "<<q;
            cout<<" "<<q; q=0;
            if(count2==n) q = INT_MAX;
        }
        if(count1==n && count2 == n && p == INT_MAX && q == INT_MAX){
            cout<<"\nArya\n";
            count1 = count2 = 0; p=q=0;
        }
        if(p == INT_MAX && q == INT_MAX)
            break;
    }
    for(i=0; i< m; i++){
        file[0][i].close();
        file[1][i].close();
    }
    fin.close();
	return 0;
}
