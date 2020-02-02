# kittens_serializer

C++ Serializer/Deserializer for variadic templates based on msgpack-c

## example code:

```cpp
#include <kittens/serializer.h>
#include <iostream>
#include <string>

int a = 1;
float b = 2.0f;
std::string c = "3";

// serialize values
std::string serialized_string = Kittens::Serializer::serialize(a, b, c);

int a_;
float b_;
std::string c_;

// deserialize values
Kittens::Serializer::convert(serialized_string, a_, b_, c_);

assert(a == a_);
assert(b == b_);
assert(c == c_);

```



