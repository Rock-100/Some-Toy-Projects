#include "include.h"

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800, 600);
	glutCreateWindow("model");

	glutReshapeFunc(ChangeSize);
	glutSpecialFunc(SpecialKeys);
	glutDisplayFunc(RenderScene);
	SetupRC();

	FileStorage fs("model/face2.yaml", FileStorage::READ);
	Mat face;
	fs["face"] >> face;
	fs.release();

	p.load(face);
	p.output_parameter();
	glutMainLoop();

	return 0;
}
