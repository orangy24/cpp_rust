#include <stdlib.h>
#include <string.h>

typedef struct NodeHandle {
  int count;
} NodeHandle;

NodeHandle* node_new(void) {
  NodeHandle* n = calloc(1, sizeof(NodeHandle));
  return n;
}

void node_free(NodeHandle* n) { free(n); }

void node_publish(NodeHandle* n, const char* bytes) {
  (void)bytes;
  if (n) n->count++;
}

int node_count(const NodeHandle* n) { return n ? n->count : 0; }
