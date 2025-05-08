#include <iostream>
#include <vector>
#include <climits>
using namespace std;

typedef long long ll;

int main() 
{
    int n, m;
    ll k;
    cin >> n >> m >> k;
    
    vector<vector<ll>> matrix(n, vector<ll>(m));
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            cin >> matrix[i][j];
        }
    }
    vector<vector<ll>> dp(n, vector<ll>(m, LLONG_MAX));
    for (int i = 0; i < n; i++) 
    {
        dp[i][0] = matrix[i][0];
    }
    for (int j = 1; j < m; j++) 
    {
        for (int i = 0; i < n; i++) 
        {
            int up = (i - 1 + n) % n;
            int straight = i;
            int down = (i + 1) % n;
            ll min_prev = min(dp[up][j-1], min(dp[straight][j-1], dp[down][j-1]));
            dp[i][j] = min_prev + matrix[i][j];
        }
    }
    ll min_cost = LLONG_MAX;
    for (int i = 0; i < n; i++) 
    {
        if (dp[i][m-1] < min_cost) 
        {
            min_cost = dp[i][m-1];
        }
    }
    if (min_cost <= k) 
    {
        cout << min_cost << endl;
    } 
    else 
    {
        cout << "RE: START :<" << endl;
    }
    return 0;
}