#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct order 
{
    int in;
    int d;
    int pen;
    double rat;
};
bool comp(const order &a, const order &b) 
{
    if (a.rat == b.rat) 
    {
        return a.in < b.in; 
    }
    return a.rat > b.rat;
}

int main()
 {
    int n;
    cin >> n;
    vector<order> orders(n);
    for (int i = 0; i< n; i++)
    {
        cin >> orders[i].d >> orders[i].pen;
        orders[i].in = i + 1; 
        orders[i].rat = (double)orders[i].pen / orders[i].d;
    }
    sort(orders.begin(), orders.end(), comp);
    for (int i = 0; i < n; i++) 
    {
        cout << orders[i].in <<" ";
    }
    cout << endl;
    return 0;
}