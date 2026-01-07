#ifndef SRC_EQUATION_H_
#define SRC_EQUATION_H_

#include "mesh.h"

/** @brief Struct that holds all needed data for a single fem solution. */
typedef struct {
  int nn;      /** Number of nodes in the mesh. */
  double* t;   /** Nodes temperatures. */
  double** hg; /** Global H matrix. */
  double* pg;  /** Global P matrix. */
  double** c;  /** C matrix */
} Equation;

/** @brief Allocates memory for Equation struct and initializes everything to 0.
 *
 * @note In this function nn is being correctly initialized to a value pulled from GlobalData */
void InitEquation(const GlobalData* glob_data, Equation* equation);

/** @brief Aggregates local P vectors to a single global P vector. */
void AggregatePVector(const GlobalData* glob_data, const Grid* grid, Equation* equation);

/** @brief Aggregates local H matrices to a single global H matrix. */
void AggregateHMatrix(const GlobalData* glob_data, const Grid* grid, Equation* equation);

/** @brief Aggregates local C matrices to a single global C matrix. */
void AggregateCMatrix(const GlobalData* glob_data, const Grid* grid, Equation* equation);

/** @brief Performs Gauss elimination on a given equation. */
int GaussElimination(int n, double** a, double* b, double* x);

/** @brief Solves steady state for a given Equation (fem problem). */
void SolveSteadyState(const GlobalData* glob_data, Equation* equation);

/** @brief Solves non stationary fem problem. */
void SolveNonStationary(const GlobalData* glob_data, Equation* equation);

/** @brief Frees previously allocated memory from Equation struct. */
void EquationCleanup(Equation* equation);

#endif
