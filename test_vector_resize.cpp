#include <iostream>
#include <vector>

int main() {
    std::vector<char> vec(48, 'z');
    std::cout << "Initial capacity: " << vec.capacity() << std::endl;
    
    auto capacity = vec.capacity();
    vec.resize(16);
    std::cout << "After resize(16) capacity: " << vec.capacity() << std::endl;
    
    return 0;
} 