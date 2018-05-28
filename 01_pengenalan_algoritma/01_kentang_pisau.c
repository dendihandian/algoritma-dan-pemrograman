/*

  Bahasa Prosedural:
    - Mendeklarasikan kotak kosong yang dipakai sebagai tempat untuk menyimpan kentang dan pisau.
    - Mengisi kotak-kotak kosong yang akan dipergunakan.
    - Menuliskan ke layar 'mulai mengupas kentang'.
    - Memproses kentang dimana kentang saat ini adalah kentang yang telah dikupas dengan pisau.
    - Pisau selesai digunakan
    - Menuliskan ke layar selesai mengupas kentang

  Bahasa Algoritmik:

    kentang : integer
    pisau : integer

    kentang <- 1
    pisau <- 1

    output("mulai mengupas kentang")

    kentang <- kentang + pisau

    pisau <- 0

    output("selesai mengupas kentang")

*/

#include <stdio.h>

int main () {
  int kentang;
  int pisau;

  kentang = 1;
  pisau = 1;

  printf("mulai mengupas kentang\n");

  kentang = kentang + pisau;

  pisau = 0;

  printf("selesai mengupas kentang\n");

  return 1;
}
