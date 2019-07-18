#pragma once
class Point3D
{
public:
	//Point3D(void);
	Point3D(double x = 0, double y = 0, double z = 0);
	~Point3D(void);

	Point3D operator *(const Point3D &vec);
	double operator %(const Point3D &vec);
	Point3D& operator += (const Point3D &vec);

	double operator [] (int idx) {
		return m_data[idx];
	}
	Point3D operator -(const Point3D &point);

	Point3D &Normalize();//µ¥Î»»¯
	double Length() const;
private:
	double m_data[3];
};
typedef Point3D CVector3D;
