/*
    Bahasa Algoritmik:

      procedure faktorial(input : n : integer, input/output : hasil : integer)

        if n > 1 then

          hasil < hasil * n
          output("rekursif dengan nilai hasil: ", hasil, "nilai n: ", n)
          n <- n - 1
          faktorial(n, hasil)

        (end if)

      (end procedure)

      ( algoritma utama )

        hasil : integer
        hasil <- 1
        faktorial(10, hasil)

      ( end of algoritma utama )
*/

#include <stdio.h>

void faktorial(int n, int hasil) {
  if (n > 1) {
      hasil = hasil * n;
      printf("rekursif dengan nilai hasil: %d nilai n: %d\n", hasil, n);
      n = n - 1;
      faktorial(n, hasil);
  }
}

int main() {
  int hasil;
  hasil = 1;
  faktorial(10, hasil);
  return 1;
}
