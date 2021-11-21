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

typedef struct {
    double *arr;
    size_t length;
    int iter;
} stack;

stack* stack_init();
double pop();
void push(stack* stack, double info);
void resize(stack* stack);
void stack_destroy(stack* stack);
void shrink_to_fit(stack* stack);
#endif