#include <stdio.h>
#include "stack.h"

int main(){
    stack* st = stack_init();
    double a = 10.1;
    push(st, a);
    printf("stack[0] = %lf\n", st->arr[0]);
    push(st, a*2);
    printf("stack[1] = %lf\n", st->arr[1]);
    pop(st);
    printf("pop");
    push(st, 40.4);
    printf("stack[1] = %lf\n", st->arr[1]);
    printf("%d\n", st->iter);
    printf("stack[cur] = %lf", st->arr[st->iter]);

    stack_destroy(st);
    return 0;
}

// глобальный таск написать хрень, которая будет менять размер массива в двое
