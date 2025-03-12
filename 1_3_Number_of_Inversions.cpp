#include <iostream>
#include <vector>
using namespace std;

long long mergecount(vector<int>& a, int l , int m , int r)
{
    vector <int> num (r-l + 1);
    int i = l , j = m+ 1, k = 0;
    long long rev = 0 ;
    while (i <= m && j <= r)
    {
        if (a[i]<= a[j])
        {
            num[k++] = a[i++];
        }
        else
        {
            num[k++] = a[j++];
            rev += (m - i + 1);
        }
    }
    while (i <= m)
    {
        num[k++] = a[i++];
    }
    while (j <= r)
    {
        num[k++] = a[j++];
    }
    for (int i = 0 ; i < k ;i++)
    {
        a[l + i ] = num[i];
    }
    return rev;
}
long long mcsort(vector<int>&a , int l , int r )
{
    long long rev = 0 ;
    if (l < r)
    {
        int m = l + (r - l )/2;
        rev += mcsort(a, l , m);
        rev += mcsort(a, m+1,r);
        rev += mergecount (a , l ,m , r);
    }
    return rev;
}
int main() 
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
     {
        cin >> a[i];
    }
    long long rev = mcsort(a, 0 , n -1);
    cout << rev << endl;
    return 0;
}