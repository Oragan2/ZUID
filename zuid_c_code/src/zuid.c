//
// Created by antoi on 11/11/2026.
//

#include "../include/zuid.h"
#include <time.h>
#include "stdlib.h"

static uint64_t rand64() {
    uint64_t result = 0;
    for (int i = 0; i < 8; i++) {
        result = (result << 8) | (rand() & 0xFF);
    }
    return result;
}

// Fill three 64-bit integers for a total of 192 bits
static void rand192(uint64_t out[3]) {
    out[0] = rand64();
    out[1] = rand64();
    out[2] = rand64();
}

static void clock128(uint64_t out[2])
{

}

static void counter128(uint64_t out[2])
{

}

ZUID_API struct scalarZUID makeNewZUID()
{
    uint64_t clock[2];
    clock128(clock);
    uint64_t counter[2];
    counter128(counter);
    uint64_t random[3];
    rand192(random);

    return {.name="ZUID",.version=1,.clock=clock,.counter=counter,.random=random};
}