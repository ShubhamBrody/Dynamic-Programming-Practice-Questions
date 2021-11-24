#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> W(n, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> W[i];
    }

    int target;
    cin >> target;

    vector<vector<int>> table(n + 1, vector<int>(target+1));

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= target; j++)
        {
            if(j == 0)
            {
                table[i][0] = 1;
                continue;
            }

            if (i == 0)
            {
                table[0][j] = 0;
                continue;
            }

            if (W[i - 1] > j)
                table[i][j] = table[i - 1][j];
            if(j>=W[i-1])
            {
                table[i][j] = table[i - 1][j] || table[i - 1][j - W[i - 1]];
            }
        }
    }

    if (table[n][target])
        cout << "The subset is present.";
    else
        cout << "The subset is not present";
}