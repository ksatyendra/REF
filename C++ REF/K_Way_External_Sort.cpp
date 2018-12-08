#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
#define m 6
#define size 4
void FileClear(fstream &file, bool i, int in){
    char ch[8];
    strcpy(ch,"file");
    ch[4] = (char)i+48;
    ch[5]=(char)in+48; ch[6] = '\0';
    file.close();
    file.open(ch, ios::trunc|ios::in|ios::out);
    file.seekg(0,ios::beg);
}
void FileBeg(fstream file[][m], bool tag){
    for(int i=0; i<m; i++)
        file[tag][i].seekg(0,ios::beg);
}
int min_index(int A[]){
    int min = A[0], in  = 0;
    for(int i=0; i < m; i++)
        if(A[i]<min){
            in = i;
            min = A[i];
        }
    return in;
}
bool countComplete(int c[],int n){
    for(int i=0; i<m; i++)
        if(c[i]!=n)
        return false;
    return true;
}
bool isAtMax(int A[]){
    for(int i=0; i<m; i++)
        if(A[i]!=INT_MAX)
        return false;
    return true;
}
void init(){
    ofstream fout("key.txt");
    for(int i=1000; i>0; i--)
        fout<<" "<<i;
    fout.close();
}
int main()
{
    init();
    fstream file[2][m]; fstream fin("key.txt", ios::in|ios::out);
    int i,j,k,n=size,count=0; int c[m]; bool tag = false; int tag1=0; char ch[8];
    int num[size]; int A[m];
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
            num[i++] = k;
        if(i==size || fin.eof()){
            //if(fin.eof()) i--;
            sort(num,num+i);
            for(j=0; j < i; j++){
                if(num[j]!=INT_MAX)
                file[0][tag1]<<num[j]<< " ";
            }
            tag1 = (tag1+1)%m;  i=0;
        }
        count++;
    } cout<<count<<"\n";
    for(i=0; i<m;i++) A[i]=c[i]=0;
    tag = false; tag1 = 0;  fin.close();
    fin.open("key.txt", ios::in|ios::out|ios::trunc); fin.seekp(0,ios::beg);
    for(j = n*m; n < count; j *=m){
        FileBeg(file,tag);
        while(1){
            for(i=0; i<m; i++){
                if(A[i]==0 && c[i]!=n){
                    if(file[tag][i]>>A[i]);
                    else
                        A[i] = INT_MAX;
                    c[i]++;
                }
            }
            int index = min_index(A);
            if(j>count &&A[index]!=INT_MAX){ fin<<" "<<A[index];  cout<<A[index]<<" "; }
            else if(A[index]!=INT_MAX)
                file[!tag][tag1]<<" "<<A[index];

            A[index] = 0;
            if(c[index] == n)
                A[index] = INT_MAX;
            if(countComplete(c,n) && isAtMax(A)){
                //cout<<"\n\n";
                for(i=0;i<m; i++)
                    c[i] = A[i] = 0;
                tag1 = (tag1+1)%m;
            }
            if(isAtMax(A))
                break;
        }
        for(i=0; i<m; i++){
            c[i]=A[i]=0;
            FileClear(file[tag][i],tag,i);
        }

        tag = !tag;  n*=m; tag1=0;
        //cout<<"\n";
    }//*/

    for(i=0; i< m; i++){
        file[0][i].close();
        file[1][i].close();
    }
    fin.close();
	return 0;
}
