import std.datetime.stopwatch : AutoStart, StopWatch;
import std.stdio : writefln;

void main() {
    enum iterations = 10_000_000;
    ubyte value;
    auto timer = StopWatch(AutoStart.yes);
    foreach (_; 0 .. iterations) {
        value = cast(ubyte)((value << 1) ^ 0x5a);
    }
    auto elapsed = timer.peek.total!"hnsecs";
    writefln("d_byte_mixing,iterations=%s,elapsed_hnsecs=%s,checksum=%s",
        iterations, elapsed, value);
}
