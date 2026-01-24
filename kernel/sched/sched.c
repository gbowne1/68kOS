/*
 * kernel/sched/sched.c
 * Round-robin scheduler
 */

#include <kernel/sched/task.h>

static task_t *current_task;

void schedule(void) {
    if (current_task && current_task->next) {
        current_task = current_task->next;
    }
}

/* End of file */
