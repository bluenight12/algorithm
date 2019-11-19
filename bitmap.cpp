#include <fstream>
#include <iostream>
#include <queue>
#include <string>

using namespace std;

ifstream input("bitmap.inp");
ofstream output("bitmap.out");

int arr[200][200];
string s;
queue<int> q;
int temp;
int d1, d2;
void bset();
void btod(int m, int n, int x, int y);
void dset();
void dtob(int m, int n, int x, int y);

void bset() {
    int count = 2;
    int x, y;
    while (1) {
        if (s.at(count) == 32) {
            break;
        } else {
            count++;
        }
    }
    if (count == 3) {
        x = s.at(2) - 48;
    } else if (count == 4) {
        x = (s.at(2) - 48) * 10 + s.at(3) - 48;
    } else {
        x = (s.at(2) - 48) * 100 + (s.at(3) - 48) * 10 + s.at(4) - 48;
    }
    count++;
    if (s.size() - count == 1) {
        y = s.at(count) - 48;
    } else if (s.size() - count == 2) {
        y = (s.at(count) - 48) * 10 + s.at(count + 1) - 48;
    } else {
        y = (s.at(count) - 48) * 100 + (s.at(count + 1) - 48) * 10 + s.at(count + 2) - 48;
    }
    while (1) {
        getline(input, s);
        if (s.size() == 50) {
            for (int i = 0; i < s.size(); i++) {
                q.push(s[i] - 48);
            }
        } else {
            if (s.at(0) == 'B' || s.at(0) == '#') {
                break;
            } else if (s.size() > 4) {
                if (s.at(0) == 'D') {
                    break;
                } else {
                    for (int i = 0; i < s.size(); i++) {
                        q.push(s[i] - 48);
                    }
                    getline(input, s);
                    break;
                }
            } else {
                for (int i = 0; i < s.size(); i++) {
                    q.push(s[i] - 48);
                }
                getline(input, s);
                break;
            }
        }
    }
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            arr[i][j] = q.front();
            q.pop();
        }
    }
    output << "D " << x << " " << y << "\n";
    temp = 0;
    btod(x, y, 0, 0);
    output << "\n";
}
void dset() {
    int count = 2;
    int x, y;
    while (1) {
        if (s.at(count) == 32) {
            break;
        } else {
            count++;
        }
    }
    if (count == 3) {
        x = s.at(2) - 48;
    } else if (count == 4) {
        x = (s.at(2) - 48) * 10 + s.at(3) - 48;
    } else {
        x = (s.at(2) - 48) * 100 + (s.at(3) - 48) * 10 + s.at(4) - 48;
    }
    count++;
    if (s.size() - count == 1) {
        y = s.at(count) - 48;
    } else if (s.size() - count == 2) {
        y = (s.at(count) - 48) * 10 + s.at(count + 1) - 48;
    } else {
        y = (s.at(count) - 48) * 100 + (s.at(count + 1) - 48) * 10 + s.at(count + 2) - 48;
    }
    while (1) {
        getline(input, s);
        if (s.size() == 50) {
            for (int i = 0; i < s.size(); i++) {
                if (s[i] == 'D') {
                    q.push(2);
                } else {
                    q.push(s[i] - 48);
                }
            }
        } else {
            if (s.size() > 1) {
                if (s.at(1) == ' ')
                    break;
            }
            if (s.at(0) == '#' || s.at(0) == 'B') {
                break;
            } else {
                for (int i = 0; i < s.size(); i++) {
                    if (s[i] == 'D') {
                        q.push(2);
                    } else {
                        q.push(s[i] - 48);
                    }
                }
                getline(input, s);
                break;
            }
        }
    }
    d1 = x;
    d2 = y;
    output << "B " << x << " " << y << "\n";
    dtob(x, y, 0, 0);
}
void btod(int m, int n, int x, int y) {
    if (m == 0 || n == 0) {
        return;
    }
    if (m == 1 && n == 1) {
        if (arr[x][y] == 1)
            output << 1;
        else
            output << 0;
        temp++;
        if (temp == 50) {
            output << "\n";
            temp = 0;
        }
        return;
    }
    bool check = true;
    int target = arr[x][y];
    for (int i = x; i < x + m; i++) {
        for (int j = y; j < y + n; j++) {
            if (target != arr[i][j]) {
                check = false;
            }
        }
    }
    if (check) {
        if (target == 1)
            output << 1;
        else
            output << 0;
        temp++;
        if (temp == 50) {
            output << "\n";
            temp = 0;
        }
    } else {
        int a, b, c, d;
        if (m % 2 == 0) {
            a = m / 2;
            c = 0;
        } else {
            a = m / 2 + 1;
            c = 1;
        }
        if (n % 2 == 0) {
            b = n / 2;
            d = 0;
        } else {
            b = n / 2 + 1;
            d = 1;
        }
        output << "D";
        temp++;
        if (temp == 50) {
            output << "\n";
            temp = 0;
        }
        btod(a, b, x, y);
        btod(a, b - d, x, y + b);
        btod(a - c, b, x + a, y);
        btod(a - c, b - d, x + a, y + b);
    }
    return;
}

void dtob(int m, int n, int x, int y) {
    if (q.empty())
        return;
    if (m == 0 || n == 0) {
        return;
    }
    if (q.front() == 2) {
        q.pop();
        int a, b, c, d;
        if (m % 2 == 0) {
            a = m / 2;
            c = 0;
        } else {
            a = m / 2 + 1;
            c = 1;
        }
        if (n % 2 == 0) {
            b = n / 2;
            d = 0;
        } else {
            b = n / 2 + 1;
            d = 1;
        }
        dtob(a, b, x, y);
        dtob(a, b - d, x, y + b);
        dtob(a - c, b, x + a, y);
        dtob(a - c, b - d, x + a, y + b);
    } else {
        int target = q.front();
        q.pop();
        for (int i = x; i < x + m; i++) {
            for (int j = y; j < y + n; j++) {
                arr[i][j] = target;
            }
        }
    }
    return;
}

int main() {
    getline(input, s);
    while (1) {
        if (s.at(0) == '#') {
            break;
        } else if (s.at(0) == 'B') {
            bset();
        } else {
            dset();
            int ct = 0;
            for (int i = 0; i < d1; i++) {
                for (int j = 0; j < d2; j++) {
                    output << arr[i][j];
                    ct++;
                    if (ct == 50) {
                        output << "\n";
                        ct = 0;
                    }
                }
            }
            if (ct != 0)
                output << "\n";
        }
    }
}