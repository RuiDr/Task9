#pragma once
#include "Point3D.h"
#include "Matrix.h"
class ArcBall
{
public:
	ArcBall(void);
	~ArcBall(void);
	void SetBound(int Width, int height);

	Point3D CoordToSphere(int x, int y);
	void click(const CPoint &pt);
	void drag(const CPoint &pt);

	double *GetRotationData();

private:
	int m_winWidth, m_winHeight;
	Point3D m_ptlast;
	CMatrix m_rotation;
};

