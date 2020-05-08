#include <stdio.h>
#include "assert.h"

int square(int number)
{
  return 5;
}

void test_map(void)
{
  printf("map\n");

  Array *numbers = create_array(0);
  Array *expected = create_array(1);

  Array *actual = map(numbers, &square);
  display_assertion(assert_array(actual, expected), "should get empty array for empty array given");
}

int main(void)
{
  test_map();
  display_passing_count();
  return 0;
}
