#include <stdio.h>
int main() {
  int tabel1[4];
  int tabel2[4];
  int tabel3[8];

  int penghitung1;
  int penghitung2;
  int penghitung3;
  int penghitung;

  for (penghitung1=0; penghitung1<4; penghitung1++) {
    printf("masukan angka:\n");
    scanf("%d", &tabel1[penghitung1]);
    printf("\n");
  }

  for (penghitung2=0; penghitung2<4; penghitung2++) {
    printf("masukan angka:\n");
    scanf("%d", &tabel2[penghitung2]);
    printf("\n");
  }

  // inisialisasi indeks awal setiap tabel
  penghitung1 = 0;
  penghitung2 = 0;
  penghitung3 = 0;

  while ((penghitung1 < 4) && (penghitung2 < 4)) {
    if (tabel1[penghitung1] < tabel2[penghitung2]) {
      tabel3[penghitung3] = tabel1[penghitung1];
      penghitung1 = penghitung1 + 1;
      penghitung3 = penghitung3 + 1;
    } else if (tabel2[penghitung2] < tabel1[penghitung1]) {
      tabel3[penghitung3] = tabel2[penghitung2];
      penghitung2 = penghitung2 + 1;
      penghitung3 = penghitung3 + 1;
    } else {
      tabel3[penghitung3] = tabel1[penghitung1];
      penghitung1 = penghitung1 + 1;
      penghitung3 = penghitung3 + 1;
      tabel3[penghitung3] = tabel2[penghitung2];
      penghitung2 = penghitung2 + 1;
      penghitung3 = penghitung3 + 1;
    }
  }

  if (penghitung1 < (4-1)) {
    for (penghitung=penghitung1; penghitung<4; penghitung++) {
      tabel3[penghitung3] = tabel1[penghitung];
      penghitung3 = penghitung3 + 1;
    }
  }

  if (penghitung2 < (4-1)) {
    for (penghitung=penghitung2; penghitung<4; penghitung++) {
      tabel3[penghitung3] = tabel2[penghitung];
      penghitung3 = penghitung3 + 1;
    }
  }

  int i;
  for (i=0; i<8; i++) {
    printf("%d\n", tabel3[i]);
  }

  return 1;
}
