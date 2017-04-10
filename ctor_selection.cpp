#include <iostream>
using namespace std;

template <class T>
struct X{
    X(int) {}
    X(string &&) {}
    X(T &&) {
    }
    X(const X&) {
        cout << "copy ctor" << endl;
    }
    template <class U>
    X(U &&) { // U is NOT CONST
        cout << "general copy ctor" << endl;
    }
};

template <class T>
void fff(T &&) {
}

int main() {
    fff("yo"); // compiler discovers the type in this scenario. Forwarding reference

    // int ctor
    X<float> x0{3}; // uses T&&

    // string ctor
    // move ctor
    string s;
    X<float> x1{ std::move(s) };

    vector<int> v;
    X<float> x2{ std::move(v) };

    // was the copy ctor
    // but with the addition of the black hole ctor,
    // it becomes a better match because x1 is a named var and is non-const
    X<float> x3{x1};

    // black hole ctor
    vector<double> w;
    X<float> x4{ w };
}
