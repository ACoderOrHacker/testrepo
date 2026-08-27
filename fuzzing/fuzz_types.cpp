#include <cstddef>
#include <cstdint>

import oe.types;

extern "C" int LLVMFuzzerTestOneInput(const std::uint8_t* data, std::size_t size) {
    oe::u8 accumulator = 0;
    for (std::size_t index = 0; index < size; ++index) {
        accumulator ^= data[index];
        oe::byte value{data[index]};
        value <<= accumulator & 7U;
        accumulator ^= static_cast<oe::u8>(value);
    }
    return 0;
}
