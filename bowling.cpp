#include <fstream>
#include <iostream>
#include <vector>

using namespace std;
ifstream input("bowling.inp");
ofstream output("bowling.out");
class bowl {
   private:
    vector< pair< int, int> > v;
    vector< int > s;
    int temp;

   public:
    void set() {
        v.clear();
        s.clear();
        int a;
        int b;
        temp = 0;
        for (int i = 0; i < 9; i++) {
            input >> a;
            if (a != 10) {
                input >> b;
            } else {
                b = 0;
            }
            v.push_back({a, b});
            s.push_back(a + b);
        }
        input >> a >> b;
        v.push_back({a, b});
        s.push_back(a + b);
        if ((a + b) >= 10) {
            input >> temp;
        }
    }
    int sum() {
        int result = 0;
        int count = 0;
        while (1) {
            if (count == 8)
                break;
            if (s[count] == 10) {
                if (v[count].first == 10) {
                    if (v[count + 1].first == 10) {
                        result += s[count] + s[count + 1] + v[count + 2].first;
                    } else {
                        result += s[count] + s[count + 1];
                    }
                } else {
                    result += s[count] + v[count + 1].first;
                }
            } else {
                result += s[count];
            }
            count++;
        }
        if (s[8] == 10) {
            if (v[8].first == 10) {
                result += s[8] + s[9];
            } else {
                result += s[8] + v[9].first;
            }
        } else {
            result += s[count];
        }
        result += s[9] + temp;
        return result;
    }
};
int main() {
    int count;
    input >> count;
    bowl b;
    while(count!=0){
        b.set();
        int result = b.sum();
        output << result << "\n";
        count--;
    }
}