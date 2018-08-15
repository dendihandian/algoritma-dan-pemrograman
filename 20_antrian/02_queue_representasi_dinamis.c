#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct {
  char nim[10];
  char nama[50];
  float nilai;
} nilaiMatKul;

typedef struct elm *alamatelmt;
typedef struct elm {
  nilaiMatKul elmt;
  alamatelmt next;
} elemen;

typedef struct {
  elemen *first;
  elemen *last;
} queue;

void createEmpty(queue *Q) {
  (*Q).first = NULL;
  (*Q).last = NULL;
}

int isEmpty (queue Q) {
  int hasil = 0;
  if (Q.first == NULL) {
    hasil = 1;
  }
  return hasil;
}

int countElement(queue Q) {
  int hasil = 0;
  if (Q.first != NULL) {
    // queue tidak kosong
    elemen *elmt;

    // inisialisasi
    elmt = Q.first;

    while (elmt != NULL) {
      // proses
      hasil = hasil + 1;

      // iterasi
      elmt = elmt->next;
    }
  }

  return hasil;
}

void add (char nim[], char nama[], float nilai, queue *Q) {
  elemen *elmt;
  elmt = (elemen *) malloc (sizeof (elemen));
  strcpy(elmt->elmt.nim, nim);
  strcpy(elmt->elmt.nama, nama);
  elmt->elmt.nilai = nilai;
  elmt->next = NULL;
  if ((*Q).first == NULL) {
    (*Q).first = elmt;
  } else {
    (*Q).last->next = elmt;
  }
  (*Q).last = elmt;
  elmt = NULL;
}

void del (queue *Q) {
  if ((*Q).first != NULL) {
    // jika queue bukan queue kosong
    elemen *elmt = (*Q).first;
    (*Q).first = (*Q).first->next;
    elmt->next = NULL;
    free(elmt);
  }
}

void printQueue (queue Q) {
  if (Q.first != NULL) {
    printf("----- isi queue -----\n");
    elemen *elmt = Q.first;
    int i = 1;
    while (elmt != NULL) {
      printf("======================\n");
      printf("elemen ke: %d\n", i);
      printf("nim: %s\n", elmt->elmt.nim);
      printf("nama: %s\n", elmt->elmt.nama);
      printf("nilai: %f\n", elmt->elmt.nilai);

      // iterasi
      elmt = elmt->next;
      i = i + 1;
    }
    printf("========================\n");
  } else {
    // proses jika queue kosong
    printf("queue kosong\n");
  }
}

int main () {
  queue Q;
  createEmpty(&Q);
  printQueue(Q);

  printf("======================\n");
  add("13507701", "Luke", 64.75, &Q);
  add("13507702", "Han", 75.11, &Q);
  add("13507703", "Leia", 84.63, &Q);
  printQueue(Q);

  printf("======================\n");
  del(&Q);
  del(&Q);
  printQueue(Q);

  return 0;
}
