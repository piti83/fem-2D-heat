#include "constants.h"
#include "integrals.h"
#include "io.h"
#include "mesh.h"

int main() {
  InitConstants();

  GlobalData data;
  Grid grid;

  ReadFile("run/test.txt", &data, &grid);
  PrintInfo(&data, &grid);

  UniversalVals uni_vals;
  CalcUniversalVals(&uni_vals);
  CalcJacobians(&grid, &uni_vals);
  CalcHMatrix(&grid, &data);

#ifndef DEBUG
  ExportJacobianData(&grid, &uni_vals);
#endif // DEBUG

  GridCleanup(&grid);

  return 0;
}
