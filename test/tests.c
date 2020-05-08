#include <stdio.h>
#include "assert.h"

int square(int number)
{
  return number * number;
}

Bool is_even(int number)
{
  return number % 2 == 0;
}

int add(int num1, int num2)
{
  return num1 + num2;
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

void test_filter(void)
{
  printf("filter\n");

  Array *numbers_1 = create_array(0);
  Array *actual_1 = filter(numbers_1, &is_even);
  display_assertion(assert_array(actual_1, numbers_1), "should give empty array for empty array given");

  Array *numbers_2 = create_array(1);
  numbers_2->array[0] = 2;
  Array *actual_2 = filter(numbers_2, &is_even);
  Array *expected_2 = create_array(1);
  expected_2->array[0] = 2;
  char message_2[] = "should filter one element when only one value that satisfy is given";
  display_assertion(assert_array(actual_2, expected_2), message_2);

  Array *numbers_3 = create_array(1);
  numbers_3->array[0] = 3;
  Array *actual_3 = filter(numbers_3, &is_even);
  Array *expected_3 = create_array(0);
  char message_3[] = "should filter no elements when only one value that don't satisfy is given";
  display_assertion(assert_array(actual_3, expected_3), message_3);

  Array *numbers_4 = create_array(2);
  numbers_4->array[0] = 2;
  numbers_4->array[1] = 3;
  Array *actual_4 = filter(numbers_4, &is_even);
  Array *expected_4 = create_array(1);
  expected_4->array[0] = 2;
  char message_4[] = "should filter the elements that satisfy for two elements in the list";
  display_assertion(assert_array(actual_4, expected_4), message_4);

  Array *numbers_5 = create_array(4);
  numbers_5->array[0] = 2;
  numbers_5->array[1] = 3;
  numbers_5->array[2] = 4;
  numbers_5->array[3] = 5;
  Array *actual_5 = filter(numbers_5, &is_even);
  Array *expected_5 = create_array(2);
  expected_5->array[0] = 2;
  expected_5->array[1] = 4;
  char message_5[] = "should filter the elements that satisfy for more than two elements in the list";
  display_assertion(assert_array(actual_5, expected_5), message_5);

  Array *numbers_6 = create_array(4);
  numbers_6->array[0] = 2;
  numbers_6->array[1] = 4;
  numbers_6->array[2] = 6;
  numbers_6->array[3] = 8;
  Array *actual_6 = filter(numbers_6, &is_even);
  Array *expected_6 = create_array(4);
  expected_6->array[0] = 2;
  expected_6->array[1] = 4;
  expected_6->array[2] = 6;
  expected_6->array[3] = 8;
  char message_6[] = "should filter all the elements when all the elements satisfy";
  display_assertion(assert_array(actual_6, expected_6), message_6);

  Array *numbers_7 = create_array(4);
  numbers_7->array[0] = 1;
  numbers_7->array[1] = 3;
  numbers_7->array[2] = 5;
  numbers_7->array[3] = 7;
  Array *actual_7 = filter(numbers_7, &is_even);
  Array *expected_7 = create_array(0);
  char message_7[] = "should filter no elements when all the elements doesn't satisfy";
  display_assertion(assert_array(actual_7, expected_7), message_7);
}

void test_reduce(void)
{
  printf("reduce\n");

  Array *numbers_1 = create_array(0);
  int actual_1 = reduce(numbers_1, 0, &add);
  display_assertion(assert(actual_1, 0), "should give initial context for empty array given");

  Array *numbers_2 = create_array(1);
  numbers_2->array[0] = 5;
  int actual_2 = reduce(numbers_2, 0, &add);
  display_assertion(assert(actual_2, 5), "should give the reduced value for one value given");

  Array *numbers_3 = create_array(2);
  numbers_3->array[0] = 5;
  numbers_3->array[1] = 10;
  int actual_3 = reduce(numbers_3, 0, &add);
  display_assertion(assert(actual_3, 15), "should give the reduced value for two values given");

  Array *numbers_4 = create_array(5);
  numbers_4->array[0] = 5;
  numbers_4->array[1] = 10;
  numbers_4->array[2] = 20;
  numbers_4->array[3] = 30;
  numbers_4->array[4] = 40;
  int actual_4 = reduce(numbers_4, 0, &add);
  display_assertion(assert(actual_4, 105), "should give the reduced value for more than two values given");
}

int main(void)
{
  test_map();
  test_filter();
  test_reduce();
  display_passing_count();
  return 0;
}
