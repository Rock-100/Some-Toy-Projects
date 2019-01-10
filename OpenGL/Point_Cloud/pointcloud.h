#ifndef POINTCLOUD_H
#define POINTCLOUD_H


using namespace cv;
using namespace std;


class PointCloud
{

public:
	PointCloud() :size(0), size_out(0)
	{
		center.x = 0.0;
		center.y = 0.0;
		center.z = 0.0;
	}

	void load(Mat model);

	void draw();

	void output_parameter();

private:
	int size;
	int size_out;
	Point3f center;
	vector<Point3f> point;
};

#endif