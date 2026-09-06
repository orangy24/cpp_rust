#include "kata.hpp"

struct NodeHandle {
  int count = 0;
};

NodeHandle* node_new(void) { return nullptr; }

void node_free(NodeHandle* n) { (void)n; }

void node_publish(NodeHandle* n, const char* bytes) {
  (void)n;
  (void)bytes;
}

int node_count(NodeHandle const* n) {
  (void)n;
  return 0;
}
