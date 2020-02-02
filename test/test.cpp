#include "../kittens/serializer.hpp"

int main() {
    
    int a = 1;
    float b = 2.0f;
    std::string c = "3";
    
    std::string resultStr = Kittens::Serializer::serialize<std::string>(a, b, c);
    
    std::vector<char> resultVec = Kittens::Serializer::serialize<std::vector<char>>(a, b, c);
    
    int a_;
    float b_;
    std::string c_;
    
    Kittens::Serializer::convert(resultStr, a_, b_, c_);
    assert(a == a_);
    assert(b == b_);
    assert(c == c_);
    
    Kittens::Serializer::convert(resultVec, a_, b_, c_);
    assert(a == a_);
    assert(b == b_);
    assert(c == c_);
    
    
    return 0;
}
