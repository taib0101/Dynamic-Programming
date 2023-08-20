/* 
    I seek refused with Allah, from the accursed devil
    In the name of Allah, the entirely Merciful,the Specially Merciful
 */
/* Limitation of recursion for 0 1 knapsack is
   1. stack overflow
   2. Optimality Not Guaranteed
   3. Exponential Time Complexity(O(2^n))
   so, we need to use tabulation dp for
   optimal solution
 */
/* 
    n = 4
    item    : 1 2 3 4
    weight  : 2 4 3 1
    profit  : 5 10 9 6
    bag of weight = 6
 */
#include<bits/stdc++.h>
using namespace std;
int dp[50][50];
int p[50]; // array of profit
int wi[50]; // array of weight
int recursion_dp(int n,int w)
{
    int result;
    if(n == 0 || w == 0)
        return 0;
    if(dp[n][w] != -1)
        return dp[n][w];
    if(wi[n] <= w)
        result = max(recursion_dp(n-1,w-wi[n])+p[n],recursion_dp(n-1,w));
    else
        result = recursion_dp(n-1,w);
    dp[n][w] = result;
    return result;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        memset(wi,0,sizeof(wi));
        memset(p,0,sizeof(p));
        for(int i = 1; i <= n; ++i)
            cin >> wi[i];
        for(int i = 1; i <= n; ++i)
            cin >> p[i];
        int w; // weight of bag
        cin >> w;
        for(int i = 1; i <= n; ++i)
        {
            for(int j = 1; j <= w; ++j)
                dp[i][j] = -1;
        }
        cout << "Maximum profit = " << recursion_dp(n,w) << endl;
    }
    return 0;
}
