#include <fstream>
#include <iostream>
#include <string>

using namespace std;

string tmp;

class cube {
private:
	string c;
	string cp;

public:
	void set() {
		for (int i = 0; i < 6; i++) {
			c.push_back(tmp.at(i));
			cp.push_back(tmp.at(i+6));
		}
	}
	int compare() {
		char temp;

		if (c.compare(cp) == 0) {
			return 1;
		}

		for (int i = 0; i < 4; i++) {
			temp = cp[1];
			cp[1] = cp[2];
			cp[2] = cp[4];
			cp[4] = cp[3];
			cp[3] = temp;
			if (c.compare(cp) == 0) {
				return 1;
			}
		}

		temp = cp[0];
		cp[0] = cp[5];
		cp[5] = temp;
		temp = cp[2];
		cp[2] = cp[3];
		cp[3] = temp;

		for (int i = 0; i < 4; i++) {
			temp = cp[1];
			cp[1] = cp[2];
			cp[2] = cp[4];
			cp[4] = cp[3];
			cp[3] = temp;
			if (c.compare(cp) == 0) {
				return 1;
			}
		}

		temp = cp[0];
		cp[0] = cp[5];
		cp[5] = temp;
		temp = cp[2];
		cp[2] = cp[3];
		cp[3] = temp;

		temp = cp[0];
		cp[0] = cp[1];
		cp[1] = cp[5];
		cp[5] = cp[4];
		cp[4] = temp;

		for (int i = 0; i < 4; i++) {
			temp = cp[1];
			cp[1] = cp[2];
			cp[2] = cp[4];
			cp[4] = cp[3];
			cp[3] = temp;
			if (c.compare(cp) == 0) {
				return 1;
			}
		}

		temp = cp[0];
		cp[0] = cp[5];
		cp[5] = temp;
		temp = cp[2];
		cp[2] = cp[3];
		cp[3] = temp;

		for (int i = 0; i < 4; i++) {
			temp = cp[1];
			cp[1] = cp[2];
			cp[2] = cp[4];
			cp[4] = cp[3];
			cp[3] = temp;
			if (c.compare(cp) == 0) {
				return 1;
			}
		}

		temp = cp[0];
		cp[0] = cp[5];
		cp[5] = temp;
		temp = cp[2];
		cp[2] = cp[3];
		cp[3] = temp;

		temp = cp[0];
		cp[0] = cp[2];
		cp[2] = cp[5];
		cp[5] = cp[3];
		cp[3] = temp;

		for (int i = 0; i < 4; i++) {
			temp = cp[1];
			cp[1] = cp[2];
			cp[2] = cp[4];
			cp[4] = cp[3];
			cp[3] = temp;
			if (c.compare(cp) == 0) {
				return 1;
			}
		}

		temp = cp[0];
		cp[0] = cp[5];
		cp[5] = temp;
		temp = cp[2];
		cp[2] = cp[3];
		cp[3] = temp;

		for (int i = 0; i < 4; i++) {
			temp = cp[1];
			cp[1] = cp[2];
			cp[2] = cp[4];
			cp[4] = cp[3];
			cp[3] = temp;
			if (c.compare(cp) == 0) {
				return 1;
			}
		}
		return 0;
	}
	void clear() {
		c.clear();
		cp.clear();
	}
};

int main() {
	ifstream input("cube.inp");
	ofstream output("cube.out");

	cube c;

	while (1) {
		getline(input, tmp);
		if (tmp == "") {
			break;
		}
		c.set();
		if (c.compare() == 1) {
			output << "TRUE\n";
		}
		else {
			output << "FALSE\n";
		}
		c.clear();
	}
}