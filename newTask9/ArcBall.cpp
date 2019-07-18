#include "StdAfx.h"
#include "ArcBall.h"
#include"Matrix.h"
#include<math.h>

ArcBall::ArcBall(void)
{
	m_rotation.SetIdentity();
}

ArcBall::~ArcBall(void)
{
}

void ArcBall::SetBound(int Width, int height)
{

	m_winWidth = Width;
	m_winHeight = height;
}

Point3D ArcBall::CoordToSphere(int x, int y)
{
	double xScale = 2.0 / m_winWidth;
	double yScale = 2.0 / m_winHeight;

	double xPos = x * xScale - 1;
	double yPos = 1 - y * yScale;
	double zPos = 0.0;

	double len = xPos * xPos + yPos * yPos;
	if (len < 1.0)
	{
		zPos = sqrt(1.0 - len);
	}

	return Point3D(xPos, yPos, zPos);
}
void ArcBall::click(const CPoint &pt)
{
	m_ptlast = CoordToSphere(pt.x, pt.y);
}

void ArcBall::drag(const CPoint &pt)
{
	Point3D ptCur = CoordToSphere(pt.x, pt.y);
	CVector3D axis = m_ptlast * ptCur;
	m_ptlast.Normalize();
	ptCur.Normalize();

	double c = m_ptlast % ptCur;
	double angle = 2 * acos(c);

	CMatrix matrix = CMatrix::GetRotationMatrix(angle, axis[0], axis[1], axis[2]);
	m_rotation = matrix * m_rotation;
	m_ptlast = ptCur;
}
double *ArcBall::GetRotationData()
{
	static double data[16];

	data[0] = m_rotation[0][0];
	data[1] = m_rotation[1][0];
	data[2] = m_rotation[2][0];
	data[3] = 0;

	data[4] = m_rotation[0][1];
	data[5] = m_rotation[1][1];
	data[6] = m_rotation[2][1];
	data[7] = 0;

	data[8] = m_rotation[0][2];
	data[9] = m_rotation[1][2];
	data[10] = m_rotation[2][2];
	data[11] = 0;

	data[12] = 0;
	data[13] = 0;
	data[14] = 0;
	data[15] = 1;

	return data;
}
