#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

#include "arrayd.hpp"
bool test_resize() {
    bool result = true;

    ArrayD arr(3, 1.5);
    arr.resize(5);
    result &= arr.ssize() == 5;
    for (std::ptrdiff_t i = 0; i < 3; ++i) {
        result &= arr[i] == 1.5;
    }
    for (std::ptrdiff_t i = 3; i < 5; ++i) {
        result &= arr[i] == 0;
    }
    arr.resize(2);
    result &= arr.ssize() == 2;
    result &= arr[0] == 1.5;
    result &= arr[1] == 1.5;

    return result;
}

bool test_insert() {
    bool result = true;

    ArrayD arr(3, 1.5);
    arr.insert(1, 2.5);
    result &= arr.ssize() == 4;
    result &= arr[0] == 1.5;
    result &= arr[1] == 2.5;
    result &= arr[2] == 1.5;


    return result;
}

bool test_remove() {
    bool result = true;

    ArrayD arr(3, 1.5);
    arr.remove(1);
    result &= arr.ssize() == 2;
    result &= arr[0] == 1.5;
    result &= arr[1] == 1.5;

    return result;
}
