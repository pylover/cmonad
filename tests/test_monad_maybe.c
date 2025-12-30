// Copyright 2025 Vahid Mardani
/*
 * This file is part of cmonad.
 *  cmonad is free software: you can redistribute it and/or modify it under
 *  the terms of the GNU General Public License as published by the Free
 *  Software Foundation, either version 3 of the License, or (at your option)
 *  any later version.
 *
 *  cmonad is distributed in the hope that it will be useful, but WITHOUT ANY
 *  WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 *  FOR A PARTICULAR PURPOSE. See the GNU General Public License for more
 *  details.
 *
 *  You should have received a copy of the GNU General Public License along
 *  with cmonad. If not, see <https://www.gnu.org/licenses/>.
 *
 *  Author: Vahid Mardani <vahid.mardani@gmail.com>
 */
/* standard */
#include <unistd.h>
#include <stdbool.h>

/* thirdparty */
#include <cutest.h>


typedef struct maybe {
    bool empty;
    int value;
} maybe_t;
#undef T
#define T maybe
#include "cmonad.h"


static void
_half(struct maybeM *m, struct maybe v) {
    if (v.empty) {
        return;
    }

    struct maybe out = {false, v.value / 2};
    MONAD_RETURN(m, out);
}


static void
_doubl(struct maybeM *m, struct maybe v) {
    if (v.empty) {
        return;
    }

    struct maybe out = {false, v.value * 2};
    MONAD_RETURN(m, out);
}


static void
_succ(struct maybeM *m, struct maybe v) {
    isfalse(v.empty);
    eqint(10, v.value);
}


static void
test_intM() {
    struct maybeM half = {_half};
    struct maybeM doubl = {_doubl};
    struct maybeM succ = {_succ};

    MONAD_BIND(&half, &doubl);
    MONAD_BIND(&doubl, &succ);
    struct maybe v = {false, 10};
    MONAD_RUN(&half, v);
}


int
main() {
    test_intM();
    return EXIT_SUCCESS;
}
