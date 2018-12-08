#include<iostream>
using namespace std;
template<class T>
class queue
{
 public:
      int size;
      int front,rear;
      T *elements;
     
      queue();
      queue(int);
      void enqueue(T);
      T dequeue();   
      void display();   
      bool empty();
};
template<class T>
	queue<T>::queue()
    {
    		front=-1;
            rear=-1;
            cout<<"Enter the size: ";
            cin>>size;
        	elements=new T[size];              
                    
    }
    template<class T>
	queue<T>::queue(int x)
    {
	front=-1;rear=-1;
	size=x;
	elements=new T[size];
    }
   template<class T>
    void queue<T>::enqueue(T x)
    {
    if(front==(rear+1)%size)
	cout<<"Queue Full..\n";
	else
    {
    if(front==-1)
    front=0;
	rear=(rear+1)%size;
    elements[rear]=x;
    }
    }
     template<class T>
	  T queue<T>::dequeue()
      {
          T t;
          if(front==-1)
          {
                       cout<<"Queue is empty..\n";
                       return NULL;
                       }
      else
          {
              if(front==rear)
              {
                             t=elements[front];
                             front=-1;rear=-1;
              }
              else
              {              t=elements[front];
                             front=(front+1)%size;
              }
          }
          return (t);
      }
      template<class T>
	  void queue<T> :: display( )
      {
		cout << endl ;
	    if(front>=0&&rear>=0)
	    {               cout<<"The queue is:\n";
         				for ( int i = front; i <=rear ; i++ )
						cout << elements[i] << "  " ;
		}
	 	cout << endl ;
     }
    template<class T>
	 bool queue<T>::empty()
     {
	if(front==-1)
          return true;
          else
          return false;
	}
