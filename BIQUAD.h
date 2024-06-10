class BiquadFilter
{
private:

protected:
  long double _n[3];          // Numerator
  long double _d[3];          // Denominator

  float _in[2];               // Next input values 
  long double _out[2];        // Previous output values
  
public:
  BiquadFilter();
  virtual ~BiquadFilter() = 0;

};

