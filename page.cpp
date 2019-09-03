#include <algorithm>
#include <cstring>
#include <fstream>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;
int k;
ifstream input("page.inp");
ofstream output("page.out");
typedef pair<int, int> pii;
vector<pair<int, pii> > v;
class FIFO {
private:
	vector<pair<int, pii> > q;
	int a[20000];
	int cnt;
	int fault;
	int equal() {
		int first = v[cnt].second.first;
		int second = v[cnt].second.second;
		for (int i = 0; i < q.size(); i++) {
			if (q[i].second.first == first && q[i].second.second == second) {
				return 1;
			}
		}
		return 0;
	}
	int compare() {
		int temp = v[cnt].second.first;
		int j;
		int min = 10001;
		for (int i = 0; i < q.size(); i++) {
			if (q[i].second.first == temp) {
				if (min > q[i].first) {
					min = q[i].first;
					j = i;
				}
			}
		}
		return j;
	}

public:
	void set() {
		memset(a, 0, sizeof(a));
		cnt = 0;
		fault = 0;
	}
	void p_f() {
		while (1) {
			if (equal() == 1) {
				cnt++;
				if (v[cnt].second.first == -1) {
					break;
				}
				continue;
			}
			else {
				if (a[v[cnt].second.first] == k) {
					int temp = compare();
					q[temp].first = v[cnt].first;
					q[temp].second = v[cnt].second;
					fault++;
				}
				else {
					q.push_back(v[cnt]);
					a[v[cnt].second.first]++;
					fault++;
				}
				cnt++;
			}
			if (v[cnt].second.first == -1) {
				break;
			}
		}
	}
	void print() {
		int count = 0;
		output << "FIFO: " << fault << endl;
		while (1) {
			output << count << " " << q[count].second.first << " " << q[count].second.second << endl;
			count++;
			if (count == q.size()) {
				break;
			}
		}
	}
};

class LRU {
private:
	vector<pair<int, pii> > q;
	int a[20000];
	int cnt;
	int fault;
	int eq;
	int equal() {
		int first = v[cnt].second.first;
		int second = v[cnt].second.second;
		for (int i = 0; i < q.size(); i++) {
			if (q[i].second.first == first && q[i].second.second == second) {
				eq = i;
				return 1;
			}
		}
		return 0;
	}
	int compare() {
		int temp = v[cnt].second.first;
		int j;
		int min = 10001;
		for (int i = 0; i < q.size(); i++) {
			if (q[i].second.first == temp) {
				if (min > q[i].first) {
					min = q[i].first;
					j = i;
				}
			}
		}
		return j;
	}

public:
	void set() {
		memset(a, 0, sizeof(a));
		cnt = 0;
		fault = 0;
	}
	void p_f() {
		while (1) {
			if (equal() == 1) {
				q[eq].first = v[cnt].first;
				cnt++;
				if (v[cnt].second.first == -1) {
					break;
				}
				continue;
			}
			else {
				if (a[v[cnt].second.first] == k) {
					int temp = compare();
					q[temp].first = v[cnt].first;
					q[temp].second = v[cnt].second;
					fault++;
				}
				else {
					q.push_back(v[cnt]);
					a[v[cnt].second.first]++;
					fault++;
				}
				cnt++;
			}
			if (v[cnt].second.first == -1) {
				break;
			}
		}
	}
	void print() {
		int count = 0;
		output << "LRU: " << fault << endl;
		while (1) {
			output << count << " " << q[count].second.first << " " << q[count].second.second << endl;
			count++;
			if (count == q.size()) {
				break;
			}
		}
	}
};

class OPT {
private:
	vector<pair<int, pii> > q;
	vector<pair<int, int> > t;
	int a[20000];
	int cnt;
	int fault;
	int eq;
	int equal() {
		int first = v[cnt].second.first;
		int second = v[cnt].second.second;
		for (int i = 0; i < q.size(); i++) {
			if (q[i].second.first == first && q[i].second.second == second) {
				eq = i;
				return 1;
			}
		}
		return 0;
	}
	int compare() {
		int temp = v[cnt].second.first;
		for (int i = 0; i < q.size(); i++) {
			if (q[i].second.first == temp) {
				t.push_back({ q[i].first, q[i].second.second });
			}
		}
		for (int i = cnt + 1; i < v.size(); i++) {
			if (t.size() == 1) {
				break;
			}
			if (v[i].second.first == temp) {
				for (int j = 0; j < t.size(); j++) {
					if (v[i].second.second == t[j].second) {
						t.erase(t.begin() + j);
						break;
					}
				}
			}
		}
		sort(t.begin(), t.end());
		for (int i = 0; i < q.size(); i++) {
			if (q[i].second.first == temp && q[i].second.second == t[0].second) {
				return i;
			}
		}
	}

public:
	void set() {
		memset(a, 0, sizeof(a));
		cnt = 0;
		fault = 0;
	}
	void p_f() {
		while (1) {
			if (equal() == 1) {
				cnt++;
				if (v[cnt].second.first == -1) {
					break;
				}
				continue;
			}
			else {
				if (a[v[cnt].second.first] == k) {
					int temp = compare();
					t.clear();
					q[temp].first = v[cnt].first;
					q[temp].second = v[cnt].second;
					fault++;
				}
				else {
					q.push_back(v[cnt]);
					a[v[cnt].second.first]++;
					fault++;
				}
				cnt++;
			}
			if (v[cnt].second.first == -1) {
				break;
			}
		}
	}
	void print() {
		int count = 0;
		output << "OPT: " << fault << endl;
		while (1) {
			output << count << " " << q[count].second.first << " " << q[count].second.second << endl;
			count++;
			if (count == q.size()) {
				break;
			}
		}
	}
};

int main() {
	FIFO F;
	LRU L;
	OPT O;
	input >> k;
	int count = 0;
	while (1) {
		int a, b;
		input >> a >> b;
		v.push_back({ count, {a, b} });
		if (a == -1 && b == -1) {
			break;
		}
		count++;
	}
	F.set();
	F.p_f();
	F.print();
	L.set();
	L.p_f();
	L.print();
	O.set();
	O.p_f();
	O.print();

	return 0;
}