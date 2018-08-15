#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct {
  char nim[10];
  char nama[50];
  float nilai;
} nilaiMatKul;

typedef struct elmt *alamatelmt;
typedef struct elmt {
  nilaiMatKul elmt;
  alamatelmt next;
} elemen;

typedef struct {
  elemen* top;
} stack;

void createEmpty(stack *S) {
  (*S).top = NULL;
}

int isEmpty(stack S) {
  int hasil = 0;
  if (S.top == NULL) {
    hasil = 1;
  }

  return hasil;
}

int countElement(stack S) {
  int hasil = 0;
  if (S.top != NULL) {
    // stack tidak kosong
    elemen *elmt;

    // inisialisasi
    elmt = S.top;

    while (elmt != NULL) {
      // proses
      hasil = hasil + 1;

      // iterasi
      elmt = elmt->next;
    }
  }

  return hasil;
}

void push (char nim[], char nama[], float nilai, stack *S) {
  elemen *elmt;
  elmt = (elemen *) malloc (sizeof (elemen));
  strcpy(elmt->elmt.nim, nim);
  strcpy(elmt->elmt.nama, nama);
  elmt->elmt.nilai = nilai;
  elmt->next = (*S).top;
  (*S).top = elmt;
  elmt = NULL;
}

void pop (stack *S) {
  if ((*S).top != NULL) {
    // jika stack bukan stack kosong
    elemen *elmt = (*S).top;
    (*S).top = (*S).top->next;
    elmt->next = NULL;
    free(elmt);
  }
}

void printStack(stack S) {
  if (S.top != NULL) {
    printf("---- isi stack ----\n");
    elemen *elmt = S.top;
    int i = 1;
    while (elmt != NULL) {
      printf("==========\n");
      printf("elemen ke: %d\n", i);
      printf("nim: %s\n", elmt->elmt.nim);
      printf("nama: %s\n", elmt->elmt.nama);
      printf("nilai: %f\n", elmt->elmt.nilai);

      // iterasi
      elmt = elmt->next;
      i = i + 1;
    }
    printf("------------------\n");
  } else {
    // proses jika stack kosong
    printf("stack kosong\n");
  }
}

int main () {
  stack S;

  createEmpty(&S);
  printStack(S);

  printf("==========\n");
  push("13507701", "Nana", 64.75, &S);
  push("13507702", "Rudi", 75.11, &S);
  push("13507703", "Dea", 84.63, &S);
  printStack(S);

  printf("==========\n");
  pop(&S);
  pop(&S);
  printStack(S);
  printf("==========\n");

  return 0;
}
