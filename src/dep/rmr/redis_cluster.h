#ifndef __RMR_REDIS_CLUSTER_H__
#define __RMR_REDIS_CLUSTER_H__

#include "cluster.h"

// forward declaration
struct RedisModuleCtx;
MRClusterTopology *RedisCluster_GetTopology(struct RedisModuleCtx *);

int InitRedisTopologyUpdater(MREndpoint *currentEndpoint);

#endif