#ifndef RMR_PARTITION_H__
#define RMR_PARTITION_H__

#include <stdlib.h>

/* A partitioner takes command keys and tags them according to a ssharding function matching the
 * cluster's sharding function.
 * Using a partitioner we can paste sharding tags onto redis arguments to make sure they reach
 * specific shards in the cluster, thus reducing the number of shards in the cluster to well bellow
 * 16384 or 4096.
  */
typedef struct {
  size_t size;
  const char **table;
  size_t tableSize;
} PartitionCtx;

size_t PartitionForKey(PartitionCtx *ctx, const char *key, size_t len);

const char *PartitionTag(PartitionCtx *ctx, size_t partition);

void PartitionCtx_Init(PartitionCtx *ctx, size_t numPartitions, const char **table,
                       size_t tableSize);

void PartitionCtx_SetSlotTable(PartitionCtx *ctx, const char **table, size_t tableSize);

#endif