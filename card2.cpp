#include <fstream>
#include <iostream>

using namespace std;

ifstream input("card.inp");
ofstream output("card.out");

class card {
   private:
    int *arr;
    int *ans;
    int *ans2;
    int *ans3;

   public:
    void set(int a) {
        arr = new int[a];
        ans = new int[a];
        ans2 = new int[a];
        ans3 = new int[a];
        for (int i = 0; i < a; i++) {
            input >> arr[i];
            ans[i] = -1000000;
            ans2[i] = -1000000;
            ans3[i] = -1000000;
        }
    }
    int sol(int a) {
        ans[0] = arr[0];
        ans[1] = arr[1];
        ans[2] = arr[2];
        for (int i = 3; i < a; i++) {
            if (i == 3) {
                ans2[i] = arr[i] + arr[i - 3];
                ans3[i] = arr[i] + arr[i - 2];
            } else {
                int tmp;
                if (ans[i - 4] >= ans2[i - 4] && ans[i - 4] >= ans3[i - 4])
                    tmp = ans[i - 4];
                else if (ans2[i - 4] >= ans[i - 4] && ans2[i - 4] >= ans3[i - 4])
                    tmp = ans2[i - 4];
                else
                    tmp = ans3[i - 4];

                ans[i] = tmp + arr[i];

                if (ans[i - 3] >= ans2[i - 3] && ans[i - 3] >= ans3[i - 3])
                    tmp = ans[i - 3];
                else if (ans2[i - 3] >= ans[i - 3] && ans2[i - 3] >= ans3[i - 3])
                    tmp = ans2[i - 3];
                else
                    tmp = ans3[i - 3];

                ans2[i] = tmp + arr[i];

                if (ans[i - 2] >= ans2[i - 2])
                    tmp = ans[i - 2];
                else
                    tmp = ans2[i - 2];

                ans3[i] = tmp + arr[i];
            }
        }
        if (ans[a-1] >= ans2[a-1] && ans[a-1] >= ans3[a-1])
            return ans[a-1];
        else if (ans2[a-1] >= ans[a-1] && ans2[a-1] >= ans3[a-1])
            return ans2[a-1];
        else
            return ans3[a-1];
    }
    void end() {
        delete[] arr;
        delete[] ans;
        delete[] ans2;
        delete[] ans3;
        arr = NULL;
        ans = NULL;
        ans2 = NULL;
        ans3 = NULL;
    }
};

int main() {
    int count;
    card c;
    input >> count;
    while (count != 0) {
        int a;
        input >> a;
        c.set(a);
        output << c.sol(a) << "\n";
        c.end();
        count--;
    }
}