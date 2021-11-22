#include<bits/stdc++.h>
using namespace std;

int KnapsackProb(vector<int> W, vector<int> C, int t, int i = 0) {
    if(t==0 || W.size() == 0) return 0;
    if(i == W.size()) return 0;
    if(W[i] > t)
    return KnapsackProb(W, C, t, i+1); // An imp condn to keep in mind...
    return max(C[i]+KnapsackProb(W, C, t-W[i], i+1), KnapsackProb(W, C, t, i+1));
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

    cout << "The answer is : " << KnapsackProb(W, C, target);
}