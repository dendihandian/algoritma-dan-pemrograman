#include <stdio.h>
#include <malloc.h>

typedef struct smp *alamatsimpul;
typedef struct smp {
  char info;
  alamatsimpul right;
  alamatsimpul left;
} simpul;

typedef struct {
  simpul* root;
} tree;

void makeTree(char c, tree *T) {
  simpul *node;
  node = (simpul *) malloc (sizeof (simpul));
  node->info = c;
  node->right = NULL;
  node->left = NULL;
  (*T).root = node;
}

void addRight(char c, simpul **root) {
  if ((*root)->right == NULL) {
    // jika sub pohon kanan kosong
    simpul *node;
    node = (simpul *) malloc (sizeof (simpul));
    node->info = c;
    node->right = NULL;
    node->left = NULL;
    (*root)->right = node;
  } else {
    printf("sub pohon kanan telah terisi\n");
  }
}

void addLeft(char c, simpul **root) {
  if ((*root)->left == NULL) {
    // jika sub pohon kanan kosong
    simpul *node;
    node = (simpul *) malloc (sizeof (simpul));
    node->info = c;
    node->right = NULL;
    node->left = NULL;
    (*root)->left = node;
  } else {
    printf("sub pohon kiri telah terisi\n");
  }
}

void delRight(simpul **root) {
  simpul *node = (*root)->right;
  (*root)->right = NULL;
  free(node);
}

void delLeft(simpul **root) {
  simpul *node = (*root)->left;
  (*root)->left = NULL;
  free(node);
}

void printTreePreOrder (simpul *root) {
  if (root != NULL) {
    printf(" %c ", root->info);
    printTreePreOrder(root->left);
    printTreePreOrder(root->right);
  }
}

void printTreeInOrder (simpul *root) {
  if (root != NULL) {
    printTreeInOrder(root->left);
    printf(" %c ", root->info);
    printTreeInOrder(root->right);
  }
}

void printTreePostOrder (simpul *root) {
  if (root != NULL) {
    printTreePostOrder(root->left);
    printTreePostOrder(root->right);
    printf(" %c ", root->info);
  }
}

void printTreeLevelOrderNext (simpul *root) {
  if (root != NULL) {
    if (root->left != NULL) {
      printf(" %c ", root->left->info);
    }
    if (root->right != NULL) {
      printf(" %c ", root->right->info);
    }
    if (root->left != NULL) {
      printTreeLevelOrderNext(root->left);
    }
    if (root->right != NULL) {
      printTreeLevelOrderNext(root->right);
    }
  }
}

void printTreeLevelOrder (simpul *root) {
  if (root != NULL) {
    printf(" %c ", root->info);
    printTreeLevelOrderNext(root);
  }
}

void copyTree(simpul *root1, simpul **root2) {
  if (root1 != NULL) {
    (*root2) = (simpul *) malloc (sizeof (simpul));
    (*root2)->info = root1->info;
    if (root1->left != NULL) {
      copyTree(root1->left, &(*root2)->left);
    }
    if (root1->right != NULL) {
      copyTree(root1->right, &(*root2)->right);
    }
  }
}

int isEqual (simpul *root1, simpul *root2) {
  int hasil = 1;
  if ((root1 != NULL) && (root2 != NULL)) {
    if (root1->info != root2->info) {
      hasil = 0;
    } else {
      isEqual(root1->left, root2->left);
      isEqual(root1->right, root2->right);
    }
  } else {
    if ((root1 != NULL) ||(root2 != NULL)) {
      hasil = 0;
    }
  }
  return hasil;
}

int main () {
  tree T;

  makeTree('A', &T);
  addLeft('B', &T.root);
  addRight('C', &T.root);
  addLeft('D', &T.root->left);
  addRight('E', &T.root->left);
  addRight('F', &T.root->right);

  printf("========================\n");
  printf("preOrder\n");
  printTreePreOrder(T.root);
  printf("\n========================\n");
  printf("inOrder\n");
  printTreeInOrder(T.root);
  printf("\n========================\n");
  printf("postOrder\n");
  printTreePostOrder(T.root);
  printf("\n========================\n");
  printf("levelOrder\n");
  printTreeLevelOrder(T.root);
  printf("\n========================\n");

  tree T2;
  copyTree(T.root, &T2.root);

  if (isEqual(T.root, T2.root) == 1) {
    printf("pohon sama\n");
  } else {
    printf("pohon tidak sama\n");
  }

  delRight(&T.root->left);
  delLeft(&T.root->left);
  printf("========================\n");
  printf("preOrder setelah dihapus\n");
  printTreePreOrder(T.root);
  printf("\n========================\n");

  return 0;
}
