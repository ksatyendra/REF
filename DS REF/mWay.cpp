#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
using namespace std;
const int m = 3;
typedef struct mnode
{
	int *data;
	mnode ** ptrs;
	mnode()
	{
		data = new int[m];
		for(int i=0; i<m ; i++)
		{
			data[i] = 0;
		}
		ptrs = new mnode * [m+1];
		for(int i=0; i<=m; i++)
			ptrs[i] = NULL;
	}
}* mptr;

mptr insert(mptr root, int k)
{
	if(!root)
	{
		cout<<"k";
		root = new mnode;
		root->data[0] = k;
		return root;
	}
	else
	{
		int i;
		for(i = 0 ; i < m ; i++)
		{
			if( k < root->data[0] && root->data[0] != 0)
			{
				cout<<"l";
				root->ptrs[i] = insert(root->ptrs[i], k);
				break;
			}
			else if( k > root->data[m-1] && root->data[m-1]!=0)
			{
				cout<<"r";
				root->ptrs[m] = insert(root->ptrs[m], k);
				break;
			}
			else if( k > root->data[i] && root->data[i+1] == 0 )
			{
				cout<<"s";
				root->data[i+1] = k;
				break;
			}
			else if( k> root->data[i] && k < root->data[i+1] && root->data[i+1]!=0)
            {
                cout<<"m";
                root->ptrs[i+1] = insert(root->ptrs[i+1], k);
                break;
            }

		}
	}
	return root;
}

void display(mptr root)
{
	if(root)
	{
		int i;
		for(i=0; i<m; i++)
		{
			display(root->ptrs[i]);
			if(root->data[i]!=0)
				cout<<" "<<root->data[i];
		}
		display(root->ptrs[m]);
	}
}
int main()
{
	mptr root=NULL; int k; int ans=1;
	mptr t = new mnode;
	cout<<t->data[2];
	while(ans)
	{
		cout<<"\nEnter Data : " ;cin>>k;
		root = insert(root, k);
		display(root);
		cout<<"\nWanna Continue ? (1/0) ";
		cin>>ans;
	}

	return 0;
}
