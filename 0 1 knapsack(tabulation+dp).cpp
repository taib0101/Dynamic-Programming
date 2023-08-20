/* 
    I seek refused with Allah, from the accursed devil
    In the name of Allah, the entirely Merciful,the Specially Merciful
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

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int wi[50],p[50];
        for(int i = 1; i <= n; ++i)
            cin >> wi[i];
        for(int i = 1; i <= n; ++i)
            cin >> p[i];
        int dp[50][50];
        int w;
        cin >> w;
        for(int i = 1; i <= n; ++i)
        {
            for(int ww = 1; ww <= w; ++ww)
            {
                if(i == 0 || ww == 0)
                    dp[i][ww] = 0;
                if(wi[i] <= ww)
                    dp[i][ww] = max(dp[i-1][ww-wi[i]] + p[i],dp[i-1][ww]);
                else
                    dp[i][ww] = dp[i-1][ww];
            }
        }
        cout << "Maximum Profit = " << dp[n][w] << endl;
    }
    return 0;
}