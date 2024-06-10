#include "BIQUAD.h"


BiquadFilter::BiquadFilter()
{
	_in[0] = 0;
	_in[1] = 0;

	_out[0] = 0;
	_out[1] = 0;
}


BiquadFilter::~BiquadFilter()
{}