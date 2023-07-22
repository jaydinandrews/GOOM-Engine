#ifndef SETTINGS_H
#define SETTINGS_H

#include "../../../../data/settings.h"

#ifndef RAYCAST_MAX_HITS
  #define RAYCAST_MAX_HITS 10
#endif

#ifndef RAYCAST_MAX_STEPS
  #define RAYCAST_MAX_STEPS 30
#endif

#ifndef RAYCAST_VISIBILITY_MAX_HITS
  #define RAYCAST_VISIBILITY_MAX_HITS 6
#endif

#ifndef RAYCAST_VISIBILITY_MAX_STEPS
  #define RAYCAST_VISIBILITY_MAX_STEPS 15
#endif

#ifndef TARGET_FPS
  #define TARGET_FPS 60
#endif

#endif /* SETTINGS_H */