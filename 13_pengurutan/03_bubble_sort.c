/*
    Bahasa Algoritmik:
      tabInt: array[1...10] of integer
      tabInt <- {34, 67, 23, 28, 98}
      i : integer
      temp : integer
      tukar : boolean

      repeat
      { inisialisasi nilai tukar sebelum ada pertukaran diset false }
      tukar <- false

      { pengulangan dan memeriksa apakah ada pertukaran }
      for i <- 1 to (5-1) do

        { jika ada nilai yang dipertukarkan }
        if tabInt[j] > tabInt[i+1] then

          { menukar posisi elemen }
          temp <- tabInt[i]
          tabInt[i] <- tabInt[i+1]
          tabInt[i+1] <- temp
          tukar <- true

        {end if}
      {end for}
      until (tukar <> true)
*/

int main() {

  int tabInt[5] = {34, 67, 23, 28, 98};

  int i;
  int temp;
  int tukar;

  do {
    // inisialisasi nilai tukar sebelum ada pertukaran diset false
    tukar = 0;

    // pengulangan dan memeriksa apakah ada pertukaran
    for (i=0; i<(5-1); i++) {
      // jika ada nilai yang dipertukarkan
      if (tabInt[i] > tabInt[i+1]) {
        // menukar posisi elemen
        temp = tabInt[i];
        tabInt[i] = tabInt[i+1];
        tabInt[i+1] = temp;
        tukar = 1;
      }
    }
  } while (tukar == 1);

  return 1;
}
