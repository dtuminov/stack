/**
 * @file stack.c
 * @author tuminov dmitriy (you@domain.com)
 * @brief 
 * @version 0.3
 * @date 2021-11-20
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "stack.h"

const unsigned long long kanareika = 79564576;
const char* exceptions_array[] = {"SUCCESSFULLY", "CRASHED", "OUT_OF_RANGE","EMPTY_STACK","OPENNING_FILE_ERROR","DIFFERENT_HASH"};
const int seed = 5;

//local funcs
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

//stack part
/**
 * @fn stack* stack_init()
 * @brief a function that creates a stack with a length of 10 elements
 * @details the function that creates a stack with a length of 10 elements initializes the default parameters
 * @return stack* 
 */

stack* stack_init(){
    stack *st = (stack*)calloc(sizeof(stack), 1);
    st->length = 10;
    elem_t *arr = (elem_t*) calloc(sizeof(elem_t), st->length + sizeof(unsigned long long));
    st->arr = arr;
    st->iter = 0;
    st->status = Successfully;
    st->arr[st->length-1] = kanareika;
    return st;
}

/**
 * @fn exceptions resize_up(stack* stack)
 * @brief increases the length of the array
 * @details doubles the length of the stack array
 * @param stack the stack passed to the function
 */

exceptions resize_up(stack* stack){
    if (stack == NULL)
        return Empty_stack;
    stack->length = 2 * stack->length;
    stack->arr = (elem_t*) realloc(stack->arr, stack->length*sizeof(elem_t));
    stack->arr[stack->length-1] = kanareika;
    return Successfully;
}

/**
 * @fn exceptions resize_down(stack* stack)
 * @brief void resize_down(stack* stack)
 * @details the function reduces the length of the stack array by half
 * @param stack the stack passed to the function
 */
//to realize the realloc functonal
exceptions resize_down(stack* stack){
    if (stack == NULL)
        return Empty_stack;
    stack->length = (stack->length)/2;
    stack->arr = (elem_t*) realloc(stack->arr, stack->length*sizeof(elem_t));
    stack->arr[stack->length-1] = kanareika;
    return Successfully;
}

/**
 * @fn exceptions push(stack* stack, double info)
 * @brief adds an element to the array
 * @param stack the stack passed to the function
 * @param info data that is being moved to the array
 */

exceptions push(stack* stack, elem_t info){
    if (stack == NULL)
        return Empty_stack;
    if (stack->iter>0)
       stack_verify(stack);
    if(stack->iter >= stack->length-2) 
        resize_up(stack);
    stack->arr[stack->iter] = info;
    stack->iter++;
    //making hash
    stack->hash = murmur3_32((uint8_t*)stack->arr, stack->length, seed);
    stack_verify(stack);
    return Successfully;
}

/**
 * @fn elem_t pop(stack* stack)
 * @brief the function removes the last element of the stack
 * @param stack the stack passed to the function
 * @return the value that was deleted
 */

elem_t pop(stack* stack){
    if (stack == NULL)
        return Empty_stack;
    if (stack->iter>0)
        stack_verify(stack);
    //checking if inter < 0
    if ((stack->iter-2) < 0) 
        return 0; 
    //main part of pop()
    if (stack->iter <= stack->length/3)
        resize_down(stack);
    elem_t tmp = stack->arr[stack->iter--];
    stack->hash = murmur3_32((uint8_t*)stack->arr, stack->length, seed);
    stack_verify(stack);
    return tmp;
}

/**
 * @fn elem_t top(stack* stack)
 * @brief get the last element of stack 
 * 
 * @param stack the stack passed to the function
 * @return double, last element of stack
 */

elem_t top(stack* stack){
    if (stack == NULL)
        return Empty_stack;
    return stack->arr[stack->iter-1];;
}

/**
 * @fn exceptions stack_destroy(stack* stack)
 * @brief the function cleans the stack passed to it
 * 
 * @param stack the stack passed to the function
 */

exceptions stack_destroy(stack* stack){
    if (stack == NULL)
        return Empty_stack;
    free(stack->arr);
    free(stack);
    return Successfully;
}
//exceptions part

/**
 * @fn exceptions make_dump(stack* stack)
 * @brief make a dumo of current status of stack
 * 
 * @param stack the stack passed to the function
 * @return exceptions , code of error
 */

exceptions make_dump(stack* stack){
    if (stack == NULL)
        return Empty_stack;
    FILE *file = fopen("files/log.txt", "a");
    //checking is the file opened
    if (file == NULL) {
        printf("File was not opened");
        return Openning_file_error;
    }
    // getting info about running prcecc
    char *string = getTime();
    // print info about stack
    fprintf(file, "................................\nInformation about stack ");
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
    //values
    fprintf(file, "kanareika value = %d\n", kanareika);
    fprintf(file, "original stack hash value = %d\n", stack->hash);
    fprintf(file, "current stack hash value = %d\n", murmur3_32((uint8_t*)stack->arr, stack->length, seed));
    fprintf(file, "stack status = %s\n", exceptions_array[stack->status]);
    fprintf(file, "procces ended\n................................\n\n\n\n");
    // cleaning memory
    free(string);
    //closing file
    fclose(file);
    return Successfully;
}

/**
 * @fn exceptions kanareika_verify(stack* stack)
 * @brief checking OUT_OF_RANGE situation
 * 
 * @param stack the stack passed to the functio
 * @return exceptions exceptions , code of error
 */

exceptions kanareika_verify(stack* stack){
    if (stack->arr[stack->length-1] != kanareika) { 
        stack->status = Out_of_range; 
        return Out_of_range; 
    }
    return Successfully;
}

/**
 * @fn exceptions hash_verify(stack* stack)
 * @brief compared hash of array
 * 
 * @param stack the stack passed to the function
 * @return exceptions exceptions , code of error
 */

exceptions hash_verify(stack* stack){
    if (stack->hash != murmur3_32((uint8_t*)stack->arr, stack->length, seed)) {
        stack->status = Different_hash;
        return Different_hash;
    }
    return Successfully;
}

/**
 * @fn exceptions stack_verify(stack* stack)
 * @brief  checking if user try to use wrong(last+1) elemet of array
 * 
 * @param stack  the stack passed to the function
 * @return exceptions 
 */

exceptions stack_verify(stack* stack){
    if (stack == NULL)
        return Empty_stack;
    kanareika_verify(stack);
    hash_verify(stack);
    if (stack->status != Successfully) {
        make_dump(stack);
        return Crashed;
    }
    return Successfully;
}

/**
 * @brief Get the Length object
 * @fn int GetLength (stack* stack)
 * 
 * @param stack he stack passed to the function
 * @return int 
 */

int GetLength (stack* stack){
    return stack->length-1;
}

/**
 * @brief the scramble for hash function 
 * @fn uint32_t murmur_32_scramble(uint32_t k)
 * @param k 
 * @return uint32_t 
 */

uint32_t murmur_32_scramble(uint32_t k) {
    k *= 0xcc9e2d51;
    k = (k << 15) | (k >> 17);
    k *= 0x1b873593;
    return k;
}

/**
 * @fn uint32_t murmur3_32(const uint8_t* key, size_t len, uint32_t seed)
 * @brief making hash 
 * 
 * @param key 
 * @param len 
 * @param seed 
 * @return uint32_t 
 */

uint32_t murmur3_32(const uint8_t* key, size_t len, uint32_t seed)
{
	uint32_t h = seed;
    uint32_t k;
    /* Read in groups of 4. */
    for (size_t i = len >> 2; i; i--) {
        // Here is a source of differing results across endiannesses.
        // A swap here has no effects on hash properties though.
        memcpy(&k, key, sizeof(uint32_t));
        key += sizeof(uint32_t);
        h ^= murmur_32_scramble(k);
        h = (h << 13) | (h >> 19);
        h = h * 5 + 0xe6546b64;
    }
    /* Read the rest. */
    k = 0;
    for (size_t i = len & 3; i; i--) {
        k <<= 8;
        k |= key[i - 1];
    }
    // A swap is *not* necessary here because the preceding loop already
    // places the low bytes in the low places according to whatever endianness
    // we use. Swaps only apply when the memory is copied in a chunk.
    h ^= murmur_32_scramble(k);
    /* Finalize. */
	h ^= len;
	h ^= h >> 16;
	h *= 0x85ebca6b;
	h ^= h >> 13;
	h *= 0xc2b2ae35;
	h ^= h >> 16;
	return h;
}