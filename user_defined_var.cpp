#include  <iostream>
using namespace std;

constexpr unsigned long long facto(int n) {
    return n == 0 || n == 1 ? 1ULL : n * facto(n-1);
}

constexpr unsigned long long operator""_fac(unsigned long long n) {
    return facto(static_cast<int>(n));
}

int main() {
    cout << 6_fac << endl;
}
