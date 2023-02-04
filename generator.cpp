#include <bits/stdc++.h>
#include "utilities.h"
using namespace std;

bool isPrime(int n) {
    if (n <= 1) return 0;
    int m = sqrt(n);
    for (int i = 2; i <= m; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

map<pair<int, int>, int> vs;

int main() {
    ios::sync_with_stdio(0);

    for (int index = 1; index <= NUM_TESTS; index++) {
        ofstream inp(inputName(index).c_str());

        int t = rand(1, 10);
        // inp << t << '\n';
        for (int z = 1; z <= t; z++) {
            long long x = rand(2, (long long)100000);
            inp << x << "\n";
        }
        inp << 0 << "\n";
        
        // Generating string
        // for (int i = 1; i <= m; i++) {
        //     int c = rand(0, 25);
        //     inp << (char) (c + 'A');
        // }

        // Generating tree
        // for (int i = 2; i <= n; i++) {
        //     int p = rand(1, i - 1);
        //     int w = rand(1, 5000);
        //     inp << i << ' ' << p << ' ' << w << "\n";
        // }
    }
    return 0;
}