#include<iostream>
using namespace std;
void perculate_down(int &x,int &y)
{
	int temp;
	temp=x;
	x=y;
	y=temp;
}
void insert(int *h,int k,int i,int d)
{
	int j;
	if(i==0)
	{
		h[i]=k;
    return;
	}
	else
	{
		j=(i-1)/d;	
		if(k>h[j])
		h[i]=k;
		else
		{
			h[i]=k;
			perculate_down(h[i],h[j]);
			insert(h,h[j],j,d);
		}
	}
		
}

int delete_top(int *h,int &size,int d)
{
	int j=0;
	int x=h[j];
	h[j]=h[size-1];
	size--;
	int min,i,pos;
	while(j<size)	
	{	if(j*d+1<size)
		{
		min=h[j*d+1];
		pos=j*d+1;
		for(i=j*d+2;i<size&&i<j*d+d;i++)
		{
			if(h[i]<min)
			{min=h[i];
			pos=i;}
			
		}
		}
		if(h[j]>h[pos])
		{
		perculate_down(h[j],h[pos]);
		j=pos;
		}
		else 
		break;
	}
	return x;
}
int main()
{
	int n,num,i,d;
	cout<<"Enter number of elements and d value: ";
        cin>>n;
        cin>>d;
        int heap[n];
        cout<<"Enter the numbers: ";
        for(i=0;i<n;i++)
        {
			cin>>num;
			insert(heap,num,i,d);
		}
		for(i=0;i<n;i++)
		cout<<heap[i]<<" ";
		cout<<endl;
		int size_of_heap=n;
		for(i=0;i<size_of_heap;i++)
		{
			cout<<delete_top(heap,n,d)<<" ";
		}
		cout<<endl;
}

