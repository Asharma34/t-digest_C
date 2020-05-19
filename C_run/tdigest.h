#pragma once


#include <stdlib.h>

typedef struct td_histogram td_histogram_t;


td_histogram_t *td_new(double compression);


void td_free(td_histogram_t *h);


void td_add(td_histogram_t *h, double val, double count);


void td_merge(td_histogram_t *into, td_histogram_t *from);


void td_reset(td_histogram_t *h);


double td_value_at(td_histogram_t *h, double q);


//quantile of val in [0, 1]
double td_quantile_of(td_histogram_t *h, double val);


double td_trimmed_mean(td_histogram_t *h, double lo, double hi);


double td_total_count(td_histogram_t *h);


double td_total_sum(td_histogram_t *h);


void td_decay(td_histogram_t *h, double factor);
