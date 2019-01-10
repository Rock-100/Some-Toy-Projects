#include "include.h"

void PointCloud::load(Mat model)
{
	for (int i = 0; i != model.rows; ++i)  
	{
		uint16_t *data = model.ptr<uint16_t>(i);  

		for (int j = 0; j != model.cols; ++j)
			if (data[j]>200 && data[j] < 1000)
			{
				point.push_back(Point3f(j, i, data[j]));
				center.x += j, center.y += i, center.z += data[j];
				size++;
			}		
	}

	center.x /= size, center.y /= size, center.z /= size;

	for (int i = 0; i != point.size(); ++i)
	{
		point[i].x -= center.x, point[i].y -= center.y, point[i].z -= center.z;
		point[i].y = -point[i].y;
		point[i].z = -point[i].z;

		if (point[i].x<nRange && point[i].x> -nRange &&
			point[i].y<nRange && point[i].y> -nRange &&
			point[i].z<nRange && point[i].z> -nRange)
		{
		}
		else
			size_out++;

	}
}

void PointCloud::draw()
{
	glBegin(GL_POINTS);
	glColor3f(0, 1, 0);
	for (int i = 0; i != point.size(); ++i)
	{
		if (point[i].x<nRange && point[i].x> -nRange &&
			point[i].y<nRange && point[i].y> -nRange &&
			point[i].z<nRange && point[i].z> -nRange)
			glVertex3f(point[i].x, point[i].y, point[i].z);
	}
		
	glEnd();
}


void PointCloud::output_parameter()
{
	cout << "number of point (display): " << size - size_out << endl;
	cout << "number of point (not display): " << size_out << endl;
	float minx=0, maxx=0, miny=0, maxy=0, minz=0, maxz=0;
	for (int i = 0; i != point.size(); ++i)
	{
		if (minx > point[i].x) minx = point[i].x;
		if (maxx < point[i].x) maxx = point[i].x;

		if (miny > point[i].y) miny = point[i].y;
		if (maxy < point[i].y) maxy = point[i].y;

		if (minz > point[i].z) minz = point[i].z;
		if (maxz < point[i].z) maxz = point[i].z;
	}

	cout << endl;
	cout << "range of display: " << -nRange << " to " << nRange << endl;
	cout << "range of X: " << minx << " to " << maxx << endl;
	cout << "range of Y: " << miny << " to " << maxy << endl;
	cout << "range of Z: " << minz << " to " << maxz << endl;
}