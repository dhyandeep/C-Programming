#include<fftw3.h>

void Convolve( double * data, double * kernel, double * convout, int size );
void FFTConvolve( double * data, double * kernel, double * convout, int size );
