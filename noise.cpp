#include "noise.hpp"

perlin::result_type perlin::noise(
	result_type x,
	decltype(x) y,
	decltype(x) z
){
	auto unit_x = (int)floor(x) & 255,
	     unit_y = (int)floor(y) & 255,
	     unit_z = (int)floor(z) & 255;
	x -= floor(x);
	y -= floor(y);
	z -= floor(z);
	auto u = fade(x),
	     v = fade(y),
	     w = fade(z);
	auto a = permutation[unit_x] + unit_y,
	     aa = permutation[a] + unit_z,
	     ab = permutation[a + 1] + unit_z,
	     b = permutation[unit_x + 1] + unit_y,
	     ba = permutation[b] + unit_z,
	     bb = permutation[b + 1] + unit_z;	
	return lerp(w,
		lerp(
			v,
			lerp(
				u,
				grad(permutation[aa], x, y, z),
				grad(permutation[ba], x - 1, y, z)
			),
			lerp(
				u,
				grad(permutation[ab], x, y - 1, z),
				grad(permutation[bb], x - 1, y - 1, z)
			)
		),
		lerp(
			v,
			lerp(
				u,
				grad(permutation[aa + 1], x, y, z - 1),
				grad(permutation[ba + 1], x - 1, y, z - 1)
			),
			lerp(
				u,
				grad(permutation[ab + 1], x, y - 1, z - 1),
				grad(permutation[bb + 1], x - 1, y - 1, z - 1)
			)
		)
	);
}

perlin::result_type perlin::fade(result_type t){
	return t * t * t * (t * (t * 6 - 15) + 10);
}

perlin::result_type perlin::lerp(
	result_type t,
	decltype(t) a,
	decltype(t) b
){
	return a + t * (b - a);
}

perlin::result_type perlin::grad(
	int hash,
	result_type x,
	decltype(x) y,
	decltype(x) z
){
	auto h = hash & 15;
	auto u = h < 8 ? x : y,
	     v = h < 4 ? y : h == 12 || h == 14 ? x : z;
	return ((h & 1) == 0 ? u : -u) + ((h & 2) == 0 ? v : -v);
}
