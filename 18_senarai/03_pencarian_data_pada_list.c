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
** Mencari
*/
void cari(char kata_cari[], list L) {
  if (L.first != NULL) {
    // list tidak kosong
    elemen *elmt;

    // inisialisasi
    elmt = L.first;

    while (elmt != NULL) {

      if (strcmp(elmt->elmt.nim, kata_cari) == 0) {
        printf("===== KETEMU =====\n");
        printf("nim: %s\n", elmt->elmt.nim);
        printf("nama: %s\n", elmt->elmt.nama);
        printf("nilai %s\n", elmt->elmt.nilai);
        printf("=====================\n");
      }

      // iterasi
      elmt = elmt->next;
    }
  }
}

int main () {
  list L;

  createList(&L);

  addLast("13501019", "Andik", "A", &L);
  addLast("13501037", "Shalahuddin", "A", &L);
  addLast("13501058", "Rosa", "A", &L);

  cari("13501037", L);

  return 0;
}
