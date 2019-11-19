#include <fstream>
#include <iostream>

using namespace std;

ifstream input("go.inp");
ofstream output("go.out");

char **arr;
int **visit;
int cnt;
int temp;
char tmp;
int black, white;
void check(int a, int b) {
    if (visit[a][b] == 0) {
        if (arr[a][b] == '.') {
            visit[a][b] = 1;
            if (temp != -1) {
                temp++;
            }
            if (a+1 != cnt) {
                if (arr[a + 1][b] == '.') {
                    check(a + 1, b);
                } else {
                    if (tmp == ' ') {
                        tmp = arr[a + 1][b];
                    } else {
                        if (arr[a + 1][b] != tmp)
                            temp = -1;
                    }
                }
            }
            if (b+1 != cnt) {
                if (arr[a][b + 1] == '.') {
                    check(a, b + 1);
                } else {
                    if (tmp == ' ') {
                        tmp = arr[a][b + 1];
                    } else {
                        if (arr[a][b + 1] != tmp)
                            temp = -1;
                    }
                }
            }
            if (a != 0) {
                if (arr[a - 1][b] == '.') {
                    check(a - 1, b);
                } else {
                    if (tmp == ' ') {
                        tmp = arr[a - 1][b];
                    } else {
                        if (arr[a - 1][b] != tmp)
                            temp = -1;
                    }
                }
            }
            if (b != 0) {
                if (arr[a][b - 1] == '.') {
                    check(a, b - 1);
                } else {
                    if (tmp == ' ') {
                        tmp = arr[a][b - 1];
                    } else {
                        if (arr[a][b - 1] != tmp)
                            temp = -1;
                    }
                }
            }
        }
    }
}

int main() {
    input >> cnt;

    arr = new char *[cnt];
    visit = new int *[cnt];
    for (int i = 0; i < cnt; i++) {
        arr[i] = new char[cnt];
        visit[i] = new int[cnt];
    }
    char c;
    for (int i = 0; i < cnt; i++) {
        for (int j = 0; j < cnt; j++) {
            input >> c;
            arr[i][j] = c;
            visit[i][j] = 0;
        }
    }
    for (int i = 0; i < cnt; i++) {
        for (int j = 0; j < cnt; j++) {
            temp = 0;
            tmp = ' ';
            check(i, j);
            if (temp != -1) {
                if (tmp == 'B') {
                    black += temp;
                } else if (tmp == 'W') {
                    white += temp;
                }
            }
        }
    }
    output << black << " " << white;
}