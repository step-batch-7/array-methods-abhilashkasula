#include <stdio.h>
#include "array.h"

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

int main(void)
{
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

  return 0;
}