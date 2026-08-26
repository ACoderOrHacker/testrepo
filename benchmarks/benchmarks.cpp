#include <benchmark/benchmark.h>

static void BM_byte_mixing(benchmark::State& state) {
    unsigned char value = 0;
    for (auto _ : state) {
        value = static_cast<unsigned char>((value << 1U) ^ 0x5AU);
        benchmark::DoNotOptimize(value);
    }
}

BENCHMARK(BM_byte_mixing);
BENCHMARK_MAIN();
