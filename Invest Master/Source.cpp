#include <iostream>
#include <vector>
#include <algorithm>

constexpr int NUM = 100001;
int dp[NUM] = { 0 };

int main() {
	int n, d, money;
	std::cin >> n >> d >> money;

	std::vector<std::vector<int>> p;
	for (int i = 0; i < d; i++) {
		p.push_back(std::vector<int>());
		for (int j = 0; j < n; j++) {
			int dd = 0;
			std::cin >> dd;
			p.back().push_back(dd);
		}
	}

	int y = money;
	for (int i = 0; i < NUM; i++) dp[i] = i;

	for (int i = 0; i < d - 1; i++) {
		int m = 0;
		for (int j = 0; j <= y; j++) dp[j] = j;//ƒŠƒZƒbƒg
		for (int j = 0; j < n; j++) {
			for (int k = 1; k <= y; k++) {
				if (k - p[i][j] >= 0) dp[k] = std::max(dp[k], dp[k - p[i][j]] + p[i + 1][j]);
			}
		}
		y = dp[y];
	}
	std::cout << y << std::endl;
	return 0;
}