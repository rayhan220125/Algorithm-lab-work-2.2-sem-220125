#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
void tower(int n, char sour, char help, char des)
{
    if(n==1)
    {
        cout<< "Move Disk "<<n<< " form "<< sour << " to "<< des<<endl;
        return;

    }
    tower(n-1, sour, des, help);
    cout<< "Move Disk "<<n<< " form "<< help << " to "<< des<<endl;
    tower(n-1, help, sour, des);

}
int main()
{
    int n;
    cout<<"Enter the number of Disk: "<<endl;
    cin>>n;
    int d= pow(2,n)-1;
    cout<<"Total move: "<<d<<endl;
    tower(n,'A','B','C');

}
