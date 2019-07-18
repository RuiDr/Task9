#pragma once
class CMatrix
{
public:
	CMatrix(double value = 1);
	~CMatrix(void);

	double *operator[] (int idx) {
		return m_data[idx];
	}

	const double *operator[] (int idx) const
	{
		return m_data[idx];
	}

	CMatrix operator *(const CMatrix &matrix);

	static CMatrix GetRotationMatrix(double angle, double x, double y, double z);
	void SetIdentity();
private:
	double m_data[3][3];
};

