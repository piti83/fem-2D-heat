#ifndef SRC_CONSTANTS_H_
#define SRC_CONSTANTS_H_

#define NIP 4

extern double kPointsN1[];
extern double kPointsN2[];
extern double kPointsN3[];
extern double kPointsN4[];

extern double kWeightsN1[];
extern double kWeightsN2[];
extern double kWeightsN3[];
extern double kWeightsN4[];

typedef struct {
  double x, y;
} Point;

void InitConstants();

double* GetPoints(int n);
double* GetWeights(int n);

#endif // SRC_CONSTANTS_H_
