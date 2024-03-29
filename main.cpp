#include <iostream>
#include "sorted_array.h"
#include "sorted_array.cpp"

struct Point {
    int x;
    int y;
    int z;

    bool operator<(const Point& other) const {
        return (x < other.x) && (y < other.y) && (z < other.z);
    }
};

int main() {
    
    sorted_array<int> arr1(5);
    arr1.push(3);
    arr1.push(1);
    arr1.push(5);

    for (size_t i = 0; i < arr1.size(); ++i) {
        std::cout << arr1[i] << " ";
    }
    std::cout << std::endl;

    
    sorted_array<Point> arr2(3);
    arr2.push({ 3, 5, 1 });
    arr2.push({ 1, 0, 2 });

    for (size_t i = 0; i < arr2.size(); ++i) {
        std::cout << "(" << arr2[i].x << ", " << arr2[i].y << ", " << arr2[i].z << ") ";
    }
    std::cout << std::endl;

    return 0;
}