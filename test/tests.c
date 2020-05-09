#include <stdio.h>
#include <stdlib.h>
#include "assert.h"
#include "../array.h"
#include "../array_void.h"

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

Object square_void(Object data)
{
  int *square = malloc(sizeof(int));
  *square = *(Int_ptr)data * *(Int_ptr)data;
  return square;
}

Object conver_to_lowercase(Object data)
{
  Char_ptr lowercase = malloc(sizeof(char));
  *lowercase = *(Char_ptr)data + 32;
  return lowercase;
}

Bool assert_int(Object data_1, Object data_2)
{
  return *(Int_ptr)data_1 == *(Int_ptr)data_2;
}

Bool assert_char(Object data_1, Object data_2)
{
  return *(Char_ptr)data_1 == *(Char_ptr)data_2;
}

Object create_int(int value)
{
  Int_ptr number = malloc(sizeof(int));
  *number = value;
  return (Object)number;
}

Object create_char(char value)
{
  Char_ptr alphabet = malloc(sizeof(char));
  *alphabet = value;
  return (Object)alphabet;
}

Bool is_even_void(Object data)
{
  return (*(Int_ptr)data) % 2 == 0;
}

Bool is_letter_abc(Object data)
{
  char letter = *(Char_ptr)data;

  if (letter == 'a' || letter == 'b' || letter == 'c')
  {
    return True;
  }
  return False;
}

Object add_void(Object context, Object data)
{
  *(Int_ptr)context = *(Int_ptr)context + *(Int_ptr)data;
  return context;
}

void test_map(void)
{
  printf("map\n");

  Array *numbers = create_array(0);
  Array *expected = create_array(0);
  Array *actual_1 = map(numbers, &square);
  display_assertion(assert_array(actual_1, expected), "should get empty array for empty array given");
  destroy_array(numbers);
  destroy_array(actual_1);
  destroy_array(expected);

  Array *numbers_2 = create_array(1);
  numbers_2->array[0] = 2;
  Array *actual_2 = map(numbers_2, &square);
  Array *expected_2 = create_array(1);
  expected_2->array[0] = 4;
  display_assertion(assert_array(actual_2, expected_2), "should map a number for one value in the array");
  destroy_array(numbers_2);
  destroy_array(actual_2);
  destroy_array(expected_2);

  Array *numbers_3 = create_array(2);
  numbers_3->array[0] = 2;
  numbers_3->array[1] = 3;
  Array *actual_3 = map(numbers_3, &square);
  Array *expected_3 = create_array(2);
  expected_3->array[0] = 4;
  expected_3->array[1] = 9;
  display_assertion(assert_array(actual_3, expected_3), "should map two numbers for two values in the array");
  destroy_array(numbers_3);
  destroy_array(actual_3);
  destroy_array(expected_3);

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
  destroy_array(numbers_4);
  destroy_array(actual_4);
  destroy_array(expected_4);
}

void test_filter(void)
{
  printf("filter\n");

  Array *numbers_1 = create_array(0);
  Array *actual_1 = filter(numbers_1, &is_even);
  display_assertion(assert_array(actual_1, numbers_1), "should give empty array for empty array given");
  destroy_array(numbers_1);
  destroy_array(actual_1);

  Array *numbers_2 = create_array(1);
  numbers_2->array[0] = 2;
  Array *actual_2 = filter(numbers_2, &is_even);
  Array *expected_2 = create_array(1);
  expected_2->array[0] = 2;
  char message_2[] = "should filter one element when only one value that satisfy is given";
  display_assertion(assert_array(actual_2, expected_2), message_2);
  destroy_array(numbers_2);
  destroy_array(actual_2);
  destroy_array(expected_2);

  Array *numbers_3 = create_array(1);
  numbers_3->array[0] = 3;
  Array *actual_3 = filter(numbers_3, &is_even);
  Array *expected_3 = create_array(0);
  char message_3[] = "should filter no elements when only one value that don't satisfy is given";
  display_assertion(assert_array(actual_3, expected_3), message_3);
  destroy_array(numbers_3);
  destroy_array(actual_3);
  destroy_array(expected_3);

  Array *numbers_4 = create_array(2);
  numbers_4->array[0] = 2;
  numbers_4->array[1] = 3;
  Array *actual_4 = filter(numbers_4, &is_even);
  Array *expected_4 = create_array(1);
  expected_4->array[0] = 2;
  char message_4[] = "should filter the elements that satisfy for two elements in the list";
  display_assertion(assert_array(actual_4, expected_4), message_4);
  destroy_array(numbers_4);
  destroy_array(actual_4);
  destroy_array(expected_4);

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
  destroy_array(numbers_5);
  destroy_array(actual_5);
  destroy_array(expected_5);

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
  destroy_array(numbers_6);
  destroy_array(actual_6);
  destroy_array(expected_6);

  Array *numbers_7 = create_array(4);
  numbers_7->array[0] = 1;
  numbers_7->array[1] = 3;
  numbers_7->array[2] = 5;
  numbers_7->array[3] = 7;
  Array *actual_7 = filter(numbers_7, &is_even);
  Array *expected_7 = create_array(0);
  char message_7[] = "should filter no elements when all the elements doesn't satisfy";
  display_assertion(assert_array(actual_7, expected_7), message_7);
  destroy_array(numbers_7);
  destroy_array(actual_7);
  destroy_array(expected_7);
}

void test_reduce(void)
{
  printf("reduce\n");

  Array *numbers_1 = create_array(0);
  int actual_1 = reduce(numbers_1, 5, &add);
  display_assertion(assert(actual_1, 5), "should give initial context for empty array given");
  destroy_array(numbers_1);

  Array *numbers_2 = create_array(1);
  numbers_2->array[0] = 5;
  int actual_2 = reduce(numbers_2, 0, &add);
  display_assertion(assert(actual_2, 5), "should add initial value and element for one value given");
  destroy_array(numbers_2);

  Array *numbers_3 = create_array(2);
  numbers_3->array[0] = 5;
  numbers_3->array[1] = 10;
  int actual_3 = reduce(numbers_3, 0, &add);
  display_assertion(assert(actual_3, 15), "should add values for two values given");
  destroy_array(numbers_3);

  Array *numbers_4 = create_array(2);
  numbers_4->array[0] = 5;
  numbers_4->array[1] = 10;
  int actual_4 = reduce(numbers_4, 5, &add);
  display_assertion(assert(actual_4, 20), "should add values with initial value for two values given");
  destroy_array(numbers_4);

  Array *numbers_5 = create_array(5);
  numbers_5->array[0] = 5;
  numbers_5->array[1] = 10;
  numbers_5->array[2] = 20;
  numbers_5->array[3] = 30;
  numbers_5->array[4] = 40;
  int actual_5 = reduce(numbers_5, 0, &add);
  display_assertion(assert(actual_5, 105), "should add values for more than two values given");
  destroy_array(numbers_5);

  Array *numbers_6 = create_array(5);
  numbers_6->array[0] = 5;
  numbers_6->array[1] = 10;
  numbers_6->array[2] = 20;
  numbers_6->array[3] = 30;
  numbers_6->array[4] = 40;
  int actual_6 = reduce(numbers_6, 5, &add);
  display_assertion(assert(actual_6, 110), "should add values with initial context for more than two values given");
  destroy_array(numbers_6);
}

void display_char(void *data)
{
  printf("%c ", *(Char_ptr)data);
}

void test_map_void(void)
{
  printf("map_void\n");

  ArrayVoid_ptr numbers_1 = create_void_array(0);
  ArrayVoid_ptr actual_1 = map_void(numbers_1, &square_void);
  char message[] = "should give empty array for empty array given";
  display_assertion(assert_array_void(actual_1, numbers_1, &assert_int), message);
  destroy_void_array(numbers_1);
  destroy_void_array(actual_1);

  ArrayVoid_ptr numbers_2 = create_void_array(1);
  numbers_2->array[0] = create_int(5);
  ArrayVoid_ptr actual_2 = map_void(numbers_2, &square_void);
  ArrayVoid_ptr expected_2 = create_void_array(1);
  expected_2->array[0] = create_int(25);
  char message_2[] = "should give one value mapped for one element given";
  display_assertion(assert_array_void(actual_2, expected_2, &assert_int), message_2);
  destroy_void_array(numbers_2);
  destroy_void_array(actual_2);
  destroy_void_array(expected_2);

  ArrayVoid_ptr numbers_3 = create_void_array(2);
  numbers_3->array[0] = create_int(5);
  numbers_3->array[1] = create_int(4);
  ArrayVoid_ptr actual_3 = map_void(numbers_3, &square_void);
  ArrayVoid_ptr expected_3 = create_void_array(2);
  expected_3->array[0] = create_int(25);
  expected_3->array[1] = create_int(16);
  char message_3[] = "should give mapped values for two elements given";
  display_assertion(assert_array_void(actual_3, expected_3, &assert_int), message_3);
  destroy_void_array(numbers_3);
  destroy_void_array(actual_3);
  destroy_void_array(expected_3);

  ArrayVoid_ptr numbers_4 = create_void_array(4);
  numbers_4->array[0] = create_int(5);
  numbers_4->array[1] = create_int(4);
  numbers_4->array[2] = create_int(3);
  numbers_4->array[3] = create_int(2);
  ArrayVoid_ptr actual_4 = map_void(numbers_4, &square_void);
  ArrayVoid_ptr expected_4 = create_void_array(4);
  expected_4->array[0] = create_int(25);
  expected_4->array[1] = create_int(16);
  expected_4->array[2] = create_int(9);
  expected_4->array[3] = create_int(4);
  char message_4[] = "should give mapped values for more than two elements given";
  display_assertion(assert_array_void(actual_4, expected_4, &assert_int), message_4);
  destroy_void_array(numbers_4);
  destroy_void_array(actual_4);
  destroy_void_array(expected_4);

  ArrayVoid_ptr alphabets = create_void_array(2);
  alphabets->array[0] = create_char('A');
  alphabets->array[1] = create_char('B');
  ArrayVoid_ptr actual_alphabets = map_void(alphabets, &conver_to_lowercase);
  ArrayVoid_ptr expected_alphabets = create_void_array(2);
  expected_alphabets->array[0] = create_char('a');
  expected_alphabets->array[1] = create_char('b');
  char message_5[] = "should give mapped values for alphabets";
  display_assertion(assert_array_void(actual_alphabets, expected_alphabets, &assert_char), message_5);
  destroy_void_array(alphabets);
  destroy_void_array(actual_alphabets);
  destroy_void_array(expected_alphabets);
}

void test_filter_void(void)
{
  printf("filter_void\n");

  ArrayVoid_ptr numbers_1 = create_void_array(0);
  ArrayVoid_ptr actual_1 = filter_void(numbers_1, &is_even_void);
  char message_1[] = "should give empty array for empty array given";
  display_assertion(assert_array_void(actual_1, numbers_1, &assert_int), message_1);
  destroy_void_array(numbers_1);
  destroy_void_array(actual_1);

  ArrayVoid_ptr numbers_2 = create_void_array(3);
  numbers_2->array[0] = create_int(2);
  numbers_2->array[1] = create_int(3);
  numbers_2->array[2] = create_int(4);
  ArrayVoid_ptr actual_2 = filter_void(numbers_2, &is_even_void);
  ArrayVoid_ptr expected_2 = create_void_array(2);
  expected_2->array[0] = create_int(2);
  expected_2->array[1] = create_int(4);
  char message_2[] = "should give only filtered values for the given numbers";
  display_assertion(assert_array_void(actual_2, expected_2, &assert_int), message_2);
  destroy_void_array(numbers_2);
  destroy_void_array(expected_2);

  ArrayVoid_ptr numbers_3 = create_void_array(3);
  numbers_3->array[0] = create_int(3);
  numbers_3->array[1] = create_int(5);
  numbers_3->array[2] = create_int(7);
  ArrayVoid_ptr actual_3 = filter_void(numbers_3, &is_even_void);
  ArrayVoid_ptr expected_3 = create_void_array(0);
  char message_3[] = "should give empty array for no numbers satisfy";
  display_assertion(assert_array_void(actual_3, expected_3, &assert_int), message_3);
  destroy_void_array(numbers_3);
  destroy_void_array(expected_3);

  ArrayVoid_ptr numbers_4 = create_void_array(3);
  numbers_4->array[0] = create_int(2);
  numbers_4->array[1] = create_int(4);
  numbers_4->array[2] = create_int(8);
  ArrayVoid_ptr actual_4 = filter_void(numbers_4, &is_even_void);
  ArrayVoid_ptr expected_4 = create_void_array(3);
  expected_4->array[0] = create_int(2);
  expected_4->array[1] = create_int(4);
  expected_4->array[2] = create_int(8);
  char message_4[] = "should filter all values for all the numbers satisfy";
  display_assertion(assert_array_void(actual_4, expected_4, &assert_int), message_4);
  destroy_void_array(numbers_4);
  destroy_void_array(expected_4);

  ArrayVoid_ptr alphabets = create_void_array(3);
  alphabets->array[0] = create_char('a');
  alphabets->array[1] = create_char('b');
  alphabets->array[2] = create_char('f');
  ArrayVoid_ptr actual_5 = filter_void(alphabets, &is_letter_abc);
  ArrayVoid_ptr expected_5 = create_void_array(2);
  expected_5->array[0] = create_char('a');
  expected_5->array[1] = create_char('b');
  char message_5[] = "should filter all values that satisfy for alphabets";
  display_assertion(assert_array_void(actual_5, expected_5, &assert_char), message_5);
  destroy_void_array(alphabets);
  destroy_void_array(expected_5);
}

void test_reduce_void(void)
{
  printf("reduce_void\n");

  ArrayVoid_ptr numbers_1 = create_void_array(0);
  Object init_1 = create_int(2);
  Object actual_1 = reduce_void(numbers_1, init_1, &add_void);
  Object expected_1 = create_int(2);
  char message_1[] = "should give the initial context for empty array";
  display_assertion(assert_object(actual_1, expected_1, &assert_int), message_1);
  destroy_void_array(numbers_1);
  free(expected_1);
  free(actual_1);

  ArrayVoid_ptr numbers_2 = create_void_array(3);
  numbers_2->array[0] = create_int(2);
  numbers_2->array[1] = create_int(3);
  numbers_2->array[2] = create_int(4);
  Object init_2 = create_int(0);
  Object actual_2 = reduce_void(numbers_2, init_2, &add_void);
  Object expected_2 = create_int(9);
  char message_2[] = "should add all the values for given numbers";
  display_assertion(assert_object(actual_2, expected_2, &assert_int), message_2);
  destroy_void_array(numbers_2);
  free(expected_2);
  free(actual_2);

  ArrayVoid_ptr numbers_3 = create_void_array(3);
  numbers_3->array[0] = create_int(2);
  numbers_3->array[1] = create_int(3);
  numbers_3->array[2] = create_int(4);
  Object init_3 = create_int(5);
  Object actual_3 = reduce_void(numbers_3, init_3, &add_void);
  Object expected_3 = create_int(14);
  char message_3[] = "should add all the values with initial context for given numbers";
  display_assertion(assert_object(actual_3, expected_3, &assert_int), message_3);
  destroy_void_array(numbers_3);
  free(expected_3);
  free(actual_3);
}

int main(void)
{
  test_map();
  test_filter();
  test_reduce();
  test_map_void();
  test_filter_void();
  test_reduce_void();
  display_passing_count();
  return 0;
}
