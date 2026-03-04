// State.h
#include "Vector3D.h"

struct State {
	Vector3D position; // r (in km)
	Vector3D velocity; // v (in km/s)
}

struct Derivatives {
	Vector3D d_position; // velocity (km/s)
	Vector3D d_velocity; // acceleration (km/s^2)
}