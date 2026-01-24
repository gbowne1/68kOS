/*
 * kernel/sched/task.h
 */

#ifndef TASK_H
#define TASK_H

#include <stdint.h>

typedef struct {
    uint32_t regs[15]; /* d0-d7, a0-a6 */
    uint32_t pc;       /* Program Counter */
    uint32_t sr;       /* Status Register */
    uint32_t usp;      /* User Stack Pointer */
} cpu_context_t;

typedef struct task {
    void *stack_ptr;
    int tid;
    uint32_t id;
    cpu_context_t context;
    struct task *next;
} task_t;

#endif

/* End of file */
