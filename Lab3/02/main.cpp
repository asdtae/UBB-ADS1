/*
 *  Mathe Ruben-Jonathan
 *  mrim2578
 *  511
 *  prob-PT_PrimReszsorozat_GI
 *
 *  Lab3/02
 *
 *  Kijelentés:
 *      Adott egy n elemű természetes számokat tartalmazó sorozat.
 *      Keressük meg és írjuk ki azt a leghosszabb sb,sb+1,...,sj
 *      tömbszakaszt, amely csak prímszámokat tartalmaz!
 *
 */

#include <iostream>
#include <vector>

#include <ctime>
#include <iomanip>

using namespace std;

static uint32_t readN() {
    uint32_t n;
    cin >> n;
    return n;
}

static uint32_t read(const uint32_t &n, vector<uint32_t> &a) {
    uint32_t tmp;
    uint32_t maxi = 0;

    for (uint32_t i = 0; i<n; i++) {
        cin >> tmp;
        a[i] = tmp;

        a[i] > maxi ? maxi = a[i] : 0;
    }

    return maxi;
}

static void write(const uint32_t &start, const uint32_t &end, const vector<uint32_t> &a) {
    for (uint32_t i = start; i<end; i++) {
        cout << a[i] << ' ';
    }
    cout << '\n';
}

static void primeBV(const uint32_t &n, vector<bool> &primeBV) {
    primeBV[0] = false;
    primeBV[1] = false;

    for (uint32_t i = 2; i<=n; i++) {
        if (primeBV[i]) {
            uint32_t j = i * 2;

            while (j<=n) {
                primeBV[j] = false;
                j += i;
            }
        }
    }
}

static void primes(const uint32_t &n, const vector<bool> &primeBV, vector<uint32_t> &primesV) {
    for (uint32_t i = 0; i<n; i++) {
        if (primeBV[i]) primesV.push_back(i);
    }
}

static vector<int32_t> solve(const vector<uint32_t> &data, const vector<uint32_t> &primesV) {
    vector<int32_t> res(2,-1);
    uint32_t maxi = 0;

    for (uint32_t i = 0, tsSize = 0; i<data.size(); i++) {
        uint32_t j = 0;
        bool p = false;

        while (j<primesV.size()) {
            if (data[i] == primesV[j]) {
                p = true;
                break;
            }

            j++;
        }

        if (p) tsSize++;
        else tsSize = 0;

        if (tsSize > maxi) {
            maxi = tsSize;
            res[0] = i - tsSize + 1;
            res[1] = i + 1;
        }

    }

    return res;
}

int main() {
    const uint32_t n = readN();
    vector<uint32_t> data(n,0);

    // TODO: miert nem megy nagyobb bemenetekre a beolvasas se

    const clock_t seg1Bef = clock();
    const uint32_t maxi = read(n,data);
    vector<bool> primesBV(maxi + 1,true);
    vector<uint32_t> primesV;
    const clock_t seg1Aft = clock();

    const clock_t seg2Bef = clock();
    primeBV(maxi + 1, primesBV);
    primes(maxi + 1, primesBV, primesV);
    const vector<int32_t> res = solve(data,primesV);
    const clock_t seg2Aft = clock();

    cout << fixed << setprecision(6) << "\n";
    cout << "seg1: "    << static_cast<double>(seg1Aft-seg1Bef) / CLOCKS_PER_SEC
         << "s, seg2: " << static_cast<double>(seg2Aft-seg2Bef) / CLOCKS_PER_SEC
         << "s\n";

    write(res[0],res[1],data);

    return 0;
}
