#include <stdio.h>

int tabInt[10] = {34, 67, 23, 28, 98, 15, 89, 67, 28, 18};

void quickSort(int l, int r) {
  int i;
  int j;
  int temp;

  i = l;
  j = r;

  do {
    while (tabInt[i] < tabInt[r]) {
      i = i + 1;
    }

    while (tabInt[j] > tabInt[l]) {
      j = j - 1;
    }

    if (i < j) {
      temp = tabInt[i];
      tabInt[i] = tabInt[j];
      tabInt[j] = temp;
      i = i + 1;
      j = j - 1;
    }
  } while (i <= j);

  if (l < j) {
    quickSort(l, j);
  }

  if (i < r) {
    quickSort(i, r);
  }
}

void tulis() {
  int i;
  for (i=0; i<10; i++) {
    printf("%d\n", tabInt[i]);
  }
}

int main() {

  tulis();
  quickSort(0, 9);
  tulis();

  return 1;
}
