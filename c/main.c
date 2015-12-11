#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "parameters.h"
#include "estimates.h"
#include "experiment.h"

int main() {
    srand(time(NULL));

    size_t iterations = 100;

    double rho = 100.0;
    double epsilon = 1E-4;

    // double exp_quantiles[] = {1.96, 2.575, 3};

    size_t r = 180;
    size_t m = r * 2;

    /*
    double* alphas;
    double* relative_deviations;
    size_t deepness = 6;
    estimate_alpha(iterations, rho, epsilon, r, m, deepness,
                   &alphas, &relative_deviations);
    size_t i = 5 + 3 * deepness;
    while (--i > 0) {
        printf("alpha=%f, reldev=%f\n", alphas[i], relative_deviations[i]);
    }
    free(alphas);
    free(relative_deviations);
    */
    double realQ;
    double alpha;
    double* values;

    alpha = 0.725; // 2.86%
    r = 140;
    m = r*2;
    realQ = get_Q(r, rho);
    values = get_estimates(&iterations, rho, epsilon, r, m, alpha);
    printf("%u: Difference is %f%%: %.15Lf - %.15f\n", iterations,
            100*fabs((sum(values, iterations)/iterations-realQ)/realQ),
            sum(values, iterations)/iterations, realQ);
    free(values);

    /*
    alpha = 0.625; // 0.04%
    r = 160;
    m = r*2;
    realQ = get_Q(r, rho);
    values = get_estimates(&iterations, rho, epsilon, r, m, alpha);
    printf("%u: Difference is %f%%\n", iterations, 100*fabs((sum(values, iterations)/iterations-realQ)/realQ));
    free(values);

    alpha = 0.553125; // 14.86%
    r = 180;
    m = r*2;
    realQ = get_Q(r, rho);
    values = get_estimates(&iterations, rho, epsilon, r, m, alpha);
    printf("%u: Difference is %f%%\n", iterations, 100*fabs((sum(values, iterations)/iterations-realQ)/realQ));
    free(values);
    */

    return 0;
}

