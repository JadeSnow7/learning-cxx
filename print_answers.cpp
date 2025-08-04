#include <iostream>
#include <cstring>
#include <memory>
#include <string>
#include <vector>

std::vector<std::string> RECORDS;

class Resource {
    std::string _records;

public:
    void record(char record) {
        _records.push_back(record);
    }

    ~Resource() {
        RECORDS.push_back(_records);
    }
};

using Unique = std::unique_ptr<Resource>;
Unique reset(Unique ptr) {
    if (ptr) ptr->record('r');
    return std::make_unique<Resource>();
}
Unique drop(Unique ptr) {
    if (ptr) ptr->record('d');
    return nullptr;
}
Unique forward(Unique ptr) {
    if (ptr) ptr->record('f');
    return ptr;
}

int main() {
    std::vector<std::string> problems[3];

    drop(forward(reset(nullptr)));
    problems[0] = std::move(RECORDS);

    forward(drop(reset(forward(forward(reset(nullptr))))));
    problems[1] = std::move(RECORDS);

    drop(drop(reset(drop(reset(reset(nullptr))))));
    problems[2] = std::move(RECORDS);

    std::cout << "=== 打印 problems 数组的内容 ===" << std::endl;
    for (int i = 0; i < 3; ++i) {
        std::cout << "problems[" << i << "]:" << std::endl;
        std::cout << "  大小: " << problems[i].size() << std::endl;
        std::cout << "  内容: ";
        for (size_t j = 0; j < problems[i].size(); ++j) {
            std::cout << "[" << j << "]=\"" << problems[i][j] << "\" ";
        }
        std::cout << std::endl;
        std::cout << std::endl;
    }

    std::cout << "=== 对应的 answers 数组应该是 ===" << std::endl;
    for (int i = 0; i < 3; ++i) {
        std::cout << "answers[" << i << "] = {";
        for (size_t j = 0; j < problems[i].size(); ++j) {
            if (j > 0) std::cout << ", ";
            std::cout << "\"" << problems[i][j] << "\"";
        }
        std::cout << "};" << std::endl;
    }

    return 0;
} 