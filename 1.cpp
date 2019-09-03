
#include <iostream>

using namespace std;

int Answer;
int Dp[1000001];
int arr_s[1000001];
int main(int argc, char** argv)
{
	
	int T, test_case;
	Dp[1] = 0;
	Dp[2] = 1;
	cin >> T;
	int temp = 0;
	int i = 4;
	while (1) {
		if (i > 1000000) {
			temp++;
			break;
		}
		Dp[i] = Dp[i / 2] + 1;
		Dp[i - 1] = Dp[i] + 1;
		i += 2;
		if (temp > 0) {
			break;
		}
	}
	arr_s[1] = 0;
	for (int n = 2; n < 1000001; n++) {
		arr_s[n] = arr_s[n - 1] + Dp[n];
	}
	for (test_case = 0; test_case < T; test_case++)
	{
		Answer = 0;
		int j, k;
		cin >> j >> k;
		if (j != k)
			Answer = arr_s[k] - arr_s[j-1];
		else
			Answer = arr_s[k] - arr_s[k-1];
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}
	return 0;
}