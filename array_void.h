#ifndef __ARRAY_VOID_H
#define __ARRAY_VOID_H

#include "array.h"

typedef void *Object;
typedef Object (*MapperVoid)(Object);
typedef Bool (*PredicateVoid)(Object);
typedef Object (*ReducerVoid)(Object, Object);

typedef void (*Displayer)(Object);
typedef int *Int_ptr;
typedef char *Char_ptr;

typedef struct
{
  Object *array;
  int length;
} ArrayVoid;

typedef ArrayVoid *ArrayVoid_ptr;

ArrayVoid_ptr map_void(ArrayVoid_ptr src, MapperVoid mapper);
ArrayVoid_ptr filter_void(ArrayVoid_ptr src, PredicateVoid predicate);
Object reduce_void(ArrayVoid_ptr src, Object init, ReducerVoid reducer);

ArrayVoid_ptr create_void_array(int length);
void destroy_void_array(ArrayVoid_ptr list);
void display_void_array(ArrayVoid_ptr void_array, void (*display_data)(void *));
ArrayVoid_ptr create_void_array_from(Object *array, int length);

#endif