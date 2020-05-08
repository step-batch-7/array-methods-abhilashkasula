#include <stdio.h>
#include "assert.h"

int square(int number)
{
  return number * number;
}

void test_map(void)
{
  printf("map\n");

  Array *numbers = create_array(0);
  Array *expected = create_array(0);
  Array *actual_1 = map(numbers, &square);
  display_assertion(assert_array(actual_1, expected), "should get empty array for empty array given");

  Array *numbers_2 = create_array(1);
  numbers_2->array[0] = 2;
  Array *actual_2 = map(numbers_2, &square);
  Array *expected_2 = create_array(1);
  expected_2->array[0] = 4;
  display_assertion(assert_array(actual_2, expected_2), "should map a number for one value in the array");

  Array *numbers_3 = create_array(2);
  numbers_3->array[0] = 2;
  numbers_3->array[1] = 3;
  Array *actual_3 = map(numbers_3, &square);
  Array *expected_3 = create_array(2);
  expected_3->array[0] = 4;
  expected_3->array[1] = 9;
  display_assertion(assert_array(actual_3, expected_3), "should map two numbers for two values in the array");

  Array *numbers_4 = create_array(4);
  numbers_4->array[0] = 2;
  numbers_4->array[1] = 3;
  numbers_4->array[2] = 4;
  numbers_4->array[3] = 5;
  Array *actual_4 = map(numbers_4, &square);
  Array *expected_4 = create_array(4);
  expected_4->array[0] = 4;
  expected_4->array[1] = 9;
  expected_4->array[2] = 16;
  expected_4->array[3] = 25;
  display_assertion(assert_array(actual_4, expected_4), "should map all numbers for values more than two in the array");
}

int main(void)
{
  test_map();
  display_passing_count();
  return 0;
}
