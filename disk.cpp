#include <fstream>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;
bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{
	return a.second < b.second;
}
bool cmp2(const pair<int, int> &a, const pair<int, int> &b)
{
	return a.first < b.first;
}
int svc;
int cnt = 0;
int hdr = 0;
vector< pair <int, int> > v;
void FCFS() {
	int i = 0;
	while (1) {
		int a = v[i].first;
		int b = v[i].second;
		if (a == -1)
			break;
		if (cnt < a) {
			cnt = a;
		}
		if (hdr > b) {
			cnt += hdr - b + svc;
		}
		else {
			cnt += b - hdr + svc;
		}
		hdr = b;
		i++;
	}
}
void SSTF() {
	vector < pair <int, int> > tmp;
	int i = 0;
	int a = 0;
	int b = 0;
	while (1) {
		for (int j = 0;j<v.size(); j++) {
			int a = v[j].first;
			int b = v[j].second;
			if (cnt < a) {
				break;
			}
			if (a == -1) {
				continue;
			}
			tmp.push_back({ a,b });
		}
		if (tmp.empty() == true) {
			if (v.empty() == true) {
				break;
			}
			else {
				cnt = v[1].first;
				continue;
			}
		}
		//sort(tmp.begin(), tmp.end(), cmp);
		if ((i == 0) || ((tmp[0].second - b)>0)) {
			a = tmp[0].first;
			b = tmp[0].second;
		}
		else if (tmp[tmp.size() - 1].second - b < 0) {
			a = tmp[tmp.size() - 1].first;
			b = tmp[tmp.size() - 1].second;
		}
		else {
			int temp;
			for (int j = 0;j<tmp.size(); j++) {
				temp = tmp[j].second - b;
				if (temp >= 0) {
					int temp2 = tmp[j - 1].second - b;
					if (temp2 + temp > 0) {
						a = tmp[j - 1].first;
						b = tmp[j - 1].second;
						break;
					}
					else {
						a = tmp[j].first;
						b = tmp[j].second;
						break;
					}
				}
			}
		}
		if (hdr > b) {
			cnt += hdr - b + svc;
		}
		else {
			cnt += b - hdr + svc;
		}
		hdr = b;
		for (int j = 0;j<v.size(); j++) {
			if (a == v[j].first && b == v[j].second) {
				v.erase(v.begin() + j);
				break;
			}
		}
		tmp.clear();
		i++;
		if (v.size() == 1)
			break;
	}
}
void LOOK() {
	vector < pair <int, int> > tmp;
	int i = 0;
	int a = 0;
	int b = 0;
	int t = 0;
	while (1) {
		for (int j = 0; j < v.size(); j++) {
			int a = v[j].first;
			int b = v[j].second;
			if (cnt < a) {
				break;
			}
			if (a == -1) {
				continue;
			}
			tmp.push_back({ a,b });
		}
		if (!(t - 1 == tmp.size())) {
			sort(tmp.begin(), tmp.end(), cmp);
		}
		t = tmp.size();
		if (tmp.empty() == true) {
			if (v.empty() == true) {
				break;
			}
			else {
				cnt = v[1].first;
				continue;
			}
		}

		if ((i == 0) || ((tmp[0].second - b) > 0)) {
			a = tmp[0].first;
			b = tmp[0].second;
			i = 1;
		}
		else if (tmp[tmp.size() - 1].second - b < 0) {
			a = tmp[tmp.size() - 1].first;
			b = tmp[tmp.size() - 1].second;
			i = -1;
		}
		else if(i==1){
			int temp;
			for (int j = 0; j < tmp.size(); j++) {
				temp = tmp[j].second - b;
				if (temp > 0) {
					a = tmp[j].first;
					b = tmp[j].second;
					i = 1;
					break;
				}
			}
		}
		else if (i == -1) {
			int temp;
			for (int j = tmp.size()-1; j>=0; j--) {
				temp = tmp[j].second - b;
				if (temp < 0) {
					a = tmp[j].first;
					b = tmp[j].second;
					i = -1;
					break;
				}
			}
		}
		if (hdr > b) {
			cnt += hdr - b + svc;
		}
		else {
			cnt += b - hdr + svc;
		}
		hdr = b;
		for (int j = 0; j < v.size(); j++) {
			if (a == v[j].first && b == v[j].second) {
				v.erase(v.begin() + j);
				break;
			}
		}
		tmp.clear();
		if (v.size() == 1)
			break;
	}
}

int main() {
	ifstream input("disk.inp");
	ofstream output("disk.out");
	string s;
	input >> s;
	input >> svc;
	while (1) {
		int a, b;
		input >> a >> b;
		v.push_back({ a, b });
		if (a == -1)
			break;
	}
	sort(v.begin(), v.end(), cmp2);
	if (s == "FCFS") {
		FCFS();
	}
	if (s == "SSTF") {
		SSTF();
	}
	if (s == "LOOK") {
		LOOK();
	}
	output << cnt << " " << hdr;
}