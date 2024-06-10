#pragma once
#include "BIQUAD.h"

#include <stdint.h>


class RiaaFilter : public BiquadFilter
{
private:
	RiaaFilter();

public:
	RiaaFilter(int sampleRate, long double dcgain);
	~RiaaFilter();

	float apply(float sample);

};


