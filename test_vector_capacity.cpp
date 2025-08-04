#include <iostream>
#include <vector>

int main() {
    std::vector<double> vec{1, 2, 3, 4, 5};
    std::cout << "Initial capacity: " << vec.capacity() << std::endl;
    
    vec.push_back(6);
    std::cout << "After push_back capacity: " << vec.capacity() << std::endl;
    
    vec.pop_back();
    std::cout << "After pop_back capacity: " << vec.capacity() << std::endl;
    
    vec.insert(vec.begin() + 1, 1.5);
    std::cout << "After insert capacity: " << vec.capacity() << std::endl;
    
    vec.erase(vec.begin() + 3);
    std::cout << "After erase capacity: " << vec.capacity() << std::endl;
    
    vec.shrink_to_fit();
    std::cout << "After shrink_to_fit capacity: " << vec.capacity() << std::endl;
    
    return 0;
} 