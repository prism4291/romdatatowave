
#include "RIAA.h"

#include <cmath>

#include <stdint.h>
#include <stdlib.h>


RiaaFilter::RiaaFilter(int sampleRate, long double dcgain)
{
	long double z1 = exp(-1.0 / ((long double)(318e-6) * sampleRate));   // t1
	long double z2 = exp(-1.0 / ((long double)(3.18e-6) * sampleRate));  // t2
	long double p1 = exp(-1.0 / ((long double)(3180e-6) * sampleRate));  // t3
	long double p2 = exp(-1.0 / ((long double)(75e-6) * sampleRate));    // t4

	_n[0] = 1;
	_n[1] = -z1 - z2;
	_n[2] = z1 * z2;

	_d[0] = 1;
	_d[1] = -p1 - p2;
	_d[2] = p1 * p2;

	long double gain = (_n[0] + _n[1] + _n[2]) / (_d[0] + _d[1] + _d[2]);
	long double gainAttenuation = (dcgain / gain);

	for (int i = 0; i < 3; i++) {
		_n[i] *= gainAttenuation;
	}
}


RiaaFilter::~RiaaFilter()
{}


float RiaaFilter::apply(float sample)
{
	double out = 0;
	out += _n[0] * sample + _n[1] * _in[0] + _n[2] * _in[1];
	out -= _d[1] * _out[0] + _d[2] * _out[1];
	out /= _d[0];

	// Shift the delay line                                                       
	_in[1] = _in[0];
	_in[0] = sample;

	_out[1] = _out[0];
	_out[0] = out;

	return (float)out;
}