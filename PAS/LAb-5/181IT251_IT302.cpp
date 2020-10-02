#include <bits/stdc++.h>
using namespace std;
int main()
{
    ofstream myfile;
    myfile.open("181IT251_IT302_P6_Output_TC6.txt");
    int x = 2;
    int i,j,y = 3;
    vector<int> xs(x), ys(y);
    cout << "Enter the values of x \n";
    for (int i = 0; i < x; i++)
    {
        cin >> xs[i];
    }
    cout << "Enter the values of y \n";
    for ( i = 0; i < y; i++)
    {
        cin >> ys[i];
    }
    vector<vector<double>> v(x, vector<double>(y));
    cout << "Enter the Value in table :  \n";
    for ( i = 0; i < x; i++)
    {
        for ( j = 0; j < y; j++)
        {
            double p;
            cin >> p;
            if (p > 1)
            {
                cout << "Given Input is Invalid "
                     << "\n";
                myfile << "Given Input is invalid";
                myfile.close();
                return 0;
            }
            else
                v[i][j] = p;
        }
    }
    vector<double> ans1(x), ans2(y);
    for ( i = 0; i < x; i++)
    {
        double sum = 0;
        for ( j = 0; j < y; j++)
        {
            sum = sum + v[i][j];
        }
        ans1[i] = sum;
    }
    for ( i = 0; i < y; i++)
    {
        double sum = 0;
        for ( j = 0; j < x; j++)
        {
            sum = sum +  v[j][i];
        }
        ans2[i] = sum;
    }
    double meanx = 0;
    for ( i = 0; i < x; i++)
    {
        meanx += xs[i] * ans1[i];
    }
    cout << "Mean of X is : " << meanx << "\n";
    myfile << "Mean of X is : " << meanx << "\n";
    double meany = 0;
    for ( i = 0; i < y; i++)
    {
        meany += ys[i] * ans2[i];
    }
    cout << "Mean of Y is : " << meany << "\n";
    myfile << "Mean of Y is : " << meany << "\n";
    double gx = 0;
    for ( i = 0; i < xs.size(); i++)
    {
        for ( j = 0; j < ys.size(); j++)
        {
            gx += v[i][j] * (xs[i] * ys[j]);
            cout << gx << " ";
        }
    }
    cout << "\n";
    myfile << "\n";
    cout << "Value G(x,y)=XY  is : " << gx << "\n";
    myfile << "Value G(x,y)=XY  is : " << gx << "\n";
    cout << " Covariance of the X and Y is : " << gx - meanx * meany << "\n";
    myfile << "Covariance of the X and Y is : " << gx - meanx * meany << "\n";
    myfile.close();
    return 0;
}


