#include <bits/stdc++.h>
using namespace std;

void test_case(int& tc) {
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int mn = INT_MAX, mx = 0;
	for (int i = 0; i < n - 1; i++) {
		int x = a[i], y = a[i+1];
		int mid1 = (x + y) / 2;
		int mid2 = (x + y + 1) / 2;
		if (x < y) {
			mn = min(mn, mid1); // x <= midpoint of a[i] and a[i+1]
		}
		if (x > y) {
			mx = max(mx, mid2); // x >= midpoint of a[i] and a[i+1]
		}
	}
	// mn should be larger than mx so that we could choose use it as well
	// for example:
	// sequence: 7 7 7 7 7 3 2 (n = length)
	// midpoints: 7 7 7 7 5 3 (n-1 = length)
	// mn = 7 and mx = 5
	// we needed 5 in order to make 7, 3, 2 into 2, 2, 3
	// thus, mn should be greater than 5 so that we could use 5 itself
	cout << (mx <= mn ? mx : -1) << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T = 1;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		test_case(tc);
	}
}
