#include <algorithm>
#include <fstream>
#include <iostream>

using namespace std;

ifstream input("card.inp");
ofstream output("card.out");

int DP[2][1001][1001];
int arr[1001];

int card(int turn, int x, int y) {
    if (x == y) {
        if (turn == 0)
            return arr[x];
        else
            return 0;
    }

    int &answer = DP[turn][x][y];

    if (answer != -1) {
        return answer;
    }

    if (turn == 0) {
        int t1 = card(!turn, x + 1, y) + arr[x];
        int t2 = card(!turn, x, y - 1) + arr[y];

        if (t1 > t2) {
            answer = t1;
        } else {
            answer = t2;
        }
    } else {
        int t1 = card(!turn, x + 1, y);
        int t2 = card(!turn, x, y - 1);

        if (t1 > t2) {
            answer = t2;
        } else {
            answer = t1;
        }
    }

    return answer;
}

int main() {
    int count;
    input >> count;

    while (count != 0) {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 1001; j++) {
                for (int k = 0; k < 1001; k++) {
                    DP[i][j][k] = -1;
                }
            }
        }
        int n;
        input >> n;

        for (int i = 0; i < n; i++) {
            input >> arr[i];
        }

        output << card(0, 0, n - 1) << "\n";
        count--;
    }
}
