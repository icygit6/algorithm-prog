#include<iostream> 
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;
struct item 
{
    int val, w ;
    double rat;
};
bool comp(const item &a, const item &b)
{
    return a.rat > b.rat ;
}
int main()
{
    int n, n1;
    cin >> n >> n1 ;
    vector<item> items(n);
    for (int i = 0 ; i < n ; i++)
    {
        cin >> items[i].val>>items[i].w;
        items[i].rat = (double)items[i].val / items[i].w;
    }
    sort(items.begin(), items.end(),comp);
    double ttl = 0.0;
    int temp = n1 ;
    for (int i = 0 ; i< n ;i++)
    {
        if (temp == 0)
        {
            break;
        }
        if (items[i].w <= temp)
        {
            ttl += items[i].val;
            temp -= items[i].w;
        }
        else
        {
            ttl += items[i].rat * temp;
            temp =0 ;
        }
    }
    cout << fixed<< setprecision(6)<< ttl <<endl;
    return 0 ;
}