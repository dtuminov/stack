/**
 * @file stack.h
 * @author tuminov dmitriy (you@domain.com)
 * @brief 
 * @version 0.2
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

extern const unsigned long long kanareika;
extern const char* exceptions_array[];

typedef double elem_t;
/**
 * @brief error codes
 * 
 */
typedef enum{
    //functions
    Successfully = 0,
    Crashed,
    //stack status
    Out_of_range,
    Empty_stack,
    Openning_file_error,
    Different_hash
} exceptions;
/**
 * @brief stack
 *  
 */
typedef struct {
    elem_t *arr;
    size_t length;
    int iter;
    int hash;
    exceptions status;
} stack;

//funcs
stack* stack_init();
exceptions stack_verify(stack* stack);
elem_t pop(stack* stack);
void push(stack* stack, elem_t info);
void resize_up(stack* stack);
void stack_destroy(stack* stack);
void resize_down(stack* stack);
elem_t top(stack* stack);
char* getTime();
exceptions make_dump(stack* stack);
int make_hash(elem_t* array);
exceptions hash_verify(stack* stack);
exceptions kanareika_verify(stack* stack);
#endif