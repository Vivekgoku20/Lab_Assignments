#include<bits/stdc++.h>
using namespace std;
#define int long long
fstream ofs;

bool check(string &s){

    int n = s.length();
    int i=0;
    while(s[i]=='0'){
        i++;
    }
    s=s.substr(i);
    n = s.length();
    //cout<<s<<endl;
    return n==2 and s>="75" and s<="85";
}

signed main(){
    int r,n,x,y;
    string s;
    cin >> s;
    ofs.open("output6.txt", ios::out | ios::trunc);
    
    if(!check(s)){
        cout<<"Invalid input. Please enter a value between 75 and 85"<<endl;
        ofs<<"Invalid input. Please enter a value between 75 and 85"<<endl;
        exit(0);
    }

    r = stoi(s);

    for(x=0;x<r;x++){
        for(y=0;y<r;y++){
            if(sqrt(x*x+y*y)<r)
            {
                cout<<"x = " << -x << " , y = "<< y << endl;
                ofs<<"{ "<<-x<<" , "<<y<<" }"<<endl;
            }
        }
    }

}