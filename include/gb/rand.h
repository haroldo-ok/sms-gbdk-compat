#ifndef _RAND_H
#define _RAND_H

#include <types.h>


/*
 * Random generator using the linear congruential method
 *
 * Author: Luc Van den Borre
 */

void initrand(UWORD seed);

UWORD randw(void);

/*
 * Random generator using the linear lagged additive method
 *
 * Author: Luc Van den Borre
 *
 * Note that 'initarand()' calls 'initrand()' with the same seed value, and
 * uses 'rand()' to initialize the random generator.
 */

void initarand(UWORD seed);

UBYTE arand(void);

#define rand()   randw()

#endif /* _GB_H */
