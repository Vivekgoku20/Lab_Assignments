#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define inf 1e18
#define P 1000000007
int main()
{
    cout << "Enter the number of inspectors: " << "\n";
    ll i,n;
    cin >> n;
    ofstream myfile;
    myfile.open("181IT251_IT302_P2_Output_TC3.txt");
    string a[n];
    cout << "Enter the names: " << "\n";
    for ( i = 0; i < n; i++)
    {
        cin >> a[i];
        if ((a[i][0] >= 'a' && a[i][0] <= 'z') || (a[i][0] >= 'A' && a[i][0] <= 'Z'))
            continue;
        else
        {
            myfile << "Invalid input";
            cout << "Invalid input" << "\n";
            return 0;
        }
    }
    ll per[n], mis[n];
    ll count = 0;
    cout << "Enter the percentage: " << "\n";
    for ( i = 0; i < n; i++)
    {
        cin >> per[i];
        count += per[i];
        if (count >= 100 && i != n - 1)
        {
            myfile << "Invalid input";
            cout << "Invalid input" << "\n";
            return 0;
        }
    }
    if (count != 100)
    {
        myfile << "Invalid input";
        cout << "Invalid input" << "\n";
        return 0;
    }
    cout << "Enter the number of packages after which they will commit the mistake: " << "\n";
    for ( i = 0; i < n; i++)
        cin >> mis[i];
    cout << "Enter the inpector name for which we want to know the probability: " << "\n";
    string target;
    cin >> target;
    ll index = inf;
    for ( i = 0; i < n; i++)
    {
        if (target == a[i])
        {
            index = i;
            break;
        }
    }
    if (index == inf)
    {
        myfile << "Invalid input";
        cout << "Invalid input" << "\n";
        return 0;
    }
    long double prob = 0;
    long double total = 0;
    for ( i = 0; i < n; i++)
    {
        total += (long double)per[i] / mis[i];
    }
    prob = (long double)per[index] / mis[index];
    myfile <<std::fixed<<setprecision(15)<< "Reqiured Probability: " << (long double)prob / total<<"\n";
    cout <<std::fixed<<setprecision(15)<< "Reqiured Probability: " << (long double)prob / total<<"\n";
    myfile.close();
    return 0;
}