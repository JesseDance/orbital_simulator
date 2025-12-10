// Vector3D.h

class Vector3D {
public:
	double x, y, z;

	//default constructor of zero vector
	Vector3D() : x(0.0), y(0.0), z(0.0) {}

	//parameterized constructor 
	Vector3D(double val_x, double val_y, double val_z) 
		: x(val_x), y(val_y), z(val_z) {}
};