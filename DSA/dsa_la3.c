/*#include <stdio.h>
#include <stdlib.h>
#define MAX_KEYS 3

typedef struct Node {
  int numk;
  int keys[MAX_KEYS];
  struct Node *children[MAX_KEYS + 1];
  int is_leaf;
} Node;

Node *create_node() {
  Node *new_node = (Node *)malloc(sizeof(Node));
  new_node->numk = 0;
  new_node->is_leaf = 1;
  for (int i = 0; i < MAX_KEYS + 1; i++)
    new_node->children[i] = NULL;
  return new_node;
}

void ino_trav(Node *root) {
  if (root) {
    for (int i = 0; i < root->numk; i++) {
      ino_trav(root->children[i]);
      printf("%d ", root->keys[i]);
    }
    ino_trav(root->children[root->numk]);
  }
}

void posto_trav(Node *root) {
  if (root) {
    for (int i = 0; i < root->numk; i++)
      posto_trav(root->children[i]);
    posto_trav(root->children[root->numk]);
    for (int i = 0; i < root->numk; i++)
      printf("%d ", root->keys[i]);
  }
}

void preo_trav(Node *root) {
  if (root) {
    for (int i = 0; i < root->numk; i++)
      printf("%d ", root->keys[i]);
    for (int i = 0; i < root->numk + 1; i++)
      preo_trav(root->children[i]);
  }
}

Node *split_child(Node *parent, int index) {
  Node *new_child = create_node();
  Node *old_child = parent->children[index];

  new_child->is_leaf = old_child->is_leaf;
  new_child->numk = MAX_KEYS / 2;

  for (int i = 0; i < MAX_KEYS / 2; i++) {
    new_child->keys[i] = old_child->keys[i + MAX_KEYS / 2];
    old_child->keys[i + MAX_KEYS / 2] = 0;
  }

  if (!old_child->is_leaf) {
    for (int i = 0; i <= MAX_KEYS / 2; i++) {
      new_child->children[i] = old_child->children[i + MAX_KEYS / 2];
      old_child->children[i + MAX_KEYS / 2] = NULL;
    }
  }

  for (int i = parent->numk; i > index; i--)
    parent->children[i + 1] = parent->children[i];
  parent->children[index + 1] = new_child;

  for (int i = parent->numk - 1; i >= index; i--)
    parent->keys[i + 1] = parent->keys[i];

  parent->keys[index] = old_child->keys[MAX_KEYS / 2 - 1];
  old_child->numk = MAX_KEYS / 2 - 1;
  parent->numk++;

  return parent;
}

Node *insert_non_full(Node *root, int key) {
  int i = root->numk - 1;

  if (root->is_leaf) {
    while (i >= 0 && key < root->keys[i]) {
      root->keys[i + 1] = root->keys[i];
      i--;
    }

    root->keys[i + 1] = key;
    root->numk++;
  } else {
    while (i >= 0 && key < root->keys[i])
      i--;

    if (root->children[i + 1]->numk == MAX_KEYS) {
      root = split_child(root, i + 1);
      if (key > root->keys[i + 1])
        i++;
    }

    root->children[i + 1] = insert_non_full(root->children[i + 1], key);
  }

  return root;
}

Node *insert(Node *root, int key) {
  if (root->numk == MAX_KEYS) {
    Node *new_root = create_node();
    new_root->is_leaf = 0;
    new_root->children[0] = root;
    new_root = split_child(new_root, 0);
    root = insert_non_full(new_root, key);
  } else {
    root = insert_non_full(root, key);
  }

  return root;
}

Node *search(Node *root, int key) {
  int i = 0;
  while (i < root->numk && key > root->keys[i])
    i++;

  if (i < root->numk && key == root->keys[i])
    return root;

  if (root->is_leaf)
    return NULL;

  return search(root->children[i], key);
}

int find_key_index(Node* node, int key) {
    int index = 0;
    while (index < node->numk && key > node->keys[index])
        index++;
    return index;
}

Node* remove_key(Node* root, int key) {
    if (!root)
        return NULL;

    int index = find_key_index(root, key);

    if (index < root->numk && root->keys[index] == key) {
        for (int i = index; i < root->numk - 1; i++)
            root->keys[i] = root->keys[i + 1];
        root->numk--;
        return root;
    }

    if (root->is_leaf)
        return root;

    root->children[index] = remove_key(root->children[index], key);

    return root;
}

void freetr(Node *root) {
  if (root) {
    for (int i = 0; i < root->numk + 1; i++)
      freetr(root->children[i]);
    free(root);
  }
}

int main() {
  Node *root = create_node();

  int keys[] = {10, 5, 6, 30};
  int numk = sizeof(keys) / sizeof(keys[0]);

  for (int i = 0; i < numk; i++)
    root = insert(root, keys[i]);

  printf("Inorder traversal:\n");
  ino_trav(root);
  printf("\n");
  printf("Preorder traversal:\n");
  preo_trav(root);
  printf("\n");
  printf("Postorder traversal:\n");
  posto_trav(root);
  printf("\n");

  printf("Searching for 6 : ");
  printf("\n");
  int index = find_key_index(root, 6);
  printf("The index is %d ", index);
  printf("\n");

  int rkey = 30;
  root = remove_key(root, rkey);
  printf("tree after deletion of key %d:\n", rkey);
  ino_trav(root);
  printf("\n");
  preo_trav(root);
  printf("\n");
  posto_trav(root);
  printf("\n");

  freetr(root);

  return 0;
}*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_KEYS 3
#define MIN_KEYS 2

typedef struct Node {
    int keys[MAX_KEYS];
    struct Node* children[MAX_KEYS + 1];
    int num_keys;
    struct Node* next;  
    
} Node;

Node* createNode(int key);

Node* insert(Node* root, int key);

Node* search(Node* root, int key);

Node* deleteKey(Node* root, int key);

Node* splitNode(Node* parent, int index);

void inorderTraversal(Node* root);

void preorderTraversal(Node* root);

void postorderTraversal(Node* root);

int main() {
    Node* root = NULL;

    int keys_to_insert[] = {10, 20, 5, 6, 12, 30, 7, 17};
    int num_keys = sizeof(keys_to_insert) / sizeof(keys_to_insert[0]);

    for (int i = 0; i < num_keys; i++) {
        root = insert(root, keys_to_insert[i]);
    }

    printf("Inorder Traversal: ");
    inorderTraversal(root);
    printf("\n");

    printf("Preorder Traversal: ");
    preorderTraversal(root);
    printf("\n");

    printf("Postorder Traversal: ");
    postorderTraversal(root);
    printf("\n");

    printf("Search 30: ");
    Node* result30 = search(root, 30);
    if (result30) {
        printf("Found\n");
    } else {
        printf("Not Found\n");
    }


    printf("After Deletion");
    printf("\n");
    root = deleteKey(root, 7);
    inorderTraversal(root);
    printf("\n");

    return 0;
}

Node* createNode(int key) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->keys[0] = key;
    newNode->num_keys = 1;
    for (int i = 0; i <= MAX_KEYS; i++) {
        newNode->children[i] = NULL;
    }
    newNode->next = NULL;
    return newNode;
}

Node* insert(Node* root, int key) {
    if (root == NULL) {
        return createNode(key);
    }

    for (int i = 0; i < root->num_keys; i++) {
        if (key == root->keys[i]) {
            return root;
        }
    }

    if (root->num_keys < MAX_KEYS) {
        int i = root->num_keys - 1;
        while (i >= 0 && key < root->keys[i]) {
            root->keys[i + 1] = root->keys[i];
            i--;
        }
        root->keys[i + 1] = key;
        root->num_keys++;
    } else {
        int i = 0;
        while (i < root->num_keys && key > root->keys[i]) {
            i++;
        }
        root->children[i] = insert(root->children[i], key);

        if (root->children[i]->num_keys > MAX_KEYS) {
            root = splitNode(root, i);
        }
    }

    return root;
}

Node* search(Node* root, int key) {
    if (!root) {
        return NULL;
    }

    int i = 0;
    while (i < root->num_keys && key > root->keys[i]) {
        i++;
    }

    if (i < root->num_keys && key == root->keys[i]) {
        return root;
    } else if (root == NULL) {
        return NULL;
    } else {
        return search(root->children[i], key);
    }
}

Node* deleteKey(Node* root, int key) {
    if (!root) {
        return NULL;
    }

    int i = 0;
    while (i < root->num_keys && key > root->keys[i]) {
        i++;
    }

    if (i < root->num_keys && key == root->keys[i]) {
        for (int j = i; j < root->num_keys - 1; j++) {
            root->keys[j] = root->keys[j + 1];
        }
        root->num_keys--;

        return root;
    } else if (root->next == NULL) {
        return root;
    } else {
        root->children[i] = deleteKey(root->children[i], key);
        return root;
    }
}

Node* splitNode(Node* parent, int index) {
    Node* child = parent->children[index];
    Node* newNode = createNode(child->keys[MIN_KEYS]);

    for (int i = MIN_KEYS + 1; i < MAX_KEYS; i++) {
        newNode->keys[i - MIN_KEYS - 1] = child->keys[i];
    }
    newNode->num_keys = MAX_KEYS - MIN_KEYS - 1;
    child->num_keys = MIN_KEYS;

    for (int i = MAX_KEYS; i >= index + 1; i--) {
        parent->children[i + 1] = parent->children[i];
    }
    parent->children[index + 1] = newNode;

    for (int i = MAX_KEYS - 1; i >= index; i--) {
        parent->keys[i + 1] = parent->keys[i];
    }
    parent->keys[index] = child->keys[MIN_KEYS];
    parent->num_keys++;

    return parent;
}

void inorderTraversal(Node* root) {
    if (root) {
        for (int i = 0; i < root->num_keys; i++) {
            inorderTraversal(root->children[i]);
            printf("%d ", root->keys[i]);
        }
        inorderTraversal(root->children[root->num_keys]);
    }
}

void preorderTraversal(Node* root) {
    if (root) {
        for (int i = 0; i < root->num_keys; i++) {
            printf("%d ", root->keys[i]);
            preorderTraversal(root->children[i]);
        }
        preorderTraversal(root->children[root->num_keys]);
    }
}

void postorderTraversal(Node* root) {
    if (root) {
        for (int i = 0; i < root->num_keys; i++) {
            postorderTraversal(root->children[i]);
        }
        postorderTraversal(root->children[root->num_keys]);
        for (int i = 0; i < root->num_keys; i++) {
            printf("%d ", root->keys[i]);
        }
    }
}