#include <iostream>
#include <string>
using namespace std;
int input;
int main() {
    int count = 0;
    while (1) {
        cin >> input;
        cout << input;
        if (++count == 3)
            break;
    }
}