/*
  Bahasa Algoritmik:

    tabInt : array [1 ... 10] of integer
    tabInt <- (34, 67, 23, 28, 15, 89, 67, 28, 18)

    i : integer
    temp : integer

    minIndeks : integer
    j : integer

    for i <- 1 to (10-1) do

      {inisialisasi indeks elemen minimum}
      minIndeks <- 1

      {perulangan mencari nilai minimum sepanjang indeks i + 1 sampai jumlah elemen array}

      for j <- i + 1 to 10 do
        if tabInt[minIndeks] > tabInt[j] then
          minIndeks <- j
        { end if }
      { end for }

      { menukar posisi elemen }
      temp <- tabInt[i]
      tabInt[i] <- tabInt[minIndeks]
      tabInt[minIndeks] <- temp

    { end for }
*/

int main() {

  int tabInt[10] = {34, 67, 23, 28, 98, 15, 89, 67, 28, 18};
  int i;
  int temp;

  int minIndeks;
  int j;

  for (i=0; i<(10-1); i++) {
    /* inisialisasi indeks elemen minimun */
    minIndeks = i;

    /* perulangan mencari nilai minimum sepanjang indek i + 1 sampai jumlah elemen array */
    for (j=(i+1); j<10; j++) {
      if (tabInt[minIndeks] > tabInt[j]) {
        minIndeks = j;
      }
    }

    /* menukar posisi elemen */
    temp = tabInt[i];
    tabInt[i] = tabInt[minIndeks];
    tabInt[minIndeks] = temp;

  }

  return 1;
}
