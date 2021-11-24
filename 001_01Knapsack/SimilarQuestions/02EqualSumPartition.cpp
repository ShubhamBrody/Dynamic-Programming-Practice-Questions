#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> N(n, 0);
    int sum = 0;

    for(int i = 0; i < n; i++)
    {
        cin >> N[i];
        sum+=N[i];
    }

    if(sum % 2 != 0) 
    {
        cout << "Bisection Impossible" << endl;
        return 0;
    }

    //here W is not fixed...
    int target = sum/2;

    cout << target << endl;

    vector<vector<int>> table(n + 1, vector<int>(target + 1));

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

            if (N[i - 1] > j)
                table[i][j] = table[i - 1][j];
            if (j>=N[i-1])
                table[i][j] = table[i - 1][j] || table[i - 1][j - N[i - 1]];
        }
    }
    if(table[n][target])
        cout << "The bisection is possible.";
    else
        cout << "The bsection is not possible";
}