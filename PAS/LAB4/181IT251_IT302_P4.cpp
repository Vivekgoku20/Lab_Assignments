#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define inf 1e18

ll comb(ll n, ll r)
{
    if (n < r)
    {
        return -1;
    }
    ll k = min(n - r, r);
    ll ans = 1;
    for (ll i = 0; i < k; i++)
    {
        ans *= (n - i);
        ans /= (i + 1);
    }
    return ans;
}
bool isnum(string a)
{
    ll n = a.length();
    if (!((a[0] >= '0' && a[0] <= '9') || a[0] == '-' || a[0] == '+'))
    {
        return false;
    }
    for (ll i = 1; i < n; i++)
    {
        if (a[i] < '0' || a[i] > '9')
        {
            return false;
        }
    }
    return true;
}

bool checkinput(string N, string X, string Y, string Z)
{
    if (!isnum(N))
    {
        cout << "N is not a valid input"
             << "\n";
        return false;
    }
    if (!isnum(X))
    {
        cout << "X is not a valid input"
             << "\n";
        return false;
    }
    if (!isnum(Y))
    {
        cout << "Y is not a valid input"
             << "\n";
        return false;
    }
    if (!isnum(Z))
    {
        cout << "Z is not a valid input"
             << "\n";
        return false;
    }
    ll n = stoi(N), x = stoi(X), y = stoi(Y), z = stoi(Z);
    if (n <= 0)
    {
        cout << "N has to be positive "
             << "\n";
        return false;
    }
    if (x <= 0)
    {
        cout << "X has to be positive "
             << "\n";
        return false;
    }
    if (y <= 0)
    {
        cout << "Y has to be positive "
             << "\n";
        return false;
    }
    if (z <= 0)
    {
        cout << "Z has to be positive "
             << "\n";
        return false;
    }
    return true;
}
int main()
{
    ofstream myfile;
    myfile.open("181IT251_IT302_P4_Output_TC6.txt");
    string N, X, Y, Z;
    ll i, j;
    cout << "Enter value of N: ";
    cin >> N;
    cout << "Enter value of X: ";
    cin >> X;
    cout << "Enter value of Y: ";
    cin >> Y;
    cout << "Enter value of Z: ";
    cin >> Z;
    if (!checkinput(N, X, Y, Z))
    {
        return 0;
    }
    ll n = stoi(N), x = stoi(X), y = stoi(Y), z = stoi(Z);
    cout << "Joll probability function is  : (xCi) * (zCj) * (yC(n-i-j))/((x+y+z)Cn) where 0 <= (i+j) <= n"
         << "\n";
    myfile << "Joll probability function is  : (xCi)*(zCj)*(yC(n-i-j))/((x+y+z)Cn) where 0 <= (i+j) <= n"
           << "\n";
    vector<vector<double>> v(n + 1, vector<double>(n + 1));
    ll den = comb(x + y + z, n);
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= n; j++)
        {
            if (i <= x && j <= z && (n - i - j) <= y && (n - i - j) >= 0)
            {
                ll ft = comb(x, i);
                ll st = comb(z, j);
                ll tt = comb(y, n - i - j);
                v[i][j] = (double)(ft * st * tt) / den;
                cout << "No. of blue : No. of green ==>" << i << " : " << j << "==>" << v[i][j] << "\n";
                myfile << "No. of blue : No. of green ==>" << i << " : " << j << "==>" << v[i][j] << "\n";
            }
            else
                v[i][j] = 0;
        }
    }
    vector<double> marx(n + 1), marz(n + 1);
    for (i = 0; i <= n; i++)
    {
        double sum = 0;
        for (ll j = 0; j <= n; j++)
        {
            sum += v[i][j];
        }
        marx[i] = sum;
    }
    for (i = 0; i <= n; i++)
    {
        double sum = 0;
        for (j = 0; j <= n; j++)
        {
            sum += v[j][i];
        }
        marz[i] = sum;
    }
    cout << "Joll Probability Function table: f(x,z) where 1st row is where x=0 and z varies from 0 to n"
         << "\n";
    myfile << "Joll Probability Function table: f(x,z) where 1st row is where x=0 and z varies from 0 to n"
           << "\n";
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= n; j++)
        {
            cout << "|  " << v[i][j] << "  ";
            myfile << "|  " << v[i][j] << "  ";
        }
        cout << "\n";
        myfile << "\n";
    }
    cout << "Marginal distribution of X alone : \n";
         
    myfile << "Marginal distribution of X alone : \n";
           
    for (ll i = 0; i <= n; i++)
    {
        cout << "|  " << marx[i] << "  ";
        myfile << "|  " << marx[i] << "  ";
    }
    cout << "\n";
    myfile << "\n";
    cout << "Marginal distribution of Z alone : \n";
       
    myfile << "Marginal distribution of Z alone : \n";
           
    for (i = 0; i <= n; i++)
    {
        cout << "|  " << marz[i] << "  ";
        myfile << "|  " << marz[i] << "  ";
    }
    cout << "\n";
    myfile << "\n";
    myfile.close();
    return 0;
}

/*#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define inf 1e18

ll comb(ll n, ll r)
{
    if (n < r)
    {
        return -1;
    }
    ll k = min(n - r, r);
    ll ans = 1;
    for (ll i = 0; i < k; i++)
    {
        ans *= (n - i);
        ans /= (i + 1);
    }
    return ans;
}
bool isnum(string a)
{
    ll n = a.length();
    if (!((a[0] >= '0' && a[0] <= '9') || a[0] == '-' || a[0] == '+'))
    {
        return false;
    }
    for (ll i = 1; i < n; i++)
    {
        if (a[i] < '0' || a[i] > '9')
        {
            return false;
        }
    }
    return true;
}

bool checkinput(string N, string X, string Y, string Z)
{
    if (!isnum(N))
    {
        cout << "N is not a valid input"
             << "\n";
        return false;
    }
    if (!isnum(X))
    {
        cout << "X is not a valid input"
             << "\n";
        return false;
    }
    if (!isnum(Y))
    {
        cout << "Y is not a valid input"
             << "\n";
        return false;
    }
    if (!isnum(Z))
    {
        cout << "Z is not a valid input"
             << "\n";
        return false;
    }
    ll n = stoi(N), x = stoi(X), y = stoi(Y), z = stoi(Z);
    if (n <= 0)
    {
        cout << "N has to be positive "
             << "\n";
        return false;
    }
    if (x <= 0)
    {
        cout << "X has to be positive "
             << "\n";
        return false;
    }
    if (y <= 0)
    {
        cout << "Y has to be positive "
             << "\n";
        return false;
    }
    if (z <= 0)
    {
        cout << "Z has to be positive "
             << "\n";
        return false;
    }
    return true;
}
int main()
{
    ofstream myfile;
    myfile.open("181IT251_IT302_P4_Output_TC6.txt");
    string N, X, Y, Z;
    ll i, j;
    cout << "Enter value of N: ";
    cin >> N;
    cout << "Enter value of X: ";
    cin >> X;
    cout << "Enter value of Y: ";
    cin >> Y;
    cout << "Enter value of Z: ";
    cin >> Z;
    if (!checkinput(N, X, Y, Z))
    {
        return 0;
    }
    ll n = stoi(N), x = stoi(X), y = stoi(Y), z = stoi(Z);
    cout << "Joll probability function is  : (xCi) * (zCj) * (yC(n-i-j))/((x+y+z)Cn) where 0 <= (i+j) <= n"
         << "\n";
    myfile << "Joll probability function is  : (xCi)*(zCj)*(yC(n-i-j))/((x+y+z)Cn) where 0 <= (i+j) <= n"
           << "\n";
    vector<vector<double>> v(n + 1, vector<double>(n + 1));
    ll den = comb(x + y + z, n);
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= n; j++)
        {
            if (i <= x && j <= z && (n - i - j) <= y && (n - i - j) >= 0)
            {
                ll ft = comb(x, i);
                ll st = comb(z, j);
                ll tt = comb(y, n - i - j);
                v[i][j] = (double)(ft * st * tt) / den;
                cout << "No. of blue : No. of green ==>" << i << " : " << j << "==>" << v[i][j] << "\n";
                myfile << "No. of blue : No. of green ==>" << i << " : " << j << "==>" << v[i][j] << "\n";
            }
            else
                v[i][j] = 0;
        }
    }
    vector<double> marx(n + 1), marz(n + 1);
    for (i = 0; i <= n; i++)
    {
        double sum = 0;
        for (ll j = 0; j <= n; j++)
        {
            sum += v[i][j];
        }
        marx[i] = sum;
    }
    for (i = 0; i <= n; i++)
    {
        double sum = 0;
        for (j = 0; j <= n; j++)
        {
            sum += v[j][i];
        }
        marz[i] = sum;
    }
    cout << "Joll Probability Function table: f(x,z) where 1st row is where x=0 and z varies from 0 to n"
         << "\n";
    myfile << "Joll Probability Function table: f(x,z) where 1st row is where x=0 and z varies from 0 to n"
           << "\n";
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= n; j++)
        {
            cout << "|  " << v[i][j] << "  ";
            myfile << "|  " << v[i][j] << "  ";
        }
        cout << "\n";
        myfile << "\n";
    }
    cout << "Marginal distribution of X alone : \n";
         
    myfile << "Marginal distribution of X alone : \n";
           
    for (ll i = 0; i <= n; i++)
    {
        cout << "|  " << marx[i] << "  ";
        myfile << "|  " << marx[i] << "  ";
    }
    cout << "\n";
    myfile << "\n";
    cout << "Marginal distribution of Z alone : \n";
       
    myfile << "Marginal distribution of Z alone : \n";
           
    for (i = 0; i <= n; i++)
    {
        cout << "|  " << marz[i] << "  ";
        myfile << "|  " << marz[i] << "  ";
    }
    cout << "\n";
    myfile << "\n";
    myfile.close();
    return 0;
}
*/