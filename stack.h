/**
 * @file stack.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-11-20
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <string.h>

// stack
typedef struct {
    double *arr;
    size_t length;
    int iter;
    double hash;
} stack;
// error codes
typedef enum{
    Successfully = 0,
    Out_of_range,
    Empty_stack
} exceptions;


stack* stack_init();
double pop(stack* stack);
void push(stack* stack, double info);
void resize_up(stack* stack);
void stack_destroy(stack* stack);
void resize_down(stack* stack);
double top(stack* stack);
exceptions stack_verify(stack* stack);
void make_log(stack* stack);
char* getTime();
void make_dump(stack* stack);
#endif