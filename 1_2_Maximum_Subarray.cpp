#include <iostream>
#include <climits> 
using namespace std;
int main()
{
    int n;
    cin >> n;
    int sa[n];
    for (int i = 0; i < n; i++) 
    {
        cin >> sa[i]; 
    }
    int max = INT_MIN; 
    int c = 0;
    for (int i = 0; i < n; i++) 
    {
        c += sa[i];
        if (c > max)
        {
            max = c; 
        }
        if (c < 0) 
        {
            c = 0; 
        }
    }
    cout << max << endl; 
    return 0;
}