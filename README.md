# perlin-noise
A c++ implementation of Ken Perlin's improved noise algorithm. The algorithm returns pseudo-random floating-point numbers between -1 and 1. Small changes in any of the 3 input values yield small changes in the return value.

The `noise` method returns a `result_type` value from three `result_type` input values. `result_type` is a templated type which can be any floating-point type. *Minimal code example below.*

```cpp
#include <iostream>
#include "noise.hpp"

int main(){
	// Unused parameters are 0.0 by default. Output should be -0.08256, -0.13692
	std::cout << perlin::noise(0.6) << ", " << perlin::noise(0.7) << std::endl;
}
```
