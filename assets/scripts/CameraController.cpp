#include <Ignis.h>
#include <glm/glm.hpp>
#include <glm/gtc/constants.hpp>

class CameraController : public ignis::ScriptBehaviour
{
public:
	void OnCreate() override
	{
		auto& tf = GetEntity().GetComponent<ignis::TransformComponent>();
		tf.Translation = { 10.0f, 0.0f, 10.0f };

	}

	void OnUpdate(float dt) override
	{
		auto& tf = GetEntity().GetComponent<ignis::TransformComponent>();

		tf.Rotation.y += dt * m_speed;
	}

	void OnDestroy() override
	{

	}

private:
	float m_speed = 1.0f;
};

IGNIS_SCRIPT(CameraController)