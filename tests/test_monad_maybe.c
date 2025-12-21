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
#include "monad.h"


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

    MONAD_CHAIN(&half, &doubl);
    MONAD_CHAIN(&doubl, &succ);
    struct maybe v = {false, 10};
    MONAD_RUN(&half, v);
}


int
main() {
    test_intM();
    return EXIT_SUCCESS;
}
