#include<bits/stdc++.h>
using namespace std;

int KnapsackProb(vector<vector<int>> &table, vector<int> W, vector<int> C, int t, int n) {
    if(t == 0 || n == 0) return 0;
    if(W[n-1] > t)
    return KnapsackProb(table, W, C, t, n-1); // An imp condn to keep in mind...
    return max(C[n-1]+KnapsackProb(table, W, C, t-W[n-1], n-1), KnapsackProb(table, W, C, t, n-1));
}

int main() {
    int n;
    cin >> n;

    vector<int> W(n, 0);
    vector<int> C(n, 0);

    for(int i = 0; i < n; i++)
    {
        cin >> W[i] >> C[i];
    }

    int target;
    cin >> target;

    vector<vector<int>> table(n+1, vector<int>(target+1, -1));

    cout << "The answer is : " << KnapsackProb(table, W, C, target, n);
}