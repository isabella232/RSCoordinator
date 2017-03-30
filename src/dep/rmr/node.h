#ifndef __MR_NODE_H__
#define __MR_NODE_H__
#include "endpoint.h"
#include "dep/triemap/triemap.h"

typedef enum { MRNode_Master = 0x1, MRNode_Self = 0x2, MRNode_Coordinator = 0x4 } MRNodeFlags;

typedef struct {
  MREndpoint endpoint;
  const char *id;
  MRNodeFlags flags;
} MRClusterNode;

/* Free an MRendpoint object */
void MRNode_Free(MRClusterNode *n);

typedef struct MRNodeMap {
  TrieMap *nodes;
  TrieMap *hosts;
} MRNodeMap;

typedef struct MRNodeMapIterator {
  TrieMapIterator *iter;
  MRNodeMap *m;
  MRClusterNode *(*Next)(struct MRNodeMapIterator *it);
} MRNodeMapIterator;

MRNodeMapIterator MRNodeMap_IterateAll(MRNodeMap *m);
MRNodeMapIterator MRNodeMap_IterateRandomNodePerhost(MRNodeMap *m);
void MRNodeMapIterator_Free(MRNodeMapIterator *it);

MRNodeMap *MR_NewNodeMap();
void MRNodeMap_Free(MRNodeMap *m);
void MRNodeMap_Add(MRNodeMap *m, MRClusterNode *n);
MRClusterNode *MRNodeMap_RandomNode(MRNodeMap *m);
size_t MRNodeMap_NumHosts(MRNodeMap *m);
size_t MRNodeMap_NumNodes(MRNodeMap *m);
#endif