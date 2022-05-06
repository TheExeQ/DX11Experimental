#pragma once
#include <glm/glm.hpp>

class Camera
{
public:
	Camera();
	void SetProjectionValues(float fovDegrees, float aspectRatio, float nearZ, float farZ);

	const glm::mat4& GetViewMatrix() const;
	const glm::mat4& GetProjectionMatrix() const;

	const glm::vec4& GetPositionVector() const;
	const glm::vec3& GetPositionFloat3() const;
	const glm::vec4& GetRotationVector() const;
	const glm::vec3& GetRotationFloat3() const;

	void SetPosition(const glm::vec4& pos);
	void SetPosition(float x, float y, float z);
	void AdjustPosition(const glm::vec4& pos);
	void AdjustPosition(float x, float y, float z);
	void SetRotation(const glm::vec4& rot);
	void SetRotation(float x, float y, float z);
	void AdjustRotation(const glm::vec4& rot);
	void AdjustRotation(float x, float y, float z);

private:
	void UpdateViewMatrix();
	glm::vec4 myPositionV4;
	glm::vec4 myRotationV4;
	glm::vec3 myPosition;
	glm::vec3 myRotation;
	glm::mat4 myViewMatrix;
	glm::mat4 myProjectionMatrix;

	const glm::vec3 DEFAULT_FORWARD_VECTOR = glm::vec3(0.0f, 0.0f, 1.0f);
	const glm::vec3 DEFAULT_UP_VECTOR = glm::vec3(0.0f, 1.0f, 0.0f);
};