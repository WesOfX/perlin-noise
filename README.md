# perlin-noise
A c++ implementation of Ken Perlin's improved noise algorithm. The algorithm returns pseudo-random numbers, but small changes in the input values yield small changes in the output value.

The `noise` method returns a `result_type` value from three `result_type` input values: `x`, `y`, and `z`. `result_type` is a templated type which can be any floating-point type. *Minimal code example below.*

```cpp
#include <iostream>
#include "noise.hpp"

int main(){
	// Unused parameters are 0.0 by default. Output should be -0.08256, -0.13692
	std::cout << perlin::noise(0.6) << ", " << perlin::noise(0.7) << std::endl;
}
```
