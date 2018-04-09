#include<iostream>
#include<cstring>
using namespace std;

int main(int argc, char *argv[])
{
    int C, G, c[25], g[25];
    cin >> C >> G;
    for (int i = 1; i <= C; i++)
        cin >> c[i];
    for (int i = 1; i <= G; i++)
        cin >> g[i];

    int dp[22][15020];
    memset(dp, 0, sizeof(dp));
    dp[0][7500] = 1;

    for (int i = 1; i <= G; i++) {
        for (int j = 0; j <= 15000; j++) {
            if (dp[i - 1][j]) {
                for (int k = 1; k <= C; k++) {
                    dp[i][j + g[i] * c[k]] += dp[i - 1][j];
                }
            }
        }
    }

    cout << dp[G][7500] << endl;

    return 0;
}