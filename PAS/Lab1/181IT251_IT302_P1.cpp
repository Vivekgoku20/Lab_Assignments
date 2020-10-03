#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define inf 1e18
#define P 1000000007
fstream ofs;
bool is_valid(string &s)
{

    int n = s.length();
    int i=0;
    while(s[i]=='0'){
        i++;
    }
    s=s.substr(i);
    n = s.length();
    cout<<s<<endl;
    return n==2 and s>="75" and s<="85";
}
signed main()
{
    int r,n,x,y;
    string s;
    cin>>s;
    ofs.open("output.txt", ios::out | ios::trunc);
    if(!is_valid(s))
    {
        cout<<"Invalid input. Please enter a value between 75 and 85"<<endl;
        ofs<<"Invalid input. Please enter a value between 75 and 85"<<endl;
        exit(0);
    }
    r = stoi(s);

    for(x=1;x<1000;x++)
    {
        for(y=1;y<1000;y++)
        {
            if(sqrt(x*x+y*y)<r)
            {
                cout<<"{ "<<-x<<" , "<<y<<" }"<<endl;
                ofs<<"{ "<<-x<<" , "<<y<<" }"<<endl;
            }
        }
    }

}