#include "binary_search_tree.h"
#include <stdio.h>
#include <stdlib.h>

void insert(node_t **node, int value) {
  if (*node == NULL) {
    *node = malloc(sizeof(node_t));

    if (*node == NULL) {
      fprintf(stderr, "Error: Cannot allocate memory\n");
      return;
    }

    (*node)->data = value;
    (*node)->left = NULL;
    (*node)->right = NULL;

    return;
  }

  if (value <= (*node)->data) {
    insert(&(*node)->left, value);
  } else if (value > (*node)->data) {
    insert(&(*node)->right, value);
  }
}

void collect(node_t *node, int *array, int *index) {
  if (node == NULL) {
    return;
  }

  collect(node->left, array, index);
  array[*index] = node->data;
  (*index)++;
  collect(node->right, array, index);
}

void count_nodes(node_t *node, int *count) {
  if (node == NULL) {
    return;
  }

  (*count)++;

  count_nodes(node->left, count);
  count_nodes(node->right, count);
}

node_t *build_tree(int *tree_data, size_t tree_data_len) {
  node_t *root = NULL;

  for (size_t i = 0; i < tree_data_len; i++) {
    insert(&root, tree_data[i]);
  }

  return root;
}

void free_tree(node_t *tree) {
  if (tree == NULL) {
    return;
  }

  free_tree(tree->left);
  free_tree(tree->right);
  free(tree);
}

int *sorted_data(node_t *tree) {
  int *sorted_data_array = NULL;
  int index = 0;
  int count = 0;

  count_nodes(tree, &count);

  sorted_data_array = malloc(count * sizeof(int));
  collect(tree, sorted_data_array, &index);

  return sorted_data_array;
}
