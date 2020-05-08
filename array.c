#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "array.h"

Array *create_array(int length)
{
  Array *new_array = malloc(sizeof(Array));
  new_array->length = length;
  new_array->array = malloc(sizeof(int) * new_array->length);
  return new_array;
}

Array *create_array_from(int *list, int length)
{
  Array *new_array = create_array(length);
  memcpy(new_array->array, list, sizeof(int) * length);
  return new_array;
}

void destroy_array(Array *list)
{
  free(list->array);
  free(list);
}

void display_array(Array *list)
{
  for (int i = 0; i < list->length; i++)
  {
    printf("%d ", list->array[i]);
  }
  printf("\n");
}

Array *map(Array *src, Mapper mapper)
{
  Array *new_array = create_array(src->length);

  for (int i = 0; i < src->length; i++)
  {
    new_array->array[i] = (*mapper)(src->array[i]);
  }

  return new_array;
}

Array *filter(Array *src, Predicate predicate)
{
  int filtered_numbers[src->length];
  int length = 0;

  for (int i = 0; i < src->length; i++)
  {
    if ((*predicate)(src->array[i]))
    {
      filtered_numbers[length] = src->array[i];
      length++;
    }
  }

  return create_array_from(filtered_numbers, length);
}

int reduce(Array *src, int context, Reducer reducer)
{
  for (int i = 0; i < src->length; i++)
  {
    context = (*reducer)(context, src->array[i]);
  }

  return context;
}
