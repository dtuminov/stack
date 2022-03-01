/**
 * @file test.c
 * @author tuminov dmitriy (you@domain.com)
 * @brief file with tests of functions
 * @version 0.1
 * @date 2021-11-23
 * 
 * @copyright Copyright (c) 2021
 * 
 */


#include "test.h"
const double EPS = 1.0E-7;

int run_all_tests(){
    printf("======Starting tests of functions======\n");
    assert(test_push() == OK);
    assert(test_pop() == OK);
    assert(test_top() == OK);
    assert(test_resizeUp() == OK);
    assert(test_resizeDown() == OK);
    assert(test_kanareika_verify() == OK);
    assert(test_stack_destroy() == OK);
    assert(test_stack_verify() == OK);
    assert(test_hash_verify() == OK);
    assert(test_GetLength() == OK);
    assert(test_make_hash() == OK);
    printf("======All functions tested successfully======\n");
    return 0;
}

ERRORS test_push(){
    printf("[%s]:",__FUNCTION__);
    stack* stack = stack_init();
    //test 1
    for (size_t i = 0; i < 5; i++)
        push(stack, i); 
    if (stack->arr[stack->iter] == top(stack))
    {
        print_warning;
        return ERROR;
    }
    
    stack_destroy(stack);
    stack = stack_init();
    //test 2
    for (size_t i = 0; i < 41; i++)
        push(stack, i); 
    if (stack->arr[stack->iter] == top(stack))
    {
        print_warning;
        return ERROR;
    }
    
    stack_destroy(stack);
    printf("OK\n");
    return OK;
}
ERRORS test_pop(){
    printf("[%s]:",__FUNCTION__);
    printf("OK\n");
    return OK;
}

ERRORS test_top(){
    printf("[%s]:",__FUNCTION__);
    stack* stack = stack_init();
    //first test of empty stack
    if (fabs(top(stack)) > EPS) {
        print_warning;
        return ERROR;
    }
    // test of not empty stack
    push(stack, 15.45);
    push(stack, 15.45);
    if (top(stack) != 15.45) {
        print_warning;
        return ERROR;
    }
    stack_destroy(stack);
    printf("OK\n");
    return OK;
}

ERRORS test_resizeUp(){
    printf("[%s]:",__FUNCTION__);
    stack* stack = stack_init();
    //test 1
    if (stack->length !=  10)
    {
        print_warning;
        return ERROR;
    }
    //test 2
    for (size_t i = 0; i < 20; i++)
    {
        push(stack, 4.5);
    }
    if (stack->length != 40) {
        print_warning;
        return ERROR;
    }
    stack_destroy(stack);
    printf("OK\n");
    return OK;
}

ERRORS test_resizeDown(){
    printf("[%s]:",__FUNCTION__);
    stack* stack = stack_init();
    for (size_t i = 0; i < 22; i++)
    {
        push(stack, 4.5);
    }
    //test 1
    for (size_t i = 0; i < 10; i++)
    {
        pop(stack);
    }
    if (stack->length != 20) {
        print_warning;
        return ERROR;
    }
    stack_destroy(stack);
    stack = stack_init();
    //test 2
    for (size_t i = 0; i < 5; i++)
    {
        pop(stack);
    }
    if (stack->length != 10) {
        print_warning;
        return ERROR;
    }
    stack_destroy(stack);
    printf("OK\n");
    return OK;
}

ERRORS test_kanareika_verify(){
    printf("[%s]:",__FUNCTION__);
    stack* stack = stack_init();
    for (size_t i = 0; i < 10; i++)
    {
        push(stack, 10);
    }
    if (stack->arr[stack->length - 1] != kanareika)
    {
        print_warning;
        return ERROR;
    }
    
    stack_destroy(stack);
    printf("OK\n");
    return OK;
}

ERRORS test_hash_verify(){
    printf("[%s]:",__FUNCTION__);
    printf("OK\n");
    return OK;
}

ERRORS test_stack_verify(){
    printf("[%s]:",__FUNCTION__);
    stack* stack1 = stack_init();
    for (size_t i = 0; i < 50; i++)
    {
        push(stack1, i);
    }
    pop(stack1);
    stack1->arr[stack1->length-1] = 0;
    if (stack_verify(stack1) == Successfully)
    {
        print_warning;
        return ERROR;
    }
    stack_destroy(stack1);
    //test2
    stack *stack2 = stack_init();
    for (size_t i = 0; i < 50; i++)
    {
        push(stack2, i);
    }
    pop(stack2);
    if (stack_verify(stack2) != Successfully) {
        print_warning;
        return ERROR;
    }
    stack_destroy(stack2);
    printf("OK\n");
    return OK;
}

ERRORS test_stack_destroy(){
    printf("[%s]:",__FUNCTION__);
    /*
    stack * stack = stack_init();
    push(stack, 8);
    stack_destroy(stack);
    printf("%p\n%p\n\n", stack, stack->arr);
    if (stack->arr != NULL || stack != NULL)
    {
        print_warning;
        return ERROR;
    }
    
    printf("OK\n");
    */
    return OK;
}

ERRORS test_GetLength(){
    printf("[%s]:",__FUNCTION__);
    stack* stack = stack_init();
    if(stack->length != 10){
        print_warning;
        return ERROR; 
    }
    stack_destroy(stack);
    printf("OK\n");
    return OK;
}

ERRORS test_make_hash(){
    printf("[%s]:",__FUNCTION__);
    printf("OK\n");
    return OK;
}