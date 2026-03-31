#include "CrossArray.hpp"

int main() {
    // Simple test
    sjtu::CrossArray arr(5);

    int data1[] = {1, 2, 3};
    arr.InsertArrays(data1, 3);

    int data2[] = {4, 5};
    arr.InsertArrays(data2, 2);

    return 0;
}
