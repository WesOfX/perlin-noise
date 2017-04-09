# perlin-noise
A c++ implementation of Ken Perlin's improved noise algorithm. The algorithm returns pseudo-random floating-point numbers between -1 and 1. Small changes in any of the 3 input values yield small changes in the return value.

The `noise` method returns a `real` value from three `real` input values. `real` is a templated type which can be any floating-point type.

`real` is a template type. `static_assert`'s are used to ensure real is a floating point type.

*Minimal examples:*
```cpp
#include <iostream>
#include "noise.hpp"

int main(){
	// Unused parameters are 0.0 by default.
	std::cout << perlin::noise(0.6) << std::endl;
	std::cout << perlin::noise(0.6, 0.4) << std::endl;
	std::cout << perlin::noise(0.6, 0.4, 0.7) << std::endl;
}
```
