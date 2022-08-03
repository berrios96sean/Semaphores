/**
 * @file tcb.h
 * @author Sean Berrios
 * @brief
 * @version 0.2
 * @date 2022-07-29
 *
 */

#ifndef TCB_H
#define TCB_H
#define _XOPEN_SOURCE 600
#include <ucontext.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <setjmp.h>

typedef struct TCB_t
{
    struct TCB_t *next;
    struct TCB_t *prev;
    ucontext_t context;
    int thread_id;

} TCB_t;

int global_thread_id = 0;

void init_TCB(TCB_t *tcb, void(*function), void *stackP, int stack_size, int arg1)
{
    memset(tcb, '\0', sizeof(TCB_t)); 
    getcontext(&tcb->context);        
    tcb->context.uc_stack.ss_sp = stackP;
    tcb->context.uc_stack.ss_size = (size_t)stack_size;
    tcb->thread_id = arg1;
    makecontext(&tcb->context, function, 0); 
}

#endif