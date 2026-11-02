/*
 *  Mathe Ruben-Jonathan
 *  mrim2578
 *  511/1
 *
 *  Lab1/05
 *
 *  Kijelentés:
 *
 *  Források:
 *
 */

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

void read(int &n, double &x) {
    cin >> n >> x;
}

void write(const double &T) {
    cout << fixed << setprecision(2) << "\n";
    cout << T << '\n';
}

double getFact(const int &n) {
    double fact = 1;

    for (int i = 1; i<=n; i++) {
        fact *= i;
    }

    return fact;
}

double getS(const int &n, const double &x) {
    double S = 1;

    for (int i = 1; i<=n; i++) {
        S += pow(-1,i) * pow(x,2*i)/getFact(2*i);
    }

    return S;
}

int main() {
    int n;
    double x;

    read(n,x);
    write(getS(n,x));

    return 0;
}
