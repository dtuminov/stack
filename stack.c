/**
 * @file stack.c
 * @author tuminov dmitriy (you@domain.com)
 * @brief 
 * @version 0.2
 * @date 2021-11-20
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "stack.h"
const unsigned long long kanareika = 7956576;
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
    st->status = Successfully;
    st->arr[st->length] = kanareika;
    return st;
}

/**
 * @fn char* getTime()
 * @brief Get the Time object
 * 
 * @return char* , current time
 */

char* getTime(){
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    char string[64];
    assert(strftime(string, sizeof(string), "%c", tm));
    char* rez = strdup(string);
    return rez;
}

/**
 * @fn exceptions make_dump(stack* stack)
 * @brief make a dumo of current status of stack
 * 
 * @param stack the stack passed to the function
 * @return exceptions , code of error
 */

exceptions make_dump(stack* stack){
    if (stack == NULL) {
        stack->status = Empty_stack;
        assert(stack->status == Empty_stack);
    }
    FILE *file = fopen("files/log.txt", "w");
    //checking is the file opened
    if (file == NULL) {
        printf("File was not opened");
        return Openning_file_error;
    }
    // getting info about running prcecc
    char *string = getTime();
    // print info about stack
    fprintf(file, "Information about stack ");
    fprintf(file, "%s\n", string);
    fprintf(file, "length = %lu\n", stack->length); 
    fprintf(file, "the current iterator = %d\n", stack->iter);
    fprintf(file, "The memory of array = %p\n", stack->arr);
    fprintf(file, "Elements of array:\n");
    //printing elements of array
    for (size_t i = 0; i < stack->length; i++)
    {
        fprintf(file, "arr[%i] = %lf\n", i, stack->arr[i]);
    }
    fprintf(file, "kanareika value = %d\n", kanareika);
    // cleaning memory
    free(string);
    //closing file
    fclose(file);
    return Successfully;
}

/**
 * @fn void resize_up(stack* stack)
 * @brief increases the length of the array
 * @details doubles the length of the stack array
 * @param stack the stack passed to the function
 */

void resize_up(stack* stack){
    if (stack == NULL) {
        stack->status = Empty_stack;
        assert(stack->status == Empty_stack);
    }
    stack->length = 2 * stack->length;
    double* new_arr = (double*) calloc(sizeof(double), stack->length);
    //overwriting array
    for (size_t i = 0; i < stack->length/2; i++) {
        new_arr[i] = stack->arr[i];
    }
    free(stack->arr);
    //add kanareika
    new_arr[stack->length] = kanareika;
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
        stack->status = Empty_stack;
        assert(stack->status == Empty_stack);
        return;
    }
    stack->length = (stack->length)/2;
    double* new_arr = (double*) calloc(sizeof(double), stack->length);
    // overwriting array
    for (size_t i = 0; i < stack->length; i++) {
        new_arr[i] = stack->arr[i];
    }
    free(stack->arr);
    //maby dangerous moment
    new_arr[stack->length] = kanareika;
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
        stack->status = Empty_stack;
        assert(stack->status == Empty_stack);
        return;
    }
    if(stack->iter >= stack->length-1) {
        resize_up(stack);
    }
    stack->arr[stack->iter] = info;
    stack->iter++;
    if(stack_verify(stack) == Out_of_range)  {
        assert(make_dump(stack) != Successfully);
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
        stack->status = Empty_stack;
        assert(stack->status == Empty_stack);
        return 0;
    }
    //checking if inter < 0
    if ((stack->iter-1) < 0) { return 0; }
    //main part of pop()
    if (stack->iter <=stack->length/2) {
        resize_down(stack);
    }
    double tmp = stack->arr[stack->iter--];
    if(stack_verify(stack) == Out_of_range){
        // code
        assert(make_dump(stack) != Successfully);
        return 0;
    }
    return tmp;
}

/**
 * @fn double top(stack* stack)
 * @brief get the last element of stack 
 * 
 * @param stack the stack passed to the function
 * @return double, last element of stack
 */

double top(stack* stack){
    if (stack == NULL) {
        stack->status = Empty_stack;
        assert(stack->status == Empty_stack);
        return 0;
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
        stack->status = Empty_stack;
        assert(stack->status == Empty_stack);
        return;
    }
    free(stack->arr);
    free(stack);
    return;
}

/**
 * @fn exceptions stack_verify(stack* stack)
 * @brief  checking if user try to use wrong(last+1) elemet of array
 * 
 * @param stack 
 * @return exceptions 
 */

exceptions stack_verify(stack* stack){
    if (stack == NULL) {
        stack->status = Empty_stack;
        assert(stack->status == Empty_stack);
    }
    if (stack->arr[stack->length] != kanareika) { return Out_of_range; }
    return Successfully;
}