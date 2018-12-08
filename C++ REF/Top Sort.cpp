#include<iostream>
using namespace std;
#define MAX_NODE 50
struct node
{
    int vertex;
    node *next;
};
node *adj[MAX_NODE]; //For storing Adjacency list of nodes.
int totNodes;
//No. of Nodes in Graph.
const int ready=1,wait=2,processed=3;
//status of node.
int status[MAX_NODE];//status arr for maintaing status.
node *sngllist=NULL; //Singly Link List
void createGraph()
{
    node *newl,*last;
    int neighbours,neighbour_value;
    cout<<"\n\n---Graph Creation---\n\n";
    cout<<"Enter total nodes in graph : ";
    cin>>totNodes;
    for(int i=1;i<=totNodes;i++)
    {
        last=NULL;
        cout<<"\nEnter no. of nodes in the adjacency list of node "<<i<<"\n";
        cout<<"--> That is Total Neighbours of "<<i<<" : ";
        cin>>neighbours;
        for(int j=1;j<=neighbours;j++)
        {
            cout<<"Enter neighbour #"<<j<<" : ";
            cin>>neighbour_value;
            newl=new node;
            newl->vertex=neighbour_value;
            newl->next=NULL;
            if(adj[i]==NULL)
                adj[i]=last=newl;
            else
            {
                last->next = newl;
                last = newl;
            }
        }
    }
}


void dfsVisit(int i)
{
    node *tmp,*newl;
    int v;

    tmp=adj[i];
    while(tmp != NULL)
    {
        v=tmp->vertex;
        if(status[v]==ready)
            dfsVisit(v);
        tmp=tmp->next;
    }

    newl=new node;
    newl->vertex=i;
    newl->next=sngllist;
    sngllist=newl;
    status[i]=processed;
}

void topologicalSort()
{
    int i;

    for(i=1;i<=totNodes;i++)
        status[i]=ready;
    for(i=1;i<=totNodes;i++)
    {
        if(status[i]==ready)
            dfsVisit(i);
    }
    //print listwhile(sngllist!=NULL){
        cout<<"   "<<sngllist->vertex;
        sngllist=sngllist->next;
}
int main()
{
    cout<<"*****Topological Sort*****\n";
    createGraph();
    cout<<"\n===Topological Sort is as under===\n";
    topologicalSort();
    return 0;
}
