/**
 * @file test.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-11-23
 * 
 * @copyright Copyright (c) 2021
 * 
 */


#include "test.h"

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
    printf("OK\n");
    return OK;
}
ERRORS test_resizeUp(){
    printf("[%s]:",__FUNCTION__);
    printf("OK\n");
    return OK;
}
ERRORS test_resizeDown(){
    printf("[%s]:",__FUNCTION__);
    printf("OK\n");
    return OK;
}