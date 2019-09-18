#include <iostream>
#include <fstream>

using namespace std;

int arr[100001];
int *arr2;
long long result;

void merge(int start, int mid, int end) {
    int m=0;
    int n=0;
    int o=0;
    m = start;
    n = mid;
    while (m < mid && n < end) {
        if (arr[m] < arr[n]) {
            arr2[o] = arr[m];
            o++;
            m++;
        } else if (arr[m] > arr[n]) {
            result += mid - m;
            arr2[o] = arr[n];
            o++;
            n++;
        } else {
            arr2[o] = arr[n];
            o++;
            n++;
        }
    }
    while (m < mid) {
        arr2[o] = arr[m];
        o++;
        m++;
    }
    while (n < end) {
        arr2[o] = arr[n];
        o++;
        n++;
    }
    for (int i = 0; i < end - start; ++i) {
        arr[start + i] = arr2[i];
    }
}

void merge_sort(int start, int end) {
    int mid = (start + end) / 2;
    if (start < mid) {
        merge_sort(start, mid);
        merge_sort(mid, end);
        merge(start, mid, end);
    }
}

int main() {
    ifstream input("inv.inp");
    ofstream output("inv.out");

    int count;
    input >> count;

    while (count != 0) {
        int i;
        input >> i;
        arr2 = new int[i];
        result = 0;

        for (int a = 0; a < i; a++) {
            int temp;
            input >> temp;
            arr[a] = temp;
        }
        merge_sort(0, i);
        output << result << "\n";
        delete[] arr2;
        arr2 = NULL;
        count--;
    }
}