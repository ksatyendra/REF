#include<bits/stdc++.h>
using namespace std;
int k=3;
int min(int d[])
{
    int min=999,i,c=0;
    for( i=0;i<k+1;i++)
    {
        if(d[i]!=0&&min>d[i])
        {
            c=i;
            min=d[i];
        }
    }//cout<<c<<" ";
    return(c);
}
int search(int d[])
{
    int c=0;
    for(int i=0;i<k+1;i++)
    {
        if(d[i]!=0)
            c++;
    }
    return(c);
}
int main()
{
    int nu=1;
    int b[4]={14,11,6,0},d[4]={0,0,0,0},flag=0;
    int s=4,a[4],n=0,t=0,c,i=0,e[4]={s,s,s,0};
    char buf[k+1][6];
    fstream f[k+1],fin;
    fin.open("abc.txt",ios::in);
    for(int i=0;i<=k;i++)
    {
        itoa(i,buf[i],10);
        strcat(buf[i],".txt");
        f[i].open(buf[i],ios::out);
    }
    while(n<124){
        i=0;
        flag=0;
        while(b[t]>d[t+1]&&i<s&&!(fin.eof()))
        {
            fin>>c;
            if(c==-1)
                break;
            a[i]=c; i++;    n++;    flag=1;
        }
        d[t+1]=d[t+1]+1;
        sort(a,a+s);
        for(int i=0; i<s && flag==1; i++)
            f[t]<<a[i]<<"\n";
            t=(t+1)%3;
    }
    for(int i=0; i<k+1; i++)
        f[i].close();
    int z=3;
    t=0;
    for(int i=0;i<=k;i++)
    {
        if(z!=i)
        {
            f[i].open(buf[i],ios::in);
            f[i].seekg(0,ios::beg);
        }
    }
    int q=k+2,counter=0,temp=0;
    while(search(b)!=1)
    {
        for(int i=0;i<4;i++)
        {
            if(q==k+2&&b[i]==0)
            {
                e[i]=e[0]+e[1]+e[2]+e[3];
            }
            else if(b[i]==0){
                e[i]=e[0]+e[1]+e[2]+e[3]-e[q];
            }
        }
        f[z].open(buf[z],ios::out);
        f[z].seekp(0,ios::beg);
        n=0;  int p=min(b);
        i=0,flag=0,n=0;
        while(i<b[p])
        {
            n=0,t=0;
            int x=0;
            for(int i=0;i<s;i++)
                d[i]=0;
            while(n<s)
            {
                if((counter!=k-2||t!=q)&&z!=t)
                {
                    f[t]>>c;
                    a[n]=c;
                }
                n++;
                t=(t+1)%4;
            }
            a[z]=999;
            if(q!=k+2&&counter!=k-2)
            {
                a[q]=999;
            }
            x=min(a);
            f[z]<<a[x]<<"\n";
            d[x]=d[x]+1;
            flag=0;
            while(a[x]!=999&&d[x]<e[x])
            {
                n++;
                if(flag==0)
                {
                    f[x]>>c;
                    a[x]=c;
                }
                flag=0;x=min(a);
                d[x]=d[x]+1;
                if(a[x]!=999)
                f[z]<<a[x]<<"\n";
                if(d[x]==e[x])
                {
                    a[x]=999;
                    flag=1;
                }
                x=min(a);
            }
            i++;
        }
        temp=p;
        p=b[p];
        for(int i=0;i<k+1;i++)
        {
            if(i!=q)
            {
                b[i]=b[i]-p;
                if(b[i]<0)
                    b[i]=-b[i];
            }
        }
        if(q!=k+2)
            b[z]=p;
        f[z].close();
        f[z].open(buf[z],ios::in);
        f[z].seekg(0,ios::beg);
        counter++;
        if(counter==k-1)
        {
            q=k+2;
            counter=0;
        }
        else
        {
            if(q==5&&temp==3)
                q=2;
            else
                q=z;
        }
        z=temp;
        if(z==-1)
            z=3;
        e[temp]=0;
        f[z].close();
        for(int i=0;i<4;i++)
            cout<<b[i]<<" "<<e[i]<<"\n";
        cout<<"\n";
        nu++;
    }
}
