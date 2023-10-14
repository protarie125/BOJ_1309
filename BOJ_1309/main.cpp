#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

constexpr auto Mod = 9901;

using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using vii = vector<pii>;
using pll = pair<ll, ll>;
using vll = vector<pll>;

int n;
vvi dp;

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	cin >> n;
	dp = vvi(n + 1, vi(3, 0));
	dp[1][0] = 1;
	dp[1][1] = 1;
	dp[1][2] = 1;

	for (auto i = 2; i <= n; ++i) {
		dp[i][0] = dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2];
		dp[i][0] %= Mod;

		dp[i][1] = dp[i - 1][0] + dp[i - 1][2];
		dp[i][1] %= Mod;

		dp[i][2] = dp[i - 1][0] + dp[i - 1][1];
		dp[i][2] %= Mod;
	}

	cout << (dp[n][0] + dp[n][1] + dp[n][2]) % Mod;

	return 0;
}