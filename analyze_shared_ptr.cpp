#include <iostream>
#include <memory>

void print_count(const std::weak_ptr<int>& observer, const std::string& step) {
    std::cout << step << ": use_count = " << observer.use_count() << std::endl;
}

int main() {
    std::cout << "=== 分析 shared_ptr 和 weak_ptr 的引用计数 ===" << std::endl;
    
    auto shared = std::make_shared<int>(10);
    std::cout << "创建 shared_ptr，初始引用计数: " << shared.use_count() << std::endl;
    
    std::shared_ptr<int> ptrs[]{shared, shared, shared};
    std::cout << "创建 ptrs 数组，每个元素都指向同一个对象" << std::endl;
    std::cout << "此时 shared 的引用计数: " << shared.use_count() << std::endl;
    
    std::weak_ptr<int> observer = shared;
    print_count(observer, "创建 weak_ptr observer");
    
    ptrs[0].reset();
    print_count(observer, "ptrs[0].reset()");
    
    ptrs[1] = nullptr;
    print_count(observer, "ptrs[1] = nullptr");
    
    ptrs[2] = std::make_shared<int>(*shared);
    print_count(observer, "ptrs[2] = std::make_shared<int>(*shared)");
    
    ptrs[0] = shared;
    ptrs[1] = shared;
    ptrs[2] = std::move(shared);
    print_count(observer, "重新赋值后");
    
    std::ignore = std::move(ptrs[0]);
    ptrs[1] = std::move(ptrs[1]);
    ptrs[1] = std::move(ptrs[2]);
    print_count(observer, "移动操作后");
    
    shared = observer.lock();
    print_count(observer, "shared = observer.lock()");
    
    shared = nullptr;
    for (auto &ptr : ptrs) ptr = nullptr;
    print_count(observer, "所有 shared_ptr 都设为 nullptr");
    
    shared = observer.lock();
    print_count(observer, "再次 shared = observer.lock()");
    
    return 0;
} 