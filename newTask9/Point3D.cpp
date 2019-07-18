#include "StdAfx.h"
#include "Point3D.h"
#include <math.h>

Point3D::Point3D(double x, double y, double z)
{
	m_data[0] = x;
	m_data[1] = y;
	m_data[2] = z;
}

Point3D Point3D :: operator *(const Point3D &vec) {
	double x = m_data[1] * vec.m_data[2] - vec.m_data[1] * m_data[2];
	double y = m_data[2] * vec.m_data[0] - vec.m_data[2] * m_data[0];
	double z = m_data[0] * vec.m_data[1] - vec.m_data[0] * m_data[1];

	return Point3D(x, y, z);
}

double Point3D :: operator %(const Point3D &vec) {
	return m_data[0] * vec.m_data[0] + m_data[1] * vec.m_data[1] + m_data[2] * vec.m_data[2];
}

double Point3D::Length() const {
	double len = m_data[0] * m_data[0] + m_data[1] * m_data[1] + m_data[2] * m_data[2];
	return sqrt(len);
}

Point3D &Point3D::Normalize() {
	double len = Length();
	if (len < 1.0e-8) {
		return *this;
	}
	m_data[0] /= len;
	m_data[1] /= len;
	m_data[2] /= len;

	return *this;
}

Point3D Point3D::operator -(const Point3D &point)
{
	return Point3D(m_data[0] - point.m_data[0], m_data[1] - point.m_data[1], m_data[2] - point.m_data[2]);
}

Point3D& Point3D::operator +=(const Point3D &point)
{
	m_data[0] += point.m_data[0];
	m_data[1] += point.m_data[1];
	m_data[2] += point.m_data[2];

	return *this;
}
Point3D::~Point3D(void)
{
}
