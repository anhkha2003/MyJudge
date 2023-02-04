#include<bits/stdc++.h>
using namespace std;

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 
    long long x;
    while (cin >> x) {
        if (x == 0) break;
        
        int res = 0;
        for (int p = 100; p >= 1; p++) {
            bool ok = 0;
            for (int b = 1; b <= x; b++) {
                long long mul = 1;
                for (int i = 1; i <= p; i++) {
                    mul *= b;
                    if (mul > x) {
                        break;
                    }
                }

                if (mul == x) {
                    ok = 1;
                    break;
                }
            }
            if (ok) {
                res = p;
                break;
            }
        }
        cout << res << "\n";
    }

    return 0;
}