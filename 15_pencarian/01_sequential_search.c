#include <string.h>
#include <stdio.h>

typedef struct {
  char nim[50];
  char nama[50];
  float nilai;
} nilaiMatkul;

nilaiMatkul tabel[5];

void isi (int i, char nim[], char nama[], float nilai) {
  strcpy(tabel[i].nim, nim);
  strcpy(tabel[i].nama, nama);
  tabel[i].nilai = nilai;
}

int main() {
  char nim_cari[50];
  int ketemu;
  int i;

  isi(0, "13507701", "Nana", 64.75);
  isi(1, "13507702", "Rudi", 75.11);
  isi(2, "13507703", "Dea", 84.63);
  isi(3, "13507704", "Ihsan", 77.07);
  isi(4, "13507705", "Tiara", 66.70);

  strcpy(nim_cari, "13507703");
  ketemu = 0;
  i = 0;

  while((i<5) && (ketemu == 0)) {
    if (strcmp(tabel[i].nim, nim_cari) == 0) {
      // jika data ketemu
      ketemu = 1;
    } else {
      i = i + 1;
    }
  }

  if (ketemu == 1) {
    printf("nim: %s\n", tabel[i].nim);
    printf("nama: %s\n", tabel[i].nama);
    printf("nama: %0.2f\n", tabel[i].nilai);
  } else {
    printf("tidak ditemukan\n");
  }

  return 1;
}
