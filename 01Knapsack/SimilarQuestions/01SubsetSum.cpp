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

    vector<vector<int>> table(n + 1, vector<int>(target + 1, 1));

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= target; j++)
        {
            if (i == 0)
            {
                table[i][j] = 0;
                continue;
            }

            if (W[i] > j)
                table[i][j] = table[i - 1][j];
            else
            {
                table[i][j] = table[i - 1][j - W[i - 1]] || table[i - 1][j];
                cout << table[i][j] << endl;
            }
        }
    }

    if (table[n][target])
        cout << "The subset is present.";
    else
        cout << "The subset is not present";
}