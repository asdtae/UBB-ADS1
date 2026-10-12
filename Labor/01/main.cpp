/*
 *  Mathe Ruben-Jonathan
 *  mrim2578
 *  511/1
 *
 */

#include <iostream>
#include <vector>

using namespace std;

void read(int &n, int &k) {
    // int b;
    cin >> n >> k;
    // cin >> b;
}

void write(const int msg) {
    cout << msg << '\n';
}

int main() {
    int n,k;

    read(n,k);

    if (k == 1) {
        write(0);
    } else if (n == k) {
        write(n-1);
    } else {
        vector<bool> baratok(n+1);
        int i = 1;

        while (baratok[i] != true) {
            baratok[i] = true;
            if (i+k > n) {
                i += k - n;
            } else {
                i += k;
            }
        }

        int hanyNemKapott = 0;
        for (i = 1; i<=n; i++) if (!baratok[i]) hanyNemKapott++;

        write(hanyNemKapott);
    }

    return 0;
}
