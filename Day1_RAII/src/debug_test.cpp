#include <iostream>
#include <vector>

/**
 * @brief This code is intentionally designed to contain common bugs to test ASan (Safety Strategy)
 */
int main() {
    // 1. A classic Out-of-Bounds error
    std::vector<int> v = {10, 20, 30};
    std::cout << "Accessing index 3: " << v[3] << std::endl; 

    // 2. A Use-After-Free error
    int* ptr = new int(42);
    delete ptr;
    std::cout << "Accessing deleted memory: " << *ptr << std::endl;

    return 0;
}