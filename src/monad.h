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
#ifndef SRC_MONAD_H_
#define SRC_MONAD_H_


/* (private api) generic stuff (must included once) */
#define LNAME_PASTE(x, y) x ## y
#define LNAME_EVAL(x, y)  LNAME_PASTE(x, y)
#define LNAME(n) LNAME_EVAL(T, n)
#define LTYPE() LNAME_EVAL(T, _t)


/* (public) shorthands */
#define MONAD_RUN(m, v) (m)->run(m, v)
#define MONAD_RETURN(m, v) if ((m)->next) (m)->next->run((m)->next, v); return
#define MONAD_CHAIN(a, b) (a)->next = b


#endif  // SRC_MONAD_H_


/* generic<template> definitions, and must be defined on every inclue without
 * any header guard and the T preprocessor variable have to be undef/define
 * before including this file.
 */
struct LNAME(M);
typedef void (*LNAME(_monad_t)) (struct LNAME(M)*, LTYPE());
struct LNAME(M) {
    LNAME(_monad_t) run;
    struct LNAME(M) *next;
    /* category specific members */
};
