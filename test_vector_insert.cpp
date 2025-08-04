#include <iostream>
#include <vector>

int main() {
    std::vector<double> vec{1, 2, 3, 4, 5};
    
    std::cout << "Initial vector: ";
    for (auto x : vec) std::cout << x << " ";
    std::cout << std::endl;
    
    vec[4] = 6;
    std::cout << "After vec[4] = 6: ";
    for (auto x : vec) std::cout << x << " ";
    std::cout << std::endl;
    
    vec.insert(vec.begin() + 2, 1.5);
    std::cout << "After insert at position 2: ";
    for (auto x : vec) std::cout << x << " ";
    std::cout << std::endl;
    
    std::vector<double> expected{1, 1.5, 2, 3, 4, 6};
    std::cout << "Expected: ";
    for (auto x : expected) std::cout << x << " ";
    std::cout << std::endl;
    
    std::cout << "vec == expected: " << (vec == expected) << std::endl;
    
    return 0;
} 