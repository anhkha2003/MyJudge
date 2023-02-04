#include<bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

long long pw(long long a, long long n, long long lim) {
    if (n == 0) return 1;
    long long q = pw(a, n / 2, lim);
    if (n % 2 == 0) {
        if (q <= lim / q) {
            return q * q;
        }
        return lim + 5;
    }
    else {
        if (q > lim / q) return lim + 5;
        long long mul = q * q;
        if (mul > lim / a) return lim + 5;
        return mul * a;
    }
}

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    long long x;
    while (cin >> x) {
        if (x == 0) break;

        int res = 0;
        for (int p = 1; p <= 70; p++) {
            long long lower = 1, upper = x;
            while (lower < upper) {
                long long mid = (lower + upper) / 2;
                if (pw(mid, p, x * 2) >= x) {
                    upper = mid;
                }
                else lower = mid + 1;
            }

            bool ok = 0;
            if (pw(lower, p, x * 2) == x) ok = 1;
            if (lower > 1 && pw(lower - 1, p, x * 2) == x) ok = 1;
            if (pw(lower + 1, p, x * 2) == x) ok = 1;

            if (ok) res = p;
        }
        cout << res << "\n";
    }

    return 0;
}