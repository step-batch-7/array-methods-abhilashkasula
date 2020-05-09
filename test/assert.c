#include <stdio.h>
#include "assert.h"

int tests_passing = 0;
int tests_failing = 0;

Bool assert(int number_1, int number_2)
{
  return number_1 == number_2;
}

Bool assert_array(Array *array_1, Array *array_2)
{
  if (array_1->length != array_2->length)
  {
    return False;
  }

  Bool assertion_status = True;

  for (int i = 0; i < array_1->length; i++)
  {
    assertion_status &= assert(array_1->array[i], array_2->array[i]);
  }

  return assertion_status;
}

Bool assert_array_void(ArrayVoid_ptr array_1, ArrayVoid_ptr array_2, AssertOn assert_data)
{
  if (array_1->length != array_2->length)
  {
    return False;
  }

  Bool assertion_status = True;

  for (int i = 0; i < array_1->length; i++)
  {
    assertion_status &= (*assert_data)(array_1->array[i], array_2->array[i]);
  }

  return assertion_status;
}

Bool assert_object(Object data_1, Object data_2, AssertOn assert_data)
{
  return (*assert_data)(data_1, data_2);
}

void display_assertion(Bool assertion_status, char *message)
{
  if (assertion_status)
  {
    printf(PASS);
    tests_passing++;
  }
  else
  {
    printf(FAIL);
    tests_failing++;
  }

  printf("%s\n", message);
}

void display_passing_count(void)
{
  printf(GREEN "\n%d passing" RESET, tests_passing);
  printf(RED "\n%d failing" RESET, tests_failing);
}
