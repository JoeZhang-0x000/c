#include<iostream>
using namespace std;
int main(int argc, const char** argv) {
    int a=0,b=0,c,d,a1,b1,m,n,r,t,q;
    cout<<"please input the m and n:\n"<<endl;
    cin>>m;
    cin>>n;
    a1 = b= 1;
    a = b1 =0;
    c = m;
    d = n;
    while (1)
    {
        /* code */
        q = int(c/d);
        r = c%d;
    
    if (r==0)
    {
        /* code */
        cout<<a<<"*"<<m<<"+"<<b<<"*"<<n<<"="<<d<<endl;
        break;
    }
    else
    {
        
        cout<<"try again!\n"<<endl;
        c = d;
        d =r;
        t =a1;
        a1 = a;
        a = t -q*a;
        t =b1;
        b1 = b;
        b =t -q*b;


    }
    
    }
    





    
    return 0;
}
