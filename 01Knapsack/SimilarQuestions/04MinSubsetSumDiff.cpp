#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> W(n, 0);

    int target = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> W[i];
        target += W[i];
    }


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

    int min = INT_MAX;

    for(int i = 0; i < target/2; i++){
        if(table[n][i] == 1 && table[n][target-i] == 1)
        {
            if(min > target-2*i)
            min = target-2*i;
        }
    }

    if(min != INT_MAX)
    cout << "The min subset difference is : " << min << endl;
}