#include<iostream>
using namespace std;
//const int size=20;
class queue
{
 public:
      int size;
      int front,rear;
      int *elements;
     
      queue();
      queue(int);
      //~queue();
      void enqueue(int);
      int dequeue();   
      void display();   
      };
      queue::queue()
      {
                    front=-1;
                    rear=-1;
                     cout<<"Enter the size: ";
                     cin>>size;
                     elements=new int[size];              
                    
      }
      queue::queue(int x)
      {
      front=-1;rear=-1;
      }
      void queue::enqueue(int x)
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
      int queue::dequeue()
      {
          int t;
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
      void queue :: display( )
      {
	cout << endl ;
	    if(front>=0&&rear>=0)
	    {                cout<<"The queue is:\n";
         for ( int i = front; i <=rear ; i++ )
		cout << elements[i] << "  " ;}
	 cout << endl ;
     }
      int main()
      {
          queue q;
          int i,j;
          char ch;
          while(1)
          {
          cout<<"Enter the element: ";
          cin>>i;
          q.enqueue(i);
          cout<<"Do you want to dequeue? Press y or n: ";
          cin>>ch;
          if(ch=='y')
          {
                     j=q.dequeue();
     	             cout << "\nItem deleted: " << j ;
     	             q.display();
                   }
          cout<<"Do you want Stop? Press y or n: ";
          cin>>ch;
          if(ch=='y')
          break;
          else
          continue;
          }
          system("pause");
          return(0);
      }
