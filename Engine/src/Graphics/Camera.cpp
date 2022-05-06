#include "Camera.h"
#include <glm/gtc/matrix_transform.hpp>

Camera::Camera()
{
	myPosition = glm::vec3(0.0f, 0.0f, 0.0f);
	myRotation = glm::vec3(0.0f, 0.0f, 0.0f);
	myPositionV4 = glm::vec4(0.0f, 0.0f, 0.0f, 1.0f);
	myRotationV4 = glm::vec4(0.0f, 0.0f, 0.0f, 1.0f);
	UpdateViewMatrix();
}

void Camera::SetProjectionValues(float fovDegrees, float aspectRatio, float nearZ, float farZ)
{
	myProjectionMatrix = glm::perspective(glm::radians(fovDegrees), aspectRatio, nearZ, farZ);
}

const glm::mat4& Camera::GetViewMatrix() const
{
	return myViewMatrix;
}

const glm::mat4& Camera::GetProjectionMatrix() const
{
	return myProjectionMatrix;
}

const glm::vec4& Camera::GetPositionVector() const
{
	return myPositionV4;
}

const glm::vec3& Camera::GetPositionFloat3() const
{
	return myPosition;
}

const glm::vec4& Camera::GetRotationVector() const
{
	return myRotationV4;
}

const glm::vec3& Camera::GetRotationFloat3() const
{
	return myRotation;
}

void Camera::SetPosition(const glm::vec4& pos)
{
	myPositionV4 = pos;
	UpdateViewMatrix();
}

void Camera::SetPosition(float x, float y, float z)
{
	myPosition = glm::vec3(x, y, z);
	UpdateViewMatrix();
}

void Camera::AdjustPosition(const glm::vec4& pos)
{
	myPositionV4 += pos;
	UpdateViewMatrix();
}

void Camera::AdjustPosition(float x, float y, float z)
{
	myPosition += glm::vec3(x, y, z);
	UpdateViewMatrix();
}

void Camera::SetRotation(const glm::vec4& rot)
{
	myRotationV4 = rot;
	UpdateViewMatrix();
}

void Camera::SetRotation(float x, float y, float z)
{
	myRotation = glm::vec3(x, y, z);
	UpdateViewMatrix();
}

void Camera::AdjustRotation(const glm::vec4& rot)
{
	myRotationV4 += rot;
	UpdateViewMatrix();
}

void Camera::AdjustRotation(float x, float y, float z)
{
	myRotation += glm::vec3(x, y, z);
	UpdateViewMatrix();
}

void Camera::UpdateViewMatrix()
{
	myViewMatrix = glm::lookAt(myPosition, myPosition + DEFAULT_FORWARD_VECTOR, DEFAULT_UP_VECTOR);
}
