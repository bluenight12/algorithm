#include <cstring>
#include <fstream>
#include <iostream>

using namespace std;

ifstream input("coinmove.inp");
ofstream output("coinmove.out");

int dp[1000001][8];
int solve(int p, int k, int s) {
    for (int i = 1; i < 8; i++) {
        dp[0][i] = -1;
    }
    for (int i = 1; i <= s; i++) {
        for (int j = 1; j <= k; j++) {
            int temp = 1;
            for (int x = 1; x <= k; x++) {
                if (x == j) {
                    continue;
                }
                if (i - j < 0) {
                    temp = -1;
                    break;
                }
                if (dp[i - j][x] == 1 || (i-j !=0) &&((i - j) % p)==0) {
                    temp = -1;
                    break;
                }
            }
            dp[i][j] = temp;
        }
    }
    for (int i = 1; i <= k; i++) {
        if (dp[s][i] == 1) {
            return s - i;
        }
    }
    return -1;
}

int main() {
    int count;
    input >> count;
    while (count != 0) {
        int p, k, s;
        input >> p >> k >> s;
        memset(dp, 0, sizeof dp);
        output << solve(p, k, s) << "\n";
        count--;
    }
}