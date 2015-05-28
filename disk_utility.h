#ifndef _DISK_UTILITY_H
#define _DISK_UTILITY_H

#include "structures.h"

void save_to_disk(struct Graph *g, char *filename);
void read_from_disk(char *filename, struct Graph *g);

#endif /* _DISK_UTILITY_H */
