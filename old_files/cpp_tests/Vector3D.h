// Vector3D.h

class Vector3D {
public:
	//member variables
	double x, y, z;

	//default constructor of zero vector
	Vector3D() : x(0.0), y(0.0), z(0.0) {}

	//parameterized constructor 
	Vector3D(double val_x, double val_y, double val_z) 
		: x(val_x), y(val_y), z(val_z) {}

	//get magnitude method
	double magnitude() const {
		return std::sqrt(x*x + y*y + z*z);
	}

	Vector3D operator+(const Vector3D& other) const {
		return Vector3D(
			x + other.x,
			y + other.y,
			z + other.z
			);
	}

	Vector3D operator-(const Vector3D& other) const {
		return Vector3D(
			x - other.x,
			y - other.y,
			z - other.z
		);
	}

	Vector3D operator*(const double scalar) const {
		return Vector3D(
			x * scalar;
			y * scalar;
			z * scalar;
		);
	}

	Vector3D operator/(double scalar) const {
		if(scalar == 0) {
			throw std::runtime_error("Attempted to divide Vector3D by zero.");
		}

			// simple approach:
			// return Vector3D(
			// 	x / scalar,
			// 	y / scalar,
			// 	z / scalar
			// );

		//optimized approach 
		//multiplication is faster than division
		double inv_scalar = 1 / scalar;
		return Vector3D(
			x * inv_scalar,
			y * inv_scalar,
			z * inv_scalar
		);
	}
};