#include "constants.h"
#include "equation.h"
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

#ifdef DEBUG
  ExportJacobianData(&grid, &uni_vals);
#endif

  CalcHbcMatrix(&grid, &uni_vals, &data);

#ifdef DEBUG
  ExportHbcMatrices(&grid);
#endif

  CalcPVector(&grid, &uni_vals, &data);

  Equation eq;
  InitEquation(&data, &eq);

  AggregatePVector(&data, &grid, &eq);
  AggregateHMatrix(&data, &grid, &eq);

#ifdef DEBUG
  ExportGlobalP(&eq);
  ExportGlobalH(&eq);
#endif

  SolveEquation(&data, &eq);

  EquationCleanup(&eq);
  GridCleanup(&grid);

  return 0;
}
