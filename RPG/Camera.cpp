#include "Camera.h"
Camera::Camera() {
	
	view =  Vector3(0, 0, -1);
	up = Vector3(0, 1, 0);
	pos = Vector3(0, 0, 0);

	forword = view - pos;
	right = forword.crossProduct(up);
	yaw = 0.0f;
	pitch = 0.0f;
	moveLeft = false, moveRight = false, moveForward = false, moveBack = false;

}

Camera::Camera(Vector3 *look)
{
	pos = Vector3();

	forword = view;
	up = Vector3(0, 1, 0);
	right = forword.crossProduct(up);
	speed = Vector3(0, 0, 0);

}

Camera::Camera(Vector3 *pos, Vector3* look)
{
	this->pos = *pos;


	forword = view;
	up = Vector3(0, 1, 0);
	right = Vector3(1, 0, 0);

	speed = Vector3(0, 0, 0);
	yaw = 0.0;
	pitch = 0.0;



}



void Camera::RotateYaw(float radians)
{
	RotateView(radians, up.x, up.y, up.z);
	
}
void Camera::RotatePitch(float radians)
{
	Vector3 viewDirection = view - pos;
	viewDirection.unit();
	right = viewDirection.crossProduct(up);
	right.unit();

	RotateView(radians, right.x, right.y, right.z);
	
}
void Camera::RotateRoll(float radians)
{
	float sine = sinf(radians);
	float cosine = cosf(radians);

	right.x = cosine*right.Length();
	right.y = sine*right.Length();

	up.x = -sine*forword.Length();
	up.y = cosine*forword.Length();
}

void Camera::Update(float deltaTime)
{
	forword = view - pos;
	forword.unit();
	right = forword.crossProduct(up);
	right.unit();

	if (moveLeft)
	{
		pos = pos - right*deltaTime*0.05;
		moveLeft = false;
	}
	if (moveRight)
	{
		pos = pos + right*deltaTime*0.05;
		moveRight = false;
	}
	if (moveForward)
	{
		pos = pos + forword*deltaTime*0.05;
		moveForward = false;
	}

	if (moveBack)
	{
		pos = pos - forword*deltaTime*0.05;
		moveBack = false;
	}
	
	gluLookAt(pos.x, pos.y, pos.z,
		 view.x,  view.y,  view.z,
		0, 1, 0);
}

void Camera::RotateView(float angle, float x, float y, float z)
{
	Vector3 viewDirection = view - pos;
	Vector3 newDirection;
	float C = cosf(angle);
	float S = sinf(angle);

	Vector3 tempX(C + x*x*(1 - C), x*y*(1 - C) - z*S, x*z*(1 - C) + y*S);
	newDirection.x = tempX*viewDirection;

	Vector3 tempY(x*y*(1 - C) + z*S, C + y*y*(1 - C), y*z*(1 - C) - x*S);
	newDirection.y = tempY*viewDirection;

	Vector3 tempZ(x*z*(1 - C) - y*S, y*z*(1 - C) + x*S, C + z*z*(1 - C));
	newDirection.z = tempZ*viewDirection;

	view = pos + newDirection;
}

void Camera::SwitchTo3D()
{
	glMatrixMode(GL_PROJECTION);//tell the gpu processer that i would select the projection matrix
	glLoadIdentity();
	gluPerspective(50.0f, (float)w / (float)h, 0.1f, 1000.0f);//set some values to projection matrix
	glMatrixMode(GL_MODELVIEW);//tell .... model view matrix
}

void Camera::SwitchTo2D()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-w / 2, w / 2, -h / 2, h / 2);
	glMatrixMode(GL_MODELVIEW);
}