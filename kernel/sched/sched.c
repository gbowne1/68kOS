/*
 * kernel/sched/sched.c
 * Round-robin scheduler
 */

#include <kernel/sched/task.h>

static task_t *current_task;

void schedule(void) {
    /* * Switch current_task to the next task in the list.
     * This is usually called from a timer interrupt.
     */
}

/* End of file */
