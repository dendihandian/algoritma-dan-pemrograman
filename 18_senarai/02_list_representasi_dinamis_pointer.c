#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct {
  char nim[10];
  char nama[50];
  char nilai[2];
} nilaiMatkul;

typedef struct elmt *alamatelmt;

typedef struct elmt {
  nilaiMatkul elmt;
  alamatelmt next;
} elemen;

typedef struct {
  elemen *first;
} list;

/*
** Membuat List
*/
void createList(list *L) {
  (*L).first = NULL;
}

/*
** Mencari Banyak Element Dalam Suatu List
*/
int countElement(list L) {
  int hasil = 0;
  if (L.first != NULL) {
    // list tidak kosong
    elemen *elmt;

    // inisialisasi
    elmt = L.first;

    while (elmt != NULL) {
      // proses
      hasil = hasil + 1;
      // iterasi
      elmt = elmt->next;
    }
  }

  return hasil;
}

/*
** Tambah Elemen Pada Awal List
*/
void addFirst(char nim[], char nama[], char nilai[], list *L) {
  elemen *elmt;
  elmt = (elemen *) malloc (sizeof (elemen));
  strcpy(elmt->elmt.nim, nim);
  strcpy(elmt->elmt.nama, nama);
  strcpy(elmt->elmt.nilai, nilai);
  elmt->next = (*L).first;
  (*L).first = elmt;
  elmt = NULL;
}

/*
** Tambah Elemen Setelah Elemen Yang Ditentukan
*/
void addAfter(elemen *prec, char nim[], char nama[], char nilai[], list *L) {
  elemen *elmt;
  elmt = (elemen *) malloc (sizeof (elemen));
  strcpy(elmt->elmt.nim, nim);
  strcpy(elmt->elmt.nama, nama);
  strcpy(elmt->elmt.nilai, nilai);
  elmt->next = prec->next;
  prec->next = elmt;
  elmt = NULL;
}

/*
** Tambah Elemen Pada Akhir List
*/
void addLast(char nim[], char nama[], char nilai[], list *L) {
  if ((*L).first == NULL) {
    //  jika list adalah list kosong
    addFirst(nim, nama, nilai, L);
  } else {
    // jika list tidak kosong
    elemen *elmt;
    elmt = (elemen *) malloc (sizeof (elemen));
    strcpy(elmt->elmt.nim, nim);
    strcpy(elmt->elmt.nama, nama);
    strcpy(elmt->elmt.nilai, nilai);
    elmt->next = NULL;

    // mencari elemen terakhir list
    elemen *last = (*L).first;

    while (last->next != NULL) {
      // iterasi
      last = last->next;
    }

    last->next = elmt;
    elmt = NULL;
  }
}

/*
** Hapus Elemen Pertama Pada List
*/
void delFirst(list *L) {
  if ((*L).first != NULL) {
    // jika list bukan list kosong
    elemen *elmt = (*L).first;
    (*L).first = (*L).first->next;
    elmt->next = NULL;
    free(elmt);
  }
}

/*
** Hapus Elemen Setelah Elemen Yang Ditentukan
*/
void delAfter(elemen *prec, list *L) {
  elemen *elmt = prec->next;
  prec->next = elmt->next;
  elmt->next = NULL;
  free(elmt);
}

/*
** Hapus Elemen Terakhir Pada List
*/
void delLast(list *L) {
  if ((*L).first != NULL) {
    // jika list tidak kosong
    if (countElement(*L) == 1) {
      // list terdiri dari satu elemen
      delFirst(L);
    }
  } else {
    // mencari elemen terakhir list
    elemen *last = (*L).first;
    elemen *before_last;

    while (last->next != NULL) {
      // iterasi
      before_last = last;
      last = last->next;
    }

    before_last->next = NULL;
    free(last);
  }
}

/*
** Hapus Semua Elemen Pada List
*/
void delAll(list *L) {
  if (countElement(*L) != 0) {
    int i;
    for (i=countElement(*L); i>=1; i--) {
      // proses menghapus elemen list
      delLast(L);
    }
  }
}

/*
** Cetak Elemen-elemen Pada List
*/
void printElement(list L) {
  if (L.first != NULL) {
    // jika list tidak kosong

    // inisialisasi
    elemen *elmt = L.first;
    int i = 1;

    while (elmt != NULL) {
      // proses
      printf("elemen ke : %d\n", i);
      printf("nim : %s\n", elmt->elmt.nim);
      printf("nama : %s\n", elmt->elmt.nama);
      printf("nilai : %s\n", elmt->elmt.nilai);
      printf("----------------------\n");

      elmt = elmt->next;
      i = i + 1;
    }
  } else {
    // proses jika list kosong
    printf("list kosong\n");
  }
}

int main() {
  list L;

  createList(&L);
  printElement(L);

  printf("==================\n");
  addFirst("13501019", "Andik", "A", &L);
  addAfter(L.first, "13501037", "Shalahuddin", "A", &L);
  addLast("13501058", "Rosa", "A", &L);
  printElement(L);
  printf("==================\n");
  delLast(&L);
  delAfter(L.first, &L);
  delFirst(&L);
  printElement(L);
  printf("==================\n");

  return 0;
}
