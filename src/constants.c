#include "constants.h"

#include <math.h>

double kPointsN1[1];
double kPointsN2[2];
double kPointsN3[3];
double kPointsN4[4];

double kWeightsN1[1];
double kWeightsN2[2];
double kWeightsN3[3];
double kWeightsN4[4];

Point kPointsN2D2[4];

void InitConstants() {
    kPointsN1[0] = 0.0;

    kPointsN2[0] = -sqrt(1.0 / 3.0);
    kPointsN2[1] = sqrt(1.0 / 3.0);

    kPointsN3[0] = -sqrt(3.0 / 5.0);
    kPointsN3[1] = 0;
    kPointsN3[2] = sqrt(3.0 / 5.0);

    kPointsN4[0] = -sqrt(3.0 / 7.0 + (2.0 / 7.0) * sqrt(6.0 / 5.0));
    kPointsN4[1] = -sqrt(3.0 / 7.0 - (2.0 / 7.0) * sqrt(6.0 / 5.0));
    kPointsN4[2] = sqrt(3.0 / 7.0 - (2.0 / 7.0) * sqrt(6.0 / 5.0));
    kPointsN4[3] = sqrt(3.0 / 7.0 + (2.0 / 7.0) * sqrt(6.0 / 5.0));

    kWeightsN1[0] = 2;

    kWeightsN2[0] = 1.0;
    kWeightsN2[1] = 1.0;

    kWeightsN3[0] =  5.0 / 9.0;
    kWeightsN3[1] =  8.0 / 9.0;
    kWeightsN3[2] =  5.0 / 9.0;

    kWeightsN4[0] = (18.0 - sqrt(30.0)) / (36.0);
    kWeightsN4[1] = (18.0 + sqrt(30.0)) / (36.0);
    kWeightsN4[2] = (18.0 + sqrt(30.0)) / (36.0);
    kWeightsN4[3] = (18.0 - sqrt(30.0)) / (36.0);

    kPointsN2D2[0] = (Point){-sqrt(1.0 / 3.0), -sqrt(1.0 / 3.0)};
    kPointsN2D2[1] = (Point){sqrt(1.0 / 3.0), -sqrt(1.0 / 3.0)};
    kPointsN2D2[2] = (Point){sqrt(1.0 / 3.0), sqrt(1.0 / 3.0)};
    kPointsN2D2[3] = (Point){-sqrt(1.0 / 3.0), sqrt(1.0 / 3.0)};
}
