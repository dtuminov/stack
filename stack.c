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
 * @fn stack* stack_init()
 * @brief a function that creates a stack with a length of 10 elements
 * @details the function that creates a stack with a length of 10 elements initializes the default parameters
 * @return stack* 
 */

stack* stack_init(){
    double *arr = (double*) calloc(sizeof(double), 10);
    stack *st = (stack*)calloc(sizeof(stack), 1);
    st->arr = arr;
    st->length = 10;
    // ставим указатель на первый элемент массива
    st->iter = 0;
    st->kanareika = rand()*rand()*rand();
    //??
    st->arr[st->length-1] = st->kanareika;
    return st;
}

/**
 * @fn void resize_up(stack* stack)
 * @brief increases the length of the array
 * @details doubles the length of the stack array
 * @param stack the stack passed to the function
 */

void resize_up(stack* stack){
    stack->length = 2 * stack->length;
    double* new_arr = (double*) calloc(sizeof(double), stack->length);
    for (size_t i = 0; i < stack->length/2; i++) {
        new_arr[i] = stack->arr[i];
    }
    new_arr[stack->length-1] = stack->kanareika;
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
    stack->length = (stack->length)/2;
    double* new_arr = (double*) calloc(sizeof(double), stack->length);
    for (size_t i = 0; i < stack->length; i++) {
        new_arr[i] = stack->arr[i];
    }
    stack->arr[stack->length-1] = stack->kanareika;
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
    //1 - kanareyra and 1 - iter
    if(stack->iter >= stack->length-2) {
        resize_up(stack);
    }
    stack->arr[stack->iter] = info;
    stack->iter++;
    return;
}

/**
 * @fn double pop(stack* stack)
 * @brief the function removes the last element of the stack
 * @param stack the stack passed to the function
 * @return the value that was deleted
 */

double pop(stack* stack){
    if (stack->iter <= (stack->length/2)-1) {
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
    return stack->arr[stack->iter-1];;
}

/**
 * @fn void stack_destroy(stack* stack)
 * @brief the function cleans the stack passed to it
 * 
 * @param stack the stack passed to the function
 */

void stack_destroy(stack* stack){
    free(stack->arr);
    free(stack);
    return;
}