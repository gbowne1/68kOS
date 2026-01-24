#include <kernel/sched/task.h>
#include <kernel/mm/malloc.h> // Assuming you have a basic allocator

static task_t *task_list = 0;
extern task_t *current_task; // Defined in sched.c

task_t* task_create(void (*entry_point)(void)) {
    // 1. Allocate the task control block and the stack
    task_t *t = (task_t*)kmalloc(sizeof(task_t));
    uint32_t *stack = (uint32_t*)kmalloc(2048); // 2KB Stack
    
    // 2. M68K stacks grow downward. Point to the top.
    uint32_t *sp = (uint32_t*)((uint8_t*)stack + 2048);

    // 3. Fake the Stack Frame for the 'rte' and 'movem' in assembly
    // The order must match your timer_isr exactly!
    
    *(--sp) = (uint32_t)entry_point; // Initial Program Counter
    *(--sp) = 0x2000;               // Initial Status Register (Sup. Mode)

    // Push 15 placeholders for d0-d7 and a0-a6
    for (int i = 0; i < 15; i++) {
        *(--sp) = 0;
    }

    t->stack_ptr = sp; 
    t->id = next_tid++; // Simple incrementing ID
    
    // 4. Link it into your Round-Robin circular list
    if (!task_list) {
        task_list = t;
        t->next = t; // Points to itself
    } else {
        t->next = task_list->next;
        task_list->next = t;
    }

    return t;
}
