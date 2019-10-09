#include "chata/String.h"
#include <benchmark/benchmark.h>

const char *text = "123.abcdefg.56789..zzf";

static void bench_string_split(benchmark::State &state)
{
    for (auto _ : state)
    {
        chata::String::Split(text, ".");
    }
}
BENCHMARK(bench_string_split);

BENCHMARK_MAIN();
