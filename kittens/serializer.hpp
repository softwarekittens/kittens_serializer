#pragma once

// requires msgpack-c to be installed
// note: msgpack-c is the header-only library: https://github.com/msgpack/msgpack-c

#include <msgpack.hpp>
#include <sstream>
#include <string>

namespace Kittens {
namespace Serializer {

// seralize any supported data to string
// the only requirement: msgpack should be able to serialize it
template <typename Container, typename... Args>
Container serialize(Args&&... args);

// convert data from string
// the only requirement: msgpack should be able to convert it
template <typename Container, typename... Args>
void convert(const Container& container, Args&&... args);

} // namespace Serializer
} // namespace Kittens

#include "impl/serializer_impl.h"
