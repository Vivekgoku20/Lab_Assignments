#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll ncr(ll n, ll r)
{
    if (n < r)
    {
        return (-1);
    }
    ll k = min(n - r, r);
    ll ans = 1;
    for (ll i = 0; i < k; i++)
    {
        ans = ans * (n - i);
        ans = ans / (i + 1);
    }
    return (ans);
}

int main()
{
    ofstream myfile;
    myfile.open("181IT251_IT302_P3_Output_TC6.txt");
    ll r, m, n;
    cout << "\nEnter r : ";
    cin >> r;
    cout << "\nEnter m : ";
    cin >> m;
    cout << "\nEnter n : ";
    cin >> n;
    ll sum = 0;
    for (ll x = 0; x <= n; x++)
    {
        ll temp1 = ncr(x, r);
        if (temp1 < 0)
        {
            cout << "Function f(" << x << ") is invalid"
                 << "\n";
            myfile << "Function f(" << x << ") is invalid"
                   << "\n";
            continue;
        }
        ll temp2 = ncr(m, m - x);
        if (temp2 < 0)
        {
            cout << "Function f(" << x << ") is invalid "
                 << "\n";
            myfile << "Function f(" << x << ") is invalid "
                   << "\n";
            continue;
        }
        cout << " Fuction f(" << x << ") = " << temp1 * temp2 << "*c"
             << "\n";
        myfile << " Fuction f(" << x << ") = " << temp1 * temp2 << "*c"
               << "\n";
        sum = sum + (temp1 * temp2);
    }
    if (sum == 0)
    {
        cout << "Invalid test case Given"
             << "\n";
        myfile << "Invalid test case Given"
               << "\n";
    }
    else
    {
        cout << "c = " << (float)1 / sum << "\n";
        myfile << "c = " << (float)1 / sum << "\n";
    }
    myfile.close();
    return (0);
}
