/**
 * @file test.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-11-23
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef TEST_H
#define TEST_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define print_warning printf("Warning in function %s:%d\n", __FUNCTION__ ,__LINE__);
typedef enum{
    OK,
    ERROR
} ERRORS;
ERRORS test_push();
ERRORS test_pop();
ERRORS test_top();
ERRORS test_resizeUp();
ERRORS test_resizeDown();
int run_all_tests();
#endif