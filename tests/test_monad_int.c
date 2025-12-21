/* standard */
#include <unistd.h>

/* thirdparty */
#include <cutest.h>

/* local public */
typedef int int_t;
#undef T
#define T int
#include "monad.h"


struct otherM {
    struct intM;

    int other;
};


static void
_add(struct otherM *m, int v) {
    MONAD_RETURN(m, v + m->other);
}


static void
_div(struct otherM *m, int v) {
    MONAD_RETURN(m, v / m->other);
}


static void
_done(struct otherM *m, int v) {
    eqint(3, v);
}


static void
test_intM() {
    struct otherM add2 = {
        .run = (int_monad_t)_add,
        .other = 2
    };
    struct otherM div4 = {
        .run = (int_monad_t)_div,
        .other = 4
    };
    struct intM tail = {
        .run = (int_monad_t)_done,
    };

    MONAD_CHAIN(&add2, (struct intM*)&div4);
    MONAD_CHAIN(&div4, &tail);
    MONAD_RUN((struct intM*)&add2, 10);
}


int
main() {
    test_intM();
    return EXIT_SUCCESS;
}
