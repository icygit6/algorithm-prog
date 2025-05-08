#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() 
{
    int n, w;
    cin >> n >> w;
    vector<int> weight(n + 1), value(n + 1);
    
    for (int i = 1; i <= n; i++) 
    {
        cin >> weight[i] >> value[i];
    }
    
    vector<long long> dp(w + 1, 0);
    
    for (int i = 1; i <= n; i++) 
    {
        for (int j = w; j >= weight[i]; j--) 
        {
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
        }
    }
    cout << dp[w] << "\n";
    return 0;
}