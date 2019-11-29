#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

ifstream input("light.inp");
ofstream output("light.out");

vector<pii> v;

int main() {
    int count;
    input >> count;
    for (int i = 0; i < count; i++) {
        int j, k;
        input >> j >> k;
        v.push_back({j, k});
    }
    sort(v.begin(), v.end());
    int tc;
    input >> tc;
    for (int i = 0; i < tc; i++) {
        int result = 0;
        int ls, rs, mid;
        int temp = 0;
        input >> ls >> rs;
        mid = ls;
        for (int j = 0; j < v.size(); j++) {
            int left = v[j].first;
            int right = v[j].second;
            if (left <= mid) {
                if (right > temp) {
                    temp = right;
                }
            } else {
                mid = temp;
                result++;
                if (mid >= rs) {
                    break;
                }
                if (left <= mid) {
                    if (right > temp) {
                        temp = right;
                    }
                } else {
                    break;
                }
            }
            if (j == v.size() - 1 && temp >= rs) {
                result++;
            }
        }
        if (temp >= rs) {
            output << result << "\n";
        } else {
            output << "-1\n";
        }
    }
}