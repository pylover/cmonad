#ifndef CORE_MONAD_H_
#define CORE_MONAD_H_
/* generic stuff (must included once) */
#define LNAME_PASTE(x, y) x ## y
#define LNAME_EVAL(x, y)  LNAME_PASTE(x, y)
#define LNAME(n) LNAME_EVAL(T, n)
#define LTYPE() LNAME_EVAL(T, _t)


#define MONAD_RUN(m, v) (m)->run(m, v)
#define MONAD_RETURN(m, v) if ((m)->next) (m)->next->run((m)->next, v); return
#define MONAD_CHAIN(a, b) (a)->next = b


#endif  // CORE_MONAD_H_


/* generic<template> definitions */
struct LNAME(M);
typedef void (*LNAME(_monad_t)) (struct LNAME(M)*, LTYPE());
struct LNAME(M) {
    LNAME(_monad_t) run;
    struct LNAME(M) *next;
    /* category specific members */
};
