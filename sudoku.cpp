#include <fstream>
#include <iostream>

using namespace std;

ifstream input("sudoku.inp");
ofstream output("sudoku.out");

int num[9][9];
int abc[9][9];
bool garo[9][9];
bool sero[9][9];
bool alpha[9][9];
bool division[9][9];
bool a;
bool en;
void solve(int x, int y) {
    for (int i = 0; i < 9; i++) {
        if (num[x][y] == 0) {
            if ((garo[x][i] == 0) && (sero[y][i] == 0) && (alpha[abc[x][y] - 'a'][i] == 0)) {
                num[x][y] = i + 1;
                garo[x][i] = 1;
                sero[y][i] = 1;
                alpha[abc[x][y] - 'a'][i] = 1;
                a = true;
                if (x == 8 && y == 8) {
                    en = true;
                    return;
                } else {
                    if (y == 8) {
                        solve(x + 1, 0);
                    } else {
                        solve(x, y + 1);
                    }
                }
                if (a == false) {
                    num[x][y] = 0;
                    garo[x][i] = 0;
                    sero[y][i] = 0;
                    alpha[abc[x][y] - 'a'][i] = 0;
                }
            }
        } else {
            if (en == true)
                return;
            if (division[x][y] == 1) {
                if (a == false) {
                    return;
                } else {
                    if (y == 8) {
                        if (x == 8) {
                            en = true;
                            return;
                        }
                        solve(x + 1, 0);
                    } else {
                        solve(x, y + 1);
                    }
                }
            }
        }
        if (i == 8 && en == false) {
            a = false;
            return;
        }
    }
    return;
}

int main() {
    int count;
    input >> count;
    int re = 1;
    while (count != 0) {
        a = true;
        en = false;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                input >> num[i][j];
                garo[i][j] = 0;
                sero[i][j] = 0;
                alpha[i][j] = 0;
                division[i][j] = 0;
            }
        }
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char v;
                input >> v;
                abc[i][j] = v;
            }
        }
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (num[i][j] != 0) {
                    int temp = abc[i][j] - 'a';
                    division[i][j] = 1;
                    alpha[temp][num[i][j] - 1] = 1;
                    garo[i][num[i][j] - 1] = 1;
                    sero[j][num[i][j] - 1] = 1;
                }
            }
        }
        solve(0, 0);
        output << "Test Case No: " << re << "\n";
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                output << num[i][j] << " ";
            }
            output << "\n";
        }
        output << "\n";
        count--;
        re++;
    }
}