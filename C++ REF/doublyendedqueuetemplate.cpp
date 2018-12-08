#include<iostream>
using namespace std;
template<class T>
class queue
{       public:
        struct dnode
        {
                T data;
                dnode* left;
                dnode* right;
                dnode()
                {
                left=right=NULL;
                }
        }*front,*rear;
        queue()
        {
        front=rear=NULL;
        }
        void enqueue_front(T k);
        void enqueue_end(T k);
        T dequeue_front();
        T dequeue_end();
        bool empty();
};
template<class T>
void queue<T>::enqueue_front(T k)
{
        if(front==NULL&&rear==NULL)
        {
                front=new dnode;
                front->data=k;
                rear=front;
        }
        else
        {
                dnode* t=new dnode;
                t->data=k;
                t->right=front;
                front->left=t;
                front=t;
        }
}
template<class T>
void queue<T>::enqueue_end(T k)
{

        if(front==NULL&&rear==NULL)
        {
                rear=new dnode;
                rear->data=k;
                front=rear;
        }
        else
        {
              rear->right=new dnode;
              rear->right->data=k;
              rear->right->left=rear;
              rear=rear->right;
        }
}
template<class T>
T queue<T>::dequeue_front()
{
        if(front==NULL)
        {
        cout<<"Queue is empty.."<<endl;
        return NULL ;
        }
        else
        {
        dnode* t=front;
        front=t->right;
        t->right=NULL;
        front->left=NULL;
        T value=t->data;
        delete t;
        return(value);
        }
}
template<class T>
T queue<T>::dequeue_end()
{
        if(front==NULL)
        {
        cout<<"Queue is empty.."<<endl;
        return NULL;
        }
        else if(front==rear)
        {
        T value =front->data;
        dnode *t=front;
        front=rear=NULL;
        delete t;
        return(value);
        }
        else
        {
        dnode* t=rear;
        rear=t->left;
        T value=t->data;
        t->left=NULL;
        rear->right=NULL;
        delete t;
        return(value);
        }
}
template<class T>
bool queue<T>::empty()
{
if(front==NULL)
return true;
else
return false;
}
