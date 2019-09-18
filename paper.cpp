#include <algorithm>
#include <fstream>
#include <functional>
#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

ifstream input("paper.inp");
ofstream output("paper.out");

vector < pair< pii, pii > > v;
vector < pair< pii, pii > > w;
vector < int > h;

bool compare(pair<pii, pii> a, pair<pii, pii> b) {
	if (a.first.first == b.first.first) {
		return a.first.second < b.first.second;
	}
	else {
		return a.first.first < b.first.first;
	}
}

void check();
void check2();

int temp;
int rs1, rs2, rs3;
int a;
// first.first = left, first.second = right, second.first = top, second.second = bottom
void check() {
	while (a != v.size()) {
		for (int i = a + 1; i < v.size(); i++) {
			if (v[a].first.first < v[i].first.second && v[a].first.second > v[i].first.first && v[a].second.first > v[i].second.second && v[a].second.second < v[i].second.first) {
				w.push_back({ {v[i].first.first, v[i].first.second}, {v[i].second.first, v[i].second.second} });
			}
		}
		h.push_back(v[a].second.first);
		h.push_back(v[a].second.second);
		for (int i = 0; i < w.size(); i++) {
			if (w[i].second.first <= v[a].second.first) {
				h.push_back(w[i].second.first);
			}
			if (w[i].second.second >= v[a].second.second) {
				h.push_back(w[i].second.second);
			}
		}
		sort(h.begin(), h.end(), greater<int>());
		h.erase(unique(h.begin(), h.end()), h.end());
		sort(w.begin(), w.end(), compare);
		if (w.size() == 0) {
			rs3++;
			h.clear();
		}
		else {
			check2();
		}
		a++;
	}
}

void check2() {
	for (int i = 0; i < h.size() - 1; i++) {
		int h1 = h[i]; // top
		int h2 = h[i + 1]; // bottom 
		int w1 = 2000000001;
		int w2 = -2000000001;
		int temp=0;
		for (int j = 0; j < w.size(); j++) {
			if (w[j].second.first >= h1 && w[j].second.second <= h2) {
				if(temp == 0){
					if (w1 >= w[j].first.first) {
						w1 = w[j].first.first;
					}
					if (w2 <= w[j].first.second) {
						w2 = w[j].first.second;
					}
					temp++;
				}
				else{
					if(w[j].first.first <= w2 && w2 <= w[j].first.second){
						w2 = w[j].first.second;
					}
				}
			}
		}
		if (w1 <= v[a].first.first && w2 >= v[a].first.second) {
			continue;
		}
		else {
			rs2++;
			w.clear();
			h.clear();
			return;
		}
	}
	rs1++;
	w.clear();
	h.clear();
	return;
}

int main() {
	int count;
	input >> count;
	temp = count;
	while (count != 0) {
		int a, b, w, h;
		input >> a >> b >> w >> h;
		v.push_back({ {a, a + w}, {b + h, b} });
		count--;
	}
	check();
	output << rs1 << " " << rs2 << " " << rs3;
}