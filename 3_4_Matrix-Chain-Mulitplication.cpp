#include <iostream>
#include <vector>
#include <climits>
using namespace std;

typedef long long ll;

int main() 
{
    int n;
    cin >> n;
    vector<int> dim(n + 1);
    for (int i = 0; i < n; i++) 
    {
        int r, c;
        cin >> r >> c;
        if (i == 0) 
        {
            dim[i] = r;
        }
        dim[i + 1] = c;
    }
    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, 0));
    for (int i = n - 1; i >= 1; i--) 
    {
        for (int j = i + 1; j <= n; j++) 
        {
            dp[i][j] = LLONG_MAX;
            
            for (int k = i; k < j; k++) 
            {
                ll cost = dp[i][k] + dp[k + 1][j] + (ll)dim[i - 1] * dim[k] * dim[j];
                if (cost < dp[i][j]) 
                {
                    dp[i][j] = cost;
                }
            }
        }
    }

    cout << dp[1][n] << "\n";
    return 0;
}