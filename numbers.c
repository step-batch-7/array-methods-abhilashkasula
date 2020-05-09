#include <stdio.h>
#include <stdlib.h>
#include "array.h"
#include "array_void.h"

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
  Int_ptr result = malloc(sizeof(int));
  *result = *(Int_ptr)data * *(Int_ptr)data;
  return (Object)result;
}

void display_int(Object data)
{
  printf("%d ", *(Int_ptr)data);
}

void display_char(Object data)
{
  printf("%c ", *(Char_ptr)data);
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

Object create_int(int value)
{
  int *number = malloc(sizeof(int));
  *number = value;
  return (Object)number;
}

Object create_char(char value)
{
  char *letter = malloc(sizeof(char));
  *letter = value;
  return (Object)letter;
}

void perform_array_methods(void)
{
  printf("array methods\n");

  Array *numbers = create_array(6);
  numbers->array[0] = 10;
  numbers->array[1] = 11;
  numbers->array[2] = 12;
  numbers->array[3] = 13;
  numbers->array[4] = 14;
  numbers->array[5] = 15;

  Array *squares_of_numbers = map(numbers, &square);
  display_array(squares_of_numbers);

  Array *evens = filter(numbers, &is_even);
  display_array(evens);

  int sum_of_numbers = reduce(numbers, 0, &add);
  printf("Sum of numbers: %d\n", sum_of_numbers);

  destroy_array(numbers);
  destroy_array(squares_of_numbers);
  destroy_array(evens);
}

void perform_array_void_methods(void)
{
  printf("\narray void methods\n");

  ArrayVoid_ptr new_void_array = create_void_array(2);
  new_void_array->array[0] = create_int(2);
  new_void_array->array[1] = create_int(3);

  ArrayVoid_ptr alphabets = create_void_array(3);
  alphabets->array[0] = create_char('a');
  alphabets->array[1] = create_char('b');
  alphabets->array[2] = create_char('e');

  ArrayVoid_ptr mapped = map_void(new_void_array, &square_void);
  display_void_array(mapped, &display_int);

  ArrayVoid_ptr filtered_numbers = filter_void(new_void_array, &is_even_void);
  ArrayVoid_ptr filtered_alphabets = filter_void(alphabets, &is_letter_abc);

  display_void_array(filtered_numbers, &display_int);
  display_void_array(filtered_alphabets, &display_char);

  Object init = create_int(2);
  Object sum = reduce_void(new_void_array, init, &add_void);
  printf("Sum: %d\n", *(Int_ptr)sum);

  destroy_void_array(mapped);
  destroy_void_array(new_void_array);
  destroy_void_array(alphabets);
  free(sum);
}

int main(void)
{
  perform_array_methods();
  perform_array_void_methods();
  return 0;
}