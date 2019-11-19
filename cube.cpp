#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int min(int a, int b) { return a < b ? a : b; }

ifstream input("cube.inp");
ofstream output("cube.out");
int dp[201][201][201];
int solve(int x, int y, int z) {
    if (x == y && y == z) {
        return dp[x][y][z] = 1;
    }
    if (x < 0 || y < 0 || z < 0) {
        return 9000000;
    }
    int &result = dp[x][y][z];
    if(result != -1){
        return result;
    }
    result = x * y * z;
    for (int z2 = 1; z2 <= (z + 1) / 2; z2++) {
        result = min(result, solve(x, y, z2) + solve(x, y, z - z2));
    }
    for (int y2 = 1; y2 <= (y + 1) / 2; y2++) {
        result = min(result, solve(x, y2, z) + solve(x, y - y2, z));
    }
    for (int x2 = 1; x2 <= (x + 1) / 2; x2++) {
        result = min(result, solve(x2, y, z) + solve(x - x2, y, z));
    }
    return result;
}

int main() {
    int count;
    input >> count;
    memset(dp, -1, sizeof dp);
    int a, b, c;
    for (int i = 0; i < count; i++) {
        input >> a >> b >> c;
        output << solve(a, b, c) << "\n";
    }
}