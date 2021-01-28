________________________________________________________________________________________________________
Convolution using 1D FFT with overlap and add method Implementation
________________________________________________________________________________________________________
Convolution is a versatile technique used in signals and image processing. One major use is to
increase the speed of operations on signals.
As our inputs are 1D signals and the operation we want to perform is identical to convoluting it
with 9 sized kernel array, we propose to use an fft based algorithm for this purpose.
Normal iterative or brute-force implementation of Convolution requires 9*N multiplications and
corresponding additions, which seems very time consuming.
We can reduce the number of multiplications and additions, using the concepts of Fourier
transforms in signal processing.
Several operations in the time domain can be simplified by converting it to frequency domain
using fourier transforms and performing equivalent operation in fourier transform and finding the
inverse fourier transform of result.

Convolution in time domain is nothing but multiplication in frequency domain.
Read it here
https://dspillustrations.com/pages/posts/misc/the-convolution-theorem-and-application-example
s.html
Hence, for finding convolution for a window of 9 size, we don't need to perform convolution for
each of the 9 elements. Instead we can directly calculate the FFT of the signal and kernel, and
multiply the fourier transforms and then get the inverse fourier transform.
This has reduced 9 multiplications into a single fft calculation of signal window and kernel.

For finding Fourier transforms, we need some mathematical library that has FFT Implementation.
mathematical libraries for c++ like intel’s MKL (math kernel library) includes FFT operation, but
what i am using is FFTW library which is light weight and pinpoints our requirement.
One major issue with fft convolution is it adds up some distortions in starting and ending parts of
the signal. This is avoided using the overlap and add method described in the following link
https://www.dspguide.com/ch18/2.html
________________________________________________________________________________________________________
System requirements
________________________________________________________________________________________________________
Gcc - g++ version 6 or above
Fftw3 library (use sudo apt-get install fftw3 command for installing)
________________________________________________________________________________________________________
INPUT
________________________________________________________________________________________________________
Input file: incsv.txt in source directory.
Suppose we have m lines.
Input format:
<Number of Lines>
<Number of columns in line1>,<elt 1>,<elt 2>,...,<elt u>
<Number of columns in line2>,<elt 1>,<elt 2>,...,<elt v>
.
.
<Number of columns in line m>,<elt 1>,<elt 2>,...,<elt w>
________________________________________________________________________________________________________
OUTPUT
________________________________________________________________________________________________________

Output file
File: Out.txt in source directory
Output format:
<elt 1><elt 2>.........<elt u>
<elt 1><elt 2>.........<elt v>
<elt 1><elt 2>.........<elt w>
________________________________________________________________________________________________________
Building the code and executing
________________________________________________________________________________________________________
Use the following commands to execute the binary
make clean => cleans the source directory and deletes the binaries and system resources
allocated
Make => builds the executable ‘out’ in source directory
./out => Execute the binary ‘out’
________________________________________________________________________________________________________
