#pragma once
#include "Point.h"
#include <iostream>
using namespace std;
class Facet
{
public:
	// 面片索引
	int index;
	// 体积
	double volume;
	// 面积
	double s;
	// 面片中点的数据
	Point _vertex_1;
	Point _vertex_2;
	Point _vertex_3;
	double sum;
	vector<double>list;

	~Facet();
	Facet()
	{}
	bool operator<(const Facet& _b) const
	{
		if (_b.index < index)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void toString()
	{
		cout << "x= " << _vertex_1.index << " y= " << _vertex_2.index << " z= " << _vertex_3.index << endl;
	}
};

