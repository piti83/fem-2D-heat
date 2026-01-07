#ifndef SRC_MESH_H_
#define SRC_MESH_H_

#include <constants.h>
#include <stdbool.h>

/** @brief Max number of integration points for 1D. */
#define MAX_NIP_1D 4

/** @brief Max number of integration points for 2D. */
#define MAX_NIP_2D (MAX_NIP_1D * MAX_NIP_1D)

/** @brief Node represents a specific point on the mesh. It contains x,y coordinates and a boolean
 * that specifies if the node is specified as a boundary condition. */
typedef struct {
  double x;
  double y;
  bool bc;
} Node;

/** @brief Jacobian represents Jacobi matrix and holds all the necessary data logically connected to
 * it. */
typedef struct {
  double j[2][2];
  double j1[2][2];
  double det_j;
  double dN_dx[4];
  double dN_dy[4];
  double weight;
} Jacobian;

/** @brief Surface structure is being used to hold derivatives calculated on the edges of mesh while
 * calculating H_bc matrices. */
typedef struct {
  double n[MAX_NIP_1D][4];
} Surface;

/** @brief Element consists of 4 nodes connected together forming a quad.
 *  @note Element holds ids of nodes, not nodes themselves. Whenever u use
 *  nodes of element, you should subtract 1 when accessing the node itself. */
typedef struct {
  unsigned int nodes[4];
  Jacobian jacobian[MAX_NIP_2D];
  double h_matrix[4][4];
  double hbc_matrix[4][4];
  Surface surface[4];
  double p_vector[4];
  double c_matrix[4][4];
} Element;

/** @brief Grid represents a complete 2D mesh. It nodes, elements and jacobians. */
typedef struct {
  unsigned int n_nodes;
  unsigned int n_elements;
  Node* nodes;
  Element* elements;
  int jacobians_calculated;
} Grid;

/** @brief Values that can be shared across solution and not recalculated for each node/element. */
typedef struct {
  double dn_dksi[MAX_NIP_2D][4];
  double dn_deta[MAX_NIP_2D][4];
} UniversalVals;

/** @brief Simulation parameters parsed from Abaqus mesh file. */
typedef struct {
  double sim_time;
  double sim_step_time;
  double conductivity;
  double alfa;
  double tot;
  double init_temp;
  double density;
  double spec_heat;
  int n_nodes;
  int n_elements;
  int nip_elem;
  int nip_bc;
} GlobalData;

/** @brief Frees allocated arrays and matrices that were alocated during initialisation process.
 * This function should be called once after all calculations and reading operations are finished.
 */
void GridCleanup(Grid* grid);

#endif  // SRC_MESH_H_
