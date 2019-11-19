#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

ifstream input("block.inp");
ofstream output("block.out");

vector< pair < pii, pii > > v;
int x_max, y_max;
int s_count;
bool cmp(const pair<pii, pii> &a, const pair<pii, pii> &b) {
	if (a.second.first != b.second.first) {
		return a.second.first < b.second.first;
	}
	else {
		return a.first.first < b.first.first;
	}
}
bool cmp2(const pair<pii, pii> &a, const pair<pii, pii> &b) {
	if (a.first.first != b.first.first) {
		return a.first.first < b.first.first;
	}
	else {
		return a.second.first < b.second.first;
	}
}
void solve() {
	sort(v.begin(), v.end(), cmp);
	int count = 0;
	while (count != v.size()) {
		int up = 0;
		for (int i = 0; i < count; i++) {
			if (v[i].first.first < v[count].first.second && v[i].first.second > v[count].first.first) {
				if (up < v[i].second.second) {
					up = v[i].second.second;
				}
			}
		}
		int tmp = v[count].second.first - up;
		v[count].second.first -= tmp;
		v[count].second.second -= tmp;
		if (v[count].second.second > y_max) {
			y_max = v[count].second.second;
		}
		if (tmp != 0) {
			s_count++;
		}
		count++;
	}
	sort(v.begin(), v.end(), cmp2);
	count = 0;
	while (count != v.size()) {
		int right = 0;
		for (int i = 0; i < count; i++) {
			if (v[i].second.first < v[count].second.second && v[i].second.second > v[count].second.first) {
				if (right < v[i].first.second) {
					right = v[i].first.second;
				}
			}
		}
		int tmp = v[count].first.first - right;
		v[count].first.first -= tmp;
		v[count].first.second -= tmp;
		if (v[count].first.second > x_max) {
			x_max = v[count].first.second;
		}
		if (tmp != 0) {
			s_count++;
		}
		count++;
	}
	return;
}

int main() {
	int count;
	input >> count;
	while (count != 0) {
		int cnt;
		input >> cnt;
		int x_temp = 0;
		int y_temp = 0;
		for (int i = 0; i < cnt; i++) {
			int a, b, c, d;
			input >> a >> b >> c >> d;
			v.push_back({ {a, c}, {b, d} });
		}
		while (1) {
			x_max = 0;
			y_max = 0;
			solve();
			if (s_count == 0) {
				break;
			}
			s_count = 0;
		}
		output << x_max << " " << y_max << "\n";
		v.clear();
		count--;
	}
}