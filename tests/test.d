import unit_threaded;

@("addition")
unittest {
    assert(2 + 2 == 4);
}

@("little_endian_encoding")
unittest {
    const value = 0x1234U;
    const encoded = cast(ubyte[])([cast(ubyte)(value & 0xff), cast(ubyte)(value >> 8)]);
    assert(encoded[0] == 0x34);
    assert(encoded[1] == 0x12);
}

mixin runTestsMain!("test");
