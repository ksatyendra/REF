#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;
void print_num(int n)
{
     switch (n)
     {
            case 1:{cout<<"One";break;}
            case 2:{cout<<"Two";break;}
            case 3:{cout<<"Three";break;}
            case 4:{cout<<"Four";break;}
            case 5:{cout<<"Five";break;}
            case 6:{cout<<"Six";break;}
            case 7:{cout<<"Seven";break;}
            case 8:{cout<<"Eight";break;}
            case 9:{cout<<"Nine";break;}
            case 10:{cout<<"Ten";break;}
            case 11:{cout<<"Eleven";break;}
            case 12:{cout<<"Twelve";break;}
            case 13:{cout<<"Thirteen";break;}
            case 14:{cout<<"Fourteen";break;}
            case 15:{cout<<"Fifteen";break;}
            case 16:{cout<<"Sixteen";break;}
            case 17:{cout<<"Seventeen";break;}
            case 18:{cout<<"Eighteen";break;}
            case 19:{cout<<"Nineteen";break;}
     }
}
void print_decade(int n)
{
     switch(n)
     {
              case 2:cout<<"Twenty ";break;
              case 3:cout<<"Thirty ";break;
              case 4:cout<<"Forty ";break;
              case 5:cout<<"Fifty ";break;
              case 6:cout<<"Sixty ";break;
              case 7:cout<<"Seventy ";break;
              case 8:cout<<"Eighty ";break;
              case 9:cout<<"Ninety ";break;
     }
}

void print(int n)
     {
          print_num(n/100);
          if(n>100)
          cout<<" Hundred ";
          n=n%100;
          if (n>19)
          {
                   print_decade(n/10);
                   n=n%10;
                   print_num(n);
          }
          else
          print_num(n);
     }




int main()
{
    int n;
    cout<<"Enter the number between 1 to 1000: \n";
    cin>>n;
    print(n);
//    system("pause");
    return(0);
}



