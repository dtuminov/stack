#include <stdio.h>
#include <stdlib.h>
#include "tests/test.h"
#include "stack.h"

int main(){
    stack* st = stack_init();
    push(st, 10);
    push(st, 11);   
    pop(st);
    run_all_tests();
    stack_destroy(st);
    return 0;
}
