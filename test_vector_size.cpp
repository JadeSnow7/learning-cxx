#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec{1, 2, 3, 4, 5};
    std::cout << "sizeof(std::vector<int>): " << sizeof(vec) << std::endl;
    std::cout << "vec.size(): " << vec.size() << std::endl;
    std::cout << "vec.capacity(): " << vec.capacity() << std::endl;
    
    std::vector<double> vec2{1, 2, 3, 4, 5};
    std::cout << "sizeof(std::vector<double>): " << sizeof(vec2) << std::endl;
    
    std::vector<char> vec3(48, 'z');
    std::cout << "sizeof(std::vector<char>): " << sizeof(vec3) << std::endl;
    
    return 0;
} 