#pragma once

namespace Kittens {
namespace Serializer {
//please don't read the code below

namespace Serializer_internal {
struct expand_type {
    template <typename... T>
    expand_type(T&&...) {}
};
} // namespace Serializer_internal

template <typename Container, typename... Args>
Container serialize(Args&&... args) {
    std::stringstream stream;
    msgpack::packer<std::stringstream> packer(&stream);
    packer.pack_array(sizeof...(args));
    //42 is a reason, why this code is working. Without this number we passing void to c-tor
    Serializer_internal::expand_type{(msgpack::pack(stream, std::forward<Args>(args)), 42)...};
    std::string buffer = stream.str();
    Container container(buffer.begin(), buffer.end());
    return container;
}

template <typename Container, typename... Args>
void convert(const Container& container, Args&&... args)
{
    msgpack::object_handle oh = msgpack::unpack(container.data(), container.size());
    msgpack::object deserialized = oh.get();
    std::tuple<Args...> t(std::forward<Args>(args)...);
    deserialized.convert(t);
}

} //namespace Serializer
} //namespace Kittens
