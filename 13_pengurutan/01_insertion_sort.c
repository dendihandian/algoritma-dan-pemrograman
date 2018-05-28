/*
  Bahasa Algoritmik:

    tabInt : array [1 ... 10] of integer
    tabInt <- (34, 67, 23, 28, 15, 89, 67, 28, 18)

    i : integer

    data_sisip : integer
    j : integer

    for i <- 2 to 10 do

      data_sisip <- tabInt
      j <- i - 1

      while (data_sisip < tabInt[j]) and (j > 0) do

        tabInt[j+1] <- tabInt[j]
        j <- j - 1

      (end while)

      tabInt[j+1] <- data_sisip

    (end for)

*/

int main() {

  int tabInt[10] = {34, 67, 23, 28, 98, 15, 89, 67, 28, 18};
  int i;

  int data_sisip;
  int j;

  for (i=1; i<10; i++) {
  
    data_sisip = tabInt[i];
    j = i - 1;

    while ((data_sisip < tabInt[j]) && (j >= 0)) {
        /* jika data array lebih kecil dari data sisip, maka data array digeser ke belakang */
        tabInt[j+1] = tabInt[j];
        j = j - 1;
    }

    /* menempatkan data sisip pada array */
    tabInt[j+1] = data_sisip;

  }

  return 1;
}
