#include <iostream>

using namespace std;


// Ax + By = GCD(A, B)

int d, x, y;
void extendedEuclid(int A, int B, int &x, int &y) {
    if (B == 0) {
        d = A;
        x = 1;
        y = 0;
    }
    else {
        extendedEuclid(B, A%B, x, y);
        int temp = x;
        x = y;
        y = temp - (A/B)*y;
    }
}

// Ax = 1 (mod m) (when GCD(m, A) == 1)
// prove: 
// Ax + By = GCD(A, B)
// Let B = m => Ax = 1 (mod m)
// => Solve extendedEuclid(A, m), get x

// Function to find modulo inverse of a
void modInverse(int a, int m)
{
    int x, y;
    extendedEuclid(a, m, x, y);
    // m is added to handle negative x
    int res = (x % m + m) % m;
    cout << "Modular multiplicative inverse is " << res;
}

int main() {
    extendedEuclid(16, 10, x, y);
    cout << "gcd(16, 10) = " << d << endl;
    cout << "x, y: " << x <<  ", " << y << endl;
    modInverse(2, 11);
    return 0;
}