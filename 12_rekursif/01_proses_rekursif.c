/*
    Bahasa Algoritmik:

      procedure tulis(input : n : integer)

      counter : integer
      counter <- n

      if counter > 0 then

        output("proses rekursif dengan nilai counter: ", counter)
        counter <- counter - 1
        tulis(counter)

      end if
*/

#include <stdio.h>

void tulis(int n) {
  int counter;
  counter = n;

  if (counter > 0) {
      printf("proses rekursif dengan nilai counter: %d\n", counter);
      counter = counter - 1;
      tulis(counter);
  }
}

int main() {
  tulis(10);
  return 1;
}
