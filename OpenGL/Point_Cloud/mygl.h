#ifndef MYGL_H
#define MYGL_H

using namespace cv;
using namespace std;

#define GL_PI 3.1415f

extern GLfloat nRange;

extern PointCloud p;

extern void RenderScene(void);

extern void SetupRC();

extern void SpecialKeys(int key, int x, int y);

extern void ChangeSize(int w, int h);

#endif
