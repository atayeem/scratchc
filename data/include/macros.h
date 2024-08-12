// block types:
// - hat blocks
// - C blocks
// - reporter blocks
// - boolean blocks
// - cap blocks
// - stack blocks

#ifndef _S_MACROS_H
#define _S_MACROS_H

#include "includes.h"

typedef struct {
    char id[64];

    enum {
        _default,
        _large,
        _slider,
        _list
    } mode;

    char opcode[64];

} Monitor;



typedef void Hat;

#define forever while(true)

#define async_exec(x, id) \
        pthread_create(id, NULL, x, NULL)

#define await(id) \
        pthread_join(id, NULL)



#endif