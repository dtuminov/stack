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
    printf("======All functions tested successfully======\n");
    return 0;
}

ERRORS test_push(){
    printf("[%s]:",__FUNCTION__);

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