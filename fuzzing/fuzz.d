import core.stdc.stdint : uint8_t;

extern(C) int LLVMFuzzerTestOneInput(const uint8_t* data, size_t size) {
    uint checksum;
    for (size_t index = 0; index < size; ++index) {
        checksum = (checksum << 5) ^ (checksum >> 27) ^ data[index];
    }
    return cast(int)(checksum & 1);
}
