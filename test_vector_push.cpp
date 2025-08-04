#include <iostream>
#include <vector>

int main() {
    std::vector<char> vec(48, 'z');
    std::cout << "Initial size: " << vec.size() << ", capacity: " << vec.capacity() << std::endl;
    
    vec.resize(16);
    std::cout << "After resize(16) size: " << vec.size() << ", capacity: " << vec.capacity() << std::endl;
    
    vec.reserve(256);
    std::cout << "After reserve(256) size: " << vec.size() << ", capacity: " << vec.capacity() << std::endl;
    
    vec.push_back('a');
    vec.push_back('b');
    vec.push_back('c');
    vec.push_back('d');
    
    std::cout << "After push_back size: " << vec.size() << ", capacity: " << vec.capacity() << std::endl;
    std::cout << "vec[15]: " << vec[15] << std::endl;
    std::cout << "vec[16]: " << vec[16] << std::endl;
    std::cout << "vec[17]: " << vec[17] << std::endl;
    std::cout << "vec[18]: " << vec[18] << std::endl;
    std::cout << "vec[19]: " << vec[19] << std::endl;
    
    return 0;
} 