#include<bits/stdc++.h>
using namespace std;
class Student{
    protected:
        int regno;
        int rno;
        string name;
    public:
        Student () { regno = rno = 0; name = ""; }
        ~Student() {}
        void input(){
            cin>>regno;
            cin>>rno;
            getline(cin, name, '#');
        void display(){
            cout<<setw(8)<<regno<<setw(8)<<rno<<setw(20)<<name;
        }
};
class EnggStu:public Student{
    string Branch;
    public:
        EnggStu() {  Branch = ""; }
        void input(){
            Student::input();
            //cout<<"Enter Branch : " ;
            getline(cin, Branch,'#');
        }
        void display(){
            Student::display();
            cout<<setiosflags(ios::left)<<setw(30)<<Branch<<"\n";
        }
        int retReg() { return regno; }
        int retRoll() { return rno; }
        string retName() { return name; }
        string retBranch() { return Branch; }
};
bool compreg(EnggStu a, EnggStu b){
    return (a.retReg() < b.retReg());
}
bool compRoll( EnggStu a, EnggStu b){
    return (a.retRoll() < b.retRoll());
}
bool compName( EnggStu a, EnggStu b){
    return (a.retName() < b.retName());
}
bool compBranch( EnggStu a, EnggStu b){
    return (a.retBranch() < b.retBranch());
}
int main()
{
    EnggStu *E,tmp;  int n,ans;
    cout<<"\nEnter no. of Student : " ; cin>>n;
    E = new EnggStu [n];
    for(int i=0; i<n; i++)
        E[i].input();
    while(1){
        cin>>ans;
        switch(ans){
        case 1:
            sort(E, E+n, compreg);
            break;
        case 2:
            sort(E, E+n, compRoll);
            break;
        case 3:
            sort(E, E+n, compName);
            break;
        case 4:
            sort(E, E+n, compBranch);
            break;
        case 5:
            return 0;
        default:
            break;
        }
    if(ans>=1 && ans<=4)
        for(int i=0; i<n; i++)
            E[i].display();
    }
    return 0;
}
