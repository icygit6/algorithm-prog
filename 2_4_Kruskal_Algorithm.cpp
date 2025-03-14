#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct e 
{
    int u, v, w;
};
bool comp(const e &a, const e &b) 
{
    return a.w < b.w;
}
vector<int> par;
int find(int x) 
{
    if (par[x] != x) 
    {
        par[x] = find(par[x]);
    }
    return par[x];
}
void unite(int x, int y) 
{
    int rx = find(x);
    int ry = find(y);
    if (rx != ry) 
    {
        par[ry] = rx;
    }
}

int main()
 {
    int n, m;
    cin >> n >> m; 
    vector<e> ed(m);
    for (int i = 0; i < m; i++) 
    {
        cin >> ed[i].u >> ed[i].v >> ed[i].w;
    }
    sort(ed.begin(), ed.end(), comp);
    par.resize(n);
    for (int i = 0; i < n; i++) 
    {
        par[i] = i;
    }
    int ttl = 0; 
    for (const e &edge : ed) 
    {
        int u = edge.u;
        int v = edge.v;
        int w = edge.w;
        if (find(u) != find(v)) 
        {
            unite(u, v);
            ttl += w;
        }
    }
    cout << "The cost of minimum spanning tree: " << ttl << endl;
    return 0;
}