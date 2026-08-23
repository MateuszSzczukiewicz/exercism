#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H
#include <stddef.h>

typedef struct node node_t;

struct node {
  node_t *right;
  node_t *left;
  int data;
};

void insert(node_t **node, int value);
void collect(node_t *node, int *array, int *index);
void count_nodes(node_t *node, int *count);
node_t *build_tree(int *tree_data, size_t tree_data_len);
void free_tree(node_t *tree);
int *sorted_data(node_t *tree);

#endif
