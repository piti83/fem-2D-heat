#include "mesh.h"

#include <stdlib.h>

void GridCleanup(Grid* grid) {
  free(grid->elements);
  free(grid->nodes);
}
