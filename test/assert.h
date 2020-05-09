
#ifndef __ASSERT_H
#define __ASSERT_H

#include "../array.h"
#include "../array_void.h"

#define RESET "\033[0m"
#define GREEN "\033[32m"
#define RED "\033[31m"
#define PASS GREEN " \u2714 " RESET
#define FAIL RED " \u2718 " RESET

typedef Bool (*AssertOn)(Object, Object);

void display_assertion(Bool, char *);
void display_passing_count(void);
Bool assert_array(Array *, Array *);
Bool assert(int, int);
Bool assert_array_void(ArrayVoid_ptr, ArrayVoid_ptr, AssertOn);
Bool assert_object(Object, Object, AssertOn);

#endif
