#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "array_void.h"

ArrayVoid_ptr create_void_array(int length)
{
  ArrayVoid_ptr new_void_array = malloc(sizeof(ArrayVoid));
  new_void_array->length = length;
  new_void_array->array = malloc(sizeof(void *) * length);
  return new_void_array;
}

ArrayVoid_ptr create_void_array_from(Object *array, int length)
{
  ArrayVoid_ptr new_void_array = create_void_array(length);
  memcpy(new_void_array->array, array, sizeof(Object) * length);
  return new_void_array;
}

void destroy_void_array(ArrayVoid_ptr list)
{
  for (int i = 0; i < list->length; i++)
  {
    free(list->array[i]);
  }

  free(list->array);
  free(list);
}

void display_void_array(ArrayVoid_ptr void_array, Displayer display_data)
{
  for (int i = 0; i < void_array->length; i++)
  {
    (*display_data)(void_array->array[i]);
  }
  printf("\n");
}

ArrayVoid_ptr map_void(ArrayVoid_ptr src, MapperVoid mapper)
{
  ArrayVoid_ptr new_void_array = create_void_array(src->length);

  for (int i = 0; i < src->length; i++)
  {
    new_void_array->array[i] = (*mapper)(src->array[i]);
  }

  return new_void_array;
}

ArrayVoid_ptr filter_void(ArrayVoid_ptr src, PredicateVoid predicate)
{
  Object filtered[src->length];
  int length = 0;

  for (int i = 0; i < src->length; i++)
  {
    if ((*predicate)(src->array[i]))
    {
      filtered[length] = src->array[i];
      length++;
    }
  }

  return create_void_array_from(filtered, length);
}

Object reduce_void(ArrayVoid_ptr src, Object context, ReducerVoid reducer)
{
  for (int i = 0; i < src->length; i++)
  {
    // printf("%d %d", *(Int_ptr)context, *(Int_ptr)src->array[i])
    context = (*reducer)(context, src->array[i]);
  }

  return context;
}
