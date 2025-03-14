#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct gas 
{
    int start;
    int end;
};
bool comp(const gas &a, const gas &b) 
{
    return a.end < b.end;
}
int main() 
{
    int n;
    cin >> n; 
    vector<gas> g(n);
    for (int i = 0; i < n; i++) 
    {
        cin >> g[i].start >> g[i].end;
    }
    sort(g.begin(), g.end(), comp);
    int mgas = 0;
    int final = -1;
    for (int i = 0; i < n; i++) 
    {
        if (g[i].start >= final) 
        {
            mgas++;
            final = g[i].end;
        }
    }
    cout << mgas << endl;
    return 0;
}