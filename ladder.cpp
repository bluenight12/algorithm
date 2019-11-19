#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

vector< pair<pii, pii> > v;
int *arr;
int result;
bool compare(pair<pii, pii> a, pair<pii, pii> b) {
	if (a.first.first == b.first.first) {
		return a.first.second > b.first.second;
	}
	else {
		return a.first.first < b.first.first;
	}
}

void ladder(int a, int b) {
	for (int i = 0; i < v.size(); i++) {
		if (v[i].first.first == a && v[i].first.second == b) {
			i++;
			if (i == v.size() || a != v[i].first.first) {
				result = a;
				return;
			}
			else {
				ladder(v[i].second.first, v[i].second.second);
			}
		}
	}
	return;
}

int main() {
	ifstream input("ladder.inp");
	ofstream output("ladder.out");

	int l;
	input >> l;
	arr = new int[l];
	while (1) {
		int a, b, c, d;
		input >> a >> b >> c >> d;
		if (a == 0 && b == 0 && c == 0 && d == 0)
			break;
		v.push_back({ {a, b}, {c, d} });
		v.push_back({ {c, d}, {a, b} });
	}
	sort(v.begin(), v.end(), compare);
	for (int i = 0; i < l; i++) {
		for (int j = 0; j < v.size(); j++) {
			if (v[j].first.first == i) {
				ladder(v[j].second.first, v[j].second.second);
				arr[result] = i;
				break;
			}
		}
	}
	for (int i = 0; i < l; i++) {
		output << arr[i] << " ";
	}
}