#include <stdlib.h>

#include "h_matrix.h"
#include "mesh.h"

void InitHMatrix(GlobHMatrix* h_matrix, GlobalData* data) {
  h_matrix->n = data->n_nodes;
  h_matrix->mat = (double**)malloc(h_matrix->n * sizeof(double*));
  for (int i = 0; i < h_matrix->n; ++i) {
    h_matrix->mat[i] = (double*)calloc(h_matrix->n, sizeof(double));
  }
}

void CalcGlobalHMatrix(GlobHMatrix* h_matrix, Grid* grid) {
  for (int element = 0; element < grid->n_elements; ++element) {
    Element* e = &grid->elements[element];
    for (int i = 0; i < 4; ++i) {
      int mat_i = e->nodes[i] - 1;
      for (int j = 0; j < 4; ++j) {
        int mat_j = e->nodes[j] - 1;
        h_matrix->mat[mat_i][mat_j] += e->h_matrix[i][j];
      }
    }
  }
}

void HMatrixCleanup(GlobHMatrix* h_matrix) {
  for (int i = 0; i < h_matrix->n; ++i) {
    free(h_matrix->mat[i]);
  }
  free(h_matrix->mat);
}
