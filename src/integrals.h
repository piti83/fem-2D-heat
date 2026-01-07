#ifndef SRC_INTEGRALS_C_
#define SRC_INTEGRALS_C_

#include <mesh.h>

/** @brief Quick 2D shape function calculation */
double N1(double ksi, double eta);
/** @brief Quick 2D shape function calculation */
double N2(double ksi, double eta);
/** @brief Quick 2D shape function calculation */
double N3(double ksi, double eta);
/** @brief Quick 2D shape function calculation */
double N4(double ksi, double eta);

/** @brief Gauss integration algorithm for 1D and 2-point scheme. */
double Gauss1D2P(double (*f)(double));
/** @brief Gauss integration algorithm for 1D and 3-point scheme. */
double Gauss1D3P(double (*f)(double));
/** @brief Gauss integration algorithm for 2D and 2-point scheme. */
double Gauss2D2P(double (*f)(double, double));
/** @brief Gauss integration algorithm for 2D and 3-point scheme. */
double Gauss2D3P(double (*f)(double, double));

/** @brief Calculates dN/dKsi and dN/dEta which are universal across solution. */
void CalcUniversalVals(UniversalVals* uni_vals, int nip);
/** @brief Calculates Jacobians (nip for every node in the mesh), which are stored inside Element
 * struct. */
void CalcJacobians(Grid* grid, UniversalVals* uni_vals, GlobalData* glob_data);
/**  Calculates local C matrix for every element. */
void CalcHMatrices(Grid* grid, GlobalData* glob_data);
/** Calculates local Hbc matrix for every element. */
void CalcHbcMatrices(Grid* grid, UniversalVals* uni_vals, GlobalData* glob_data);
/** Calculates local P vector for every element. */
void CalcPVectors(Grid* grid, UniversalVals* uni_vals, GlobalData* glob_data);
/** Calculates local C matrix for every element.  */
void CalcCMatrices(Grid* grid, UniversalVals* uni_vals, GlobalData* glob_data);

#endif  // SRC_INTEGRALS_C_
