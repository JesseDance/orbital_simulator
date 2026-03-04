// Propagator.cpp

#include "Vector3D.h"
#include "Constants.h"

//function: twoBodyAccelartion
//input: The current position vector (r) of a satellite.
//output: The acceleration vector (a) due to Earth's gravity.
Vector3D twoBodyAcceleration(const Vector3D& position) {

	//get magnitude (r) of position vector
	double r = position.magnitude();

	//calculate scalar factor: -mu / r^3
	double r_cubed = r * r * r;

	//check for valid position vector

	double factor = -GM_EARTH / r_cubed;

	//multiply the position vector by the scalar factor
	Vector3D acceleration = position * factor;

	return acceleration;
}

//helper function to calculate Y_n + h*k_i
State add_scaled_derivatives(const State& state, const Derivatives& derivatives, double scale) {
	State new_state;

	//new position: r_new = r_old + (d_r/dt) * scale
	new_state.position = state.position derivatives.d_position * scale;

	//new velocity: v_new = v_old + (d_v/dt) * scale
	new_state.velocity = state.velocity + derivatives.d_velocity * scale;

	return new_state;
}

State rungeKutta4(const State& currentState, double dt) {
	//K1 derivative estimate at the start of the interval (Y_n)
	Derivatives k1 = getDerivatives(currentState);
	//K2 (Y_n + (dt/2) * k1)
	State state_k2 = add_scaled_derivatives(currentState, k1, dt * 0.5);
	Derivatives k2 = getDerivatives(state_k2);
	//K3 (Y_n + (dt/2) * k2)
	State state_k3 = add_scaled_derivatives(currentState, k2, dt * 0.5);
	Derivatives k3 = getDerivatives(state_k3);
	//K4 (Y_n + dt * k3)
	State state_k4 = add_scaled_derivatives(currentState, k3, dt);
	Derivatives k4 = getDerivatives(state_k4);
	//final weighted state 
	//Y_n+1 = Y_n + (dt/6) * (k1 + 2*k2 + 2*k3 + k4)
	State nextState;

	nextState.position = currentState.position +
						(k1.d_position + k2.d_position * 2.0 +
						 k3.d_position * 2.0 + k4.d_position) *
						(dt / 6.0);
	nextState.velocity = currentState.velocity +
						(k1.d_velocity + k2.d_velocity * 2.0 +
						 k3.d_velocity * 2.0 + k4.d_velocity) *
						(dt / 6.0);

	return nextState;
}