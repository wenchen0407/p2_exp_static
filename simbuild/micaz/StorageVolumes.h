#ifndef STORAGE_VOLUMES_H
#define STORAGE_VOLUMES_H

enum {
  VOLUME_LOGTEST, 
};

#endif
#if defined(VS)
VS(VOLUME_LOGTEST, 1024)
#undef VS
#endif
#if defined(VB)
VB(VOLUME_LOGTEST, 0)
#undef VB
#endif
