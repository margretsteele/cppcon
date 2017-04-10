#include  <iostream>
#include  <cmath>
#include  <type_traits>
using namespace std;

//since abs is not constexpr then anything that calls it is not compile time
//to get around this we would need to write a constexpr equivilant

template <class T>
constexpr
    enable_if_t<!is_floating_point<T>::value, bool>
        close_enough(T a, T b) {
            return a == b;
        }

template <class T>
constexpr
    enable_if_t<is_floating_point<T>::value, bool>
        close_enough(T a, T b) {
            return abs(a - b) <= static_cast<T>(0.000001);
        }


int main() {
    if(close_enough(3,4)) {
        cout << "Booooo" << endl;
    }

    if(close_enough(3.1, 3.000000002)) {
        cout << "what" << endl;
    }

    if(close_enough(3.1, 3.1000000009)) {
        cout << "this is good" << endl;
    }
}
