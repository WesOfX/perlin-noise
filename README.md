# perlin-noise
A c++ implementation of Ken Perlin's improved noise algorithm. The algorithm returns pseudo-random floating-point numbers between -1 and 1. Small changes in any of the 3 input values yield small changes in the return value.

The `noise` method returns a `real` value from three `real` input values. `real` is a templated type which can be any floating-point type.

`real` is a typedef of `float` but it can be changed to any floating-point arithmatic type. Alternatively, all the functions in `noise.hpp` could be templated to take any floating-point arithmatic type. For simplicity, I chose not to template them. Note there is no `static_assert` to ensure `real` is a floating-point type if you decide to change the type of `real`.

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
