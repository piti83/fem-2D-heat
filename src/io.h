#ifndef SRC_INPUT_H_
#define SRC_INPUT_H_

#include "mesh.h"

void ReadFile(const char* path, GlobalData* glob_data, Grid* grid);

void PrintInfo(const GlobalData* glob_data, const Grid* grid);

void ExportJacobianData(const Grid* grid, const UniversalVals* uni_vals);

#endif  // SRC_INPUT_H_
