#ifndef SRC_CONSTANTS_H_
#define SRC_CONSTANTS_H_

/** @brief Array that holds values of points in N-point integration scheme. */
extern double kPointsN1[];
/** @brief Array that holds values of points in N-point integration scheme. */
extern double kPointsN2[];
/** @brief Array that holds values of points in N-point integration scheme. */
extern double kPointsN3[];
/** @brief Array that holds values of points in N-point integration scheme. */
extern double kPointsN4[];

/** @brief Array that holds weights of points in N-point integration scheme. */
extern double kWeightsN1[];
/** @brief Array that holds weights of points in N-point integration scheme. */
extern double kWeightsN2[];
/** @brief Array that holds weights of points in N-point integration scheme. */
extern double kWeightsN3[];
/** @brief Array that holds weights of points in N-point integration scheme. */
extern double kWeightsN4[];

/**@brief Struct that represents a single point in 2D space.*/
typedef struct {
  double x, y;
} Point;

/** @brief Calculates values of integration points and their weights in various configurations.
 *  These values are global and used in Gauss integration process.
 *
 *  @note This function only needs to be run once in the beginning of the program. I implemented
 *  it this way because there are no natively supported compile time calculations in C.
 * */
void InitConstants();

/**@brief Returns pointer to an array that holds values
 * of points in n-point integragration scheme.
 *
 * @param n Amount of points in integration scheme.
 */
double* GetPoints(int n);

/**@brief Returns pointer to an array that holds weights
 * of points in n-point integragration scheme.
 *
 * @param n Amount of points in integration scheme.
 */
double* GetWeights(int n);

#endif  // SRC_CONSTANTS_H_
