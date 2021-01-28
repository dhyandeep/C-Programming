#include<fftw3.h>
#include<stdlib.h>
#include "FFTConv.h"
void Convolve( double * data, double * kernel, double * convout, int size )
{
    int a, b;
    for( a = 0; a < size*2; a++ )
    {
        double cvo = 0;
        for( b = 0; b < size; b++ )
        {
            if( a-b<0 ) continue;
            cvo += data[b] * kernel[a-b];
        }
        convout[a] = cvo;
    }
}

//Convout's array size must be 2*size.
void FFTConvolve( double * data, double * kernel, double * convout, int size )
{
    //struct timeval tvs, tve;
    int i;

    //Pad the 2nd half of the data with 0's.
    size *= 2;

    fftw_complex in_sequence[size], freq_sequence[size];
    fftw_complex in_data[size], freq_data[size];
    fftw_complex rev_data[size], time_data[size];
    fftw_plan p1 = fftw_plan_dft_1d(size, in_sequence, freq_sequence, FFTW_FORWARD, FFTW_ESTIMATE);
    fftw_plan p2 = fftw_plan_dft_1d(size, in_data, freq_data,         FFTW_FORWARD, FFTW_ESTIMATE);
    fftw_plan rev = fftw_plan_dft_1d(size, rev_data, time_data,       FFTW_BACKWARD, FFTW_ESTIMATE);

    for( i = 0; i < size/2; i++ )
    {
        in_sequence[i][0] = kernel[i];
        in_sequence[i][1] = 0;

        in_data[i][0] = data[i];
        in_data[i][1] = 0;
    }
    for( ; i < size; i++ )
    {
        in_sequence[i][0] = in_sequence[i][1] = 0;
        in_data[i][0] = in_data[i][1] = 0;
    }

    fftw_execute(p1);
    fftw_execute(p2);

    double mux = 1.0/size;

    for( i = 0; i < size; i++ )
    {
        double realD = freq_data[i][0];
        double imagD = freq_data[i][1];
        double realS = freq_sequence[i][0];
        double imagS = freq_sequence[i][1];
        rev_data[i][0] = (realD * realS - imagD * imagS)*mux;
        rev_data[i][1] = (realD * imagS + imagD * realS)*mux;
    }

    fftw_execute(rev);

    for( i = 0; i < size; i++ )
    {
        convout[i] = time_data[i][0]; // The i term should be non-existent.
    }
}
