#ifndef SRC_H_MATRIX_H_
#define SRC_H_MATRIX_H_

#include "mesh.h"


typedef struct {
  int n;
  double** mat;
} GlobHMatrix;

void InitHMatrix(GlobHMatrix* h_matrix, GlobalData* data);

void CalcGlobalHMatrix(GlobHMatrix* h_matrix, Grid* grid);

void HMatrixCleanup(GlobHMatrix* h_matrix);

#endif // SRC_H_MATRIX_H_
