/**
 * @file stack.c
 * @author tuminov dmitriy (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-11-20
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "stack.h"


/**
 * @brief 
 * 
 * @return stack* 
 */

stack* stack_init(){
    double *arr = (double*) calloc(sizeof(double), 10);
    stack *st = (stack*)calloc(sizeof(stack), 1);
    st->arr = arr;
    st->length = 10;
    st->iter = 1;
    return st;
}

/**
 * @brief 
 * 
 * @param stack 
 */

void resize(stack* stack){
    stack->length = 2 * stack->length;
    double* new_arr = (double*) calloc(sizeof(double), stack->length);
    for (size_t i = 0; i < stack->length/2; i++) {
        new_arr[i] = stack->arr[i];
    }
    stack->arr = new_arr;
    return;
}

/**
 * @brief 
 * 
 * @param stack 
 */

void shrink_to_fit(stack* stack){
    stack->length = (stack->length)/2;
    double* new_arr = (double*) calloc(sizeof(double), stack->length);
    for (size_t i = 0; i < stack->length; i++) {
        new_arr[i] = stack->arr[i];
    }
    stack->arr = new_arr;
    return;
}

/**
 * @brief 
 * 
 * @param stack 
 * @param info 
 */

void push(stack* stack, double info){
    if(stack->iter >= stack->length-2) {
        resize(stack);
    }
    stack->arr[stack->iter-1] = info;
    stack->iter++;
    return;
}

/**
 * @brief 
 * 
 */

double pop(stack* stack){
    if (stack->iter-1 <= stack->length/2) {
        shrink_to_fit(stack);
    }
    double tmp = stack->arr[stack->iter];
    stack->iter--;
    return tmp;
}

/**
 * @brief 
 * 
 * @param stack 
 */

void stack_destroy(stack* stack){
    free(stack->arr);
    free(stack);
    return;
}