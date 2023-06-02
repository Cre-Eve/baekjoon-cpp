//BaekJoon_12852
//1로 만들기 2


/*
* 제한 시간 : 4ms / 0.5s
* 메모리 제한 : 5928KB / 512MB
* 정답 비율 : 47.206%
*/

#include<iostream>

using namespace std;

int dp[1000001];

int Min(int a, int b) {
	return a > b ? b : a;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;

	cin >> n;

	for (int i = 1; i <= n; i++) {
		dp[i] = i;
	}

	for (int i = 2; i <= n; i++) {
		if (i % 2 == 0) {
			dp[i] = Min(dp[i], dp[i / 2]);
		}
		if (i % 3 == 0) {
			dp[i] = Min(dp[i], dp[i / 3]);
		}
		dp[i] = Min(dp[i], dp[i - 1]) + 1;
	}
	cout << dp[n] - 1 << "\n";


	while (n != 0) {
		cout << n << " ";

		if (dp[n] == dp[n - 1] + 1) {
			n -= 1;
		}
		else if (n % 2 == 0 && dp[n] == dp[n / 2] + 1) {
			n /= 2;
		}
		else if (n % 3 == 0 && dp[n] == dp[n / 3] + 1) {
			n /= 3;
		}
	}
}
