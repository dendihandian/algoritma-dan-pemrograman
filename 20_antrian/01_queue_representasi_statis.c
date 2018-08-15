#include <stdio.h>
#include <string.h>

typedef struct {
  char nim[10];
  char nama[50];
  float nilai;
} nilaiMatKul;

typedef struct {
  int first;
  int last;
  nilaiMatKul data[10];
} queue;

void createEmpty (queue *Q) {
  (*Q).first = -1;
  (*Q).last = -1;
}

int isEmpty(queue Q) {
  int hasil = 0;
  if (Q.first == -1) {
    hasil = 1;
  }
  return hasil;
}

int isFull(queue Q) {
  int hasil = 0;
  if (Q.last == 9) {
    hasil = 1;
  }
  return hasil;
}

void add (char nim[], char nama[], float nilai, queue *Q) {
  if (isEmpty(*Q) == 1) {
    // jika queue kosong
    (*Q).first = 0;
    (*Q).last = 0;
    strcpy((*Q).data[0].nim, nim);
    strcpy((*Q).data[0].nama, nama);
    (*Q).data[0].nilai = nilai;
  } else {
    // jika queue tidak kosong
    if (isFull(*Q) != 1) {
      (*Q).last = (*Q).last + 1;
      strcpy((*Q).data[(*Q).last].nim, nim);
      strcpy((*Q).data[(*Q).last].nama, nama);
      (*Q).data[(*Q).last].nilai = nilai;
    } else {
      printf("queue penuh\n");
    }
  }
}

void del (queue *Q) {
  if ((*Q).last == 0) {
    (*Q).first = -1;
    (*Q).last = -1;
  } else {
    // menggeser elemen ke depan
    int i;
    for (i=((*Q).first + 1); i<=(*Q).last; i++) {
      strcpy((*Q).data[i-1].nim, (*Q).data[i].nim);
      strcpy((*Q).data[i-1].nama, (*Q).data[i].nama);
      (*Q).data[i-1].nilai = (*Q).data[i].nilai;
      (*Q).last = (*Q).last - 1;
    }
  }
}

void printQueue (queue Q) {
  if (Q.first != -1) {
    printf("----- isi queue -----\n");
    int i;
    for (i=Q.last; i>=Q.first; i--) {
      printf("====================\n");
      printf("elemen ke: %d\n", i);
      printf("nim: %s\n", Q.data[i].nim);
      printf("nama: %s\n", Q.data[i].nama);
      printf("nilai: %f\n", Q.data[i].nilai);
    }
    printf("====================\n");
  } else {
    // proses jika queue kosong
    printf("queue kosong\n");
  }
}

int main () {
  queue Q;

  createEmpty(&Q);
  printQueue(Q);

  printf("========================\n");
  add("13507701", "Nana", 64.75, &Q);
  add("13507702", "Rudi", 75.11, &Q);
  add("13507703", "Dea", 84.63, &Q);
  printQueue(Q);

  printf("========================\n");
  del(&Q);
  del(&Q);
  printQueue(Q);

  printf("========================\n");

  return 0;
}
