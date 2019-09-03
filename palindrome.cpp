#include <fstream>
#include <iostream>
#include <string>

using namespace std;

ifstream input("palindrome.inp");
ofstream output("palindrome.out");
int mx;
class palindrome {
   private:
    string c;
   public:
    void set() {
        getline(input,c);
        mx = c.size()-1;
    }
    int compare() {
        int result = 0;
        int a = 0;
        int b = mx;
        while (1) {
            if (c[a] != c[b]) {
                result++;
                if (c[a + 1] == c[b]) {
                    a++;
                } else if (c[a] == c[b - 1]) {
                    b--;
                } else {
                    result++;
                    if (c[a + 2] == c[b]) {
                        a += 2;
                    } else if (c[a] == c[b + 2]) {
                        b -= 2;
                    } else {
                        result = -1;
                        break;
                    }
                }
            }
            a++;
            b--;
            if (a >= b) {
                break;
            }
        }
        if(result>2){
            result = -1;
        }
        return result;
    }
};
int main() {
    int count;
    input >> count;
    count += 1;
    int temp = count;
    palindrome p;
    while (count != 0) {
        p.set();
        int result = p.compare();
        if(temp == count){
            count--;
            continue;
        }
        output << result << "\n";
        count--;
    }
}