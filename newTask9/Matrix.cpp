#include "StdAfx.h"
#include "Matrix.h"
#include<math.h>

CMatrix::CMatrix(double value)
{
	memset(m_data[0], 0, sizeof(double) * 9);
	m_data[0][0] = value;
	m_data[1][1] = value;
	m_data[2][2] = value;
}


void CMatrix::SetIdentity()
{
	memset(m_data[0], 0, sizeof(double) * 9);
	m_data[0][0] = 1;
	m_data[1][1] = 1;
	m_data[2][2] = 1;
}
CMatrix::~CMatrix(void)
{
}

CMatrix CMatrix::operator *(const CMatrix &matrix)
{
	CMatrix result;
	for (int i = 0;i < 3;++i)
	{
		for (int j = 0;j < 3;j++)
		{
			result[i][j] = m_data[i][0] * matrix[0][j] +
				m_data[i][1] * matrix[1][j] +
				m_data[i][2] * matrix[2][j];

		}
	}
	return result;
}

CMatrix CMatrix::GetRotationMatrix(double angle, double x, double y, double z)
{
#define  ZERO_TOL    1.0e-7
	double s = sin(angle);
	double c = cos(angle);

	CMatrix matrix;
	if (fabs(z) < ZERO_TOL)
	{
		if (fabs(y) < ZERO_TOL)
		{
			//if the axis is (0, 0, 0), assume to be identity matrix
			if (fabs(x) < ZERO_TOL)
				return matrix;

			//rotation axis is (1, 0, 0)
			matrix[0][0] = 1.0;
			matrix[1][1] = c;  matrix[2][2] = c;

			if (x > 0)
			{
				matrix[1][2] = -s; matrix[2][1] = s;
			}
			else
			{
				matrix[1][2] = s; matrix[2][1] = -s;
			}

			return matrix;

		}
		else if (fabs(x) < ZERO_TOL)
		{
			//rotation axis is (0, 1, 0)
			matrix[1][1] = 1.0;
			matrix[0][0] = c;  matrix[2][2] = c;

			if (y > 0)
			{
				matrix[0][2] = s;  matrix[2][0] = -s;
			}
			else
			{
				matrix[0][2] = -s;  matrix[2][0] = s;
			}

			return matrix;
		}
	}
	else if (fabs(y) < ZERO_TOL)
	{
		if (fabs(x) < ZERO_TOL)
		{
			//rotation axis is (0, 0, 1)
			matrix[2][2] = 1.0;
			matrix[0][0] = c;  matrix[1][1] = c;

			if (z > 0)
			{
				matrix[0][1] = -s; matrix[1][0] = s;
			}
			else
			{
				matrix[0][1] = s; matrix[1][0] = -s;
			}

			return matrix;
		}
	}

	//common case

	//normalize the rotation axis
	double mag = sqrt(x * x + y * y + z * z);
	mag = 1.0 / mag;
	x *= mag;
	y *= mag;
	z *= mag;

	double t = 1.0 - c;

	double tx = t * x;
	double ty = t * y;
	double tz = t * z;
	double sx = s * x;
	double sy = s * y;
	double sz = s * z;

	//-----------------------------------------------------------
	//		| t*x*x + c		t*x*y - s*z		t*x*z + s*y |
	//		|											|
	//	R = | t*x*y + s*z	t*y*y + c		t*y*z - s*x |
	//		|											|
	//		| t*x*z - s*y	t*y*z + s*x		t*z*z + c	|
	//
	// where c = cos(theta), s = sin(theta), t = 1 - c and(x, y, z) is a unit
	// vector on the axis of rotation.
	//-----------------------------------------------------------

	// row one
	matrix[0][0] = tx * x + c;
	matrix[0][1] = tx * y - sz;
	matrix[0][2] = tx * z + sy;

	// row two
	matrix[1][0] = matrix[0][1] + sz + sz;	// tx * y + sz
	matrix[1][1] = ty * y + c;
	matrix[1][2] = ty * z - sx;

	// row three
	matrix[2][0] = matrix[0][2] - sy - sy;	// tx * z - sy
	matrix[2][1] = matrix[1][2] + sx + sx;	// ty * z + sx
	matrix[2][2] = tz * z + c;

	return matrix;
}

