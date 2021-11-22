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

exceptions stack_verify(stack* stack);

/**
 * @fn stack* stack_init()
 * @brief a function that creates a stack with a length of 10 elements
 * @details the function that creates a stack with a length of 10 elements initializes the default parameters
 * @return stack* 
 */

stack* stack_init(){
    stack *st = (stack*)calloc(sizeof(stack), 1);
    st->length = 10;
    double *arr = (double*) calloc(sizeof(double), st->length + sizeof(unsigned long long));
    st->arr = arr;
    st->iter = 0;
    return st;
}

/**
 * @fn void resize_up(stack* stack)
 * @brief increases the length of the array
 * @details doubles the length of the stack array
 * @param stack the stack passed to the function
 */

void resize_up(stack* stack){
    if (stack == NULL) {
        //printf("the stack ponter is NULL");
        return;
    }
    stack->length = 2 * stack->length;
    double* new_arr = (double*) calloc(sizeof(double), stack->length);
    for (size_t i = 0; i < stack->length/2; i++) {
        new_arr[i] = stack->arr[i];
    }
    free(stack->arr);
    stack->arr = new_arr;
    return;
}

/**
 * @fn void resize_down(stack* stack)
 * @brief void resize_down(stack* stack)
 * @details the function reduces the length of the stack array by half
 * @param stack the stack passed to the function
 */

void resize_down(stack* stack){
    if (stack == NULL) {
        //printf("the stack ponter is NULL");
        return;
    }
    stack->length = (stack->length)/2;
    double* new_arr = (double*) calloc(sizeof(double), stack->length);
    for (size_t i = 0; i < stack->length; i++) {
        new_arr[i] = stack->arr[i];
    }
    free(stack->arr);
    stack->arr = new_arr;
    return;
}

/**
 * @fn void push(stack* stack, double info)
 * @brief adds an element to the array
 * @param stack the stack passed to the function
 * @param info data that is being moved to the array
 */

void push(stack* stack, double info){
    if (stack == NULL) {
        //printf("the stack ponter is NULL");
        return;
    }
    if(stack->iter >= stack->length-1) {
        resize_up(stack);
    }
    stack->arr[stack->iter] = info;
    stack->iter++;
    if(stack_verify(stack) == Out_of_range){
        // code
        return;
    }
    return;
}

/**
 * @fn double pop(stack* stack)
 * @brief the function removes the last element of the stack
 * @param stack the stack passed to the function
 * @return the value that was deleted
 */

double pop(stack* stack){
    if (stack == NULL) {
        //printf("the stack ponter is NULL");
        return;
    }
    if (stack->iter <=stack->length/2) {
        resize_down(stack);
    }
    double tmp = stack->arr[stack->iter--];
    return tmp;
}

/**
 * @brief 
 * 
 * @param stack 
 * @return double 
 */

double top(stack* stack){
    if (stack == NULL) {
        //printf("the stack ponter is NULL");
        return;
    }
    return stack->arr[stack->iter-1];;
}

/**
 * @fn void stack_destroy(stack* stack)
 * @brief the function cleans the stack passed to it
 * 
 * @param stack the stack passed to the function
 */

void stack_destroy(stack* stack){
    if (stack == NULL) {
        //printf("the stack ponter is NULL");
        return;
    }
    free(stack->arr);
    free(stack);
    return;
}

/**
 * @brief  
 * 
 * @param stack 
 * @return exceptions 
 */
exceptions stack_verify(stack* stack){
    if (stack == NULL) {
        //printf("the stack ponter is NULL");
        return;
    }
    if (stack->arr[stack->length] != kanareika)
    {
        return Out_of_range;
    }
    return Successfully;
}