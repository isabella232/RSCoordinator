#ifndef RSCOORDINATOR_VERSION_H_
#define RSCOORDINATOR_VERSION_H_
#include "dep/RediSearch/src/version.h"

#define RSCOORDINATOR_VERSION_MAJOR 3
#define RSCOORDINATOR_VERSION_MINOR 0
#define RSCOORDINATOR_VERSION_PATCH 11

// convert semver to incremental number as expected by redis
#define RSCOORDINATOR_VERSION                                                \
  (RSCOORDINATOR_VERSION_MAJOR * 10000 + RSCOORDINATOR_VERSION_MINOR * 100 + \
   RSCOORDINATOR_VERSION_PATCH)

#endif
