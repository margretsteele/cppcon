#include  <iostream>
#include  <cmath>
#include  <type_traits>
using namespace std;

class exact{};
class floating{};

template <class T>
constexpr bool close_enough(T a, T b, exact) {
    return a == b;
}

template <class T>
constexpr bool close_enough(T a, T b, floating) {
    return abs(a - b) <= static_cast<T>(0.000001);
}

//since abs is not constexpr then anything that calls it is not compile time
//to get around this we would need to write a constexpr equivilant

template <class T>
constexpr bool close_enough(T a, T b) {
    //old way to write this, shit it is so ugly or whatever
    return close_enough(a, b, typename conditional<is_floating_point<T>::value, floating, exact>::type{});

    //new way, replace typename ::type with _t and ::value with _v added in C++17
    //return close_enough(a, b, conditional_t<is_floating_point_v<T>, floating, exact>{});
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
