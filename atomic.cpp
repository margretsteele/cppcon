#include <iostream>
#include <thread>
using namespace std;

int main(){
    enum { N = 1000000 };
    // if atomic is used instead we actually end up with 2 million in n
    // without an atomic bool here we end up with ~1040000 in n, not close_enough to 2 million
    int n = 0;

    thread th0{ [&n] {
        for(int i = 0; i < N; ++i)
            ++n;
    } };

    thread th1{ [&n] {
        for(int i = 0; i < N; ++i)
            ++n;
    } };

    th0.join();
    th1.join();

    cout << n << endl;
}
