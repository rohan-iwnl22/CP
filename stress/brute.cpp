#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, l, r;
    std::cin >> n >> l >> r;
    
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    std::vector<i64> pre(n + 1);
    for (int i = 0; i < n; i++) {
        pre[i + 1] = pre[i] + a[i];
    }
    
    std::vector<int> dp(n + 1);
    
    std::multiset<int> s;
    for (int i = 1, j = 0, k = 0; i <= n; i++) {
        dp[i] = dp[i - 1];
        while (k < i && pre[i] - pre[k] >= l) {
            s.insert(dp[k++]);
        }
        while (j < i && pre[i] - pre[j] > r) {
            s.extract(dp[j++]);
        }
        if (!s.empty()) {
            dp[i] = std::max(dp[i], 1 + *s.rbegin());
        }
    }
    std::cout << dp[n] << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    solve();
    
    return 0;
}
