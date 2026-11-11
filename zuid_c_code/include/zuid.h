//
// Created by antoi on 11/11/2026.
//

#ifndef ZUID_ZUID_H
#define ZUID_ZUID_H

#include <stdint.h>
#include "macros.h"

struct scalarZUID
{
    char name[4];
    uint8_t version;
    uint64_t time[2];
    uint64_t counter[2];
    uint64_t random[3];
};

ZUID_API struct scalarZUID makeNewZUID();

#endif //ZUID_ZUID_H
