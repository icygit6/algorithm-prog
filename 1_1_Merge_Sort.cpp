#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;
int main()
{
    vector<int> arr;
    string input;
    getline(cin, input);
    stringstream ss(input);
    int num;
    while (ss >> num)
    {
        arr.push_back(num);
    }
    int n = arr.size();
    vector<int> t(n); 
    for (int s = 1; s < n; s *= 2)
    {
        for (int l = 0; l < n; l += 2 * s)
        {
            int mid = min(l + s, n);
            int r = min(l + 2 * s, n);

            int i = l, j = mid, k = l;
            while (i < mid && j < r)
            {
                if (arr[i] < arr[j])
                {
                    t[k++] = arr[i++];
                }
                else
                {
                    t[k++] = arr[j++];
                }
            }
            while (i < mid)
            {
                t[k++] = arr[i++];
            }
            while (j < r)
            {
                t[k++] = arr[j++];
            }

            for (int m = l; m < r; m++)
            {
                arr[m] = t[m];
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}