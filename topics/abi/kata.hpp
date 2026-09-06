#pragma once

#ifdef __cplusplus
extern "C" {
#endif

typedef struct NodeHandle NodeHandle;

NodeHandle* node_new(void);
void node_free(NodeHandle* n);
void node_publish(NodeHandle* n, const char* bytes);
int node_count(NodeHandle const* n);

#ifdef __cplusplus
}
#endif
