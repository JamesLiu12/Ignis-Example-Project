#include <Ignis.h>

class CameraController : public ignis::ScriptBehaviour
{
public:
	void OnCreate() override
	{
		ignis::Input::LockCursor();

		m_mouse_x = ignis::Input::GetMouseX();
		m_mouse_y = ignis::Input::GetMouseY();
	}

	void OnUpdate(float dt) override
	{
		if (!ignis::Input::IsCursorLocked()) return;

		auto& tf = GetEntity().GetComponent<ignis::TransformComponent>();

		double cur_x = ignis::Input::GetMouseX();
		double cur_y = ignis::Input::GetMouseY();

		if (ignis::Input::ConsumeCursorJustLocked())
		{
			m_mouse_x = cur_x;
			m_mouse_y = cur_y;
			return;
		}

		float dx = (float)(cur_x - m_mouse_x);
		float dy = (float)(cur_y - m_mouse_y);

		m_mouse_x = cur_x;
		m_mouse_y = cur_y;

		tf.Rotation.y -= dx * m_sensitivity;
		tf.Rotation.x -= dy * m_sensitivity;

		tf.Rotation.x = glm::clamp(tf.Rotation.x,
			glm::radians(-89.0f),
			glm::radians(89.0f));

		float speed = m_speed;
		if (ignis::Input::IsKeyPressed(ignis::KeyCode::LeftShift))
			speed *= m_boost_factor;

		glm::quat rotation = tf.GetRotationQuat();
		glm::vec3 forward = rotation * glm::vec3(0.0f, 0.0f, -1.0f);
		glm::vec3 right = rotation * glm::vec3(1.0f, 0.0f, 0.0f);
		glm::vec3 world_up = glm::vec3(0.0f, 1.0f, 0.0f);

		if (ignis::Input::IsKeyPressed(ignis::KeyCode::W))
			tf.Translation += forward * speed * dt;
		if (ignis::Input::IsKeyPressed(ignis::KeyCode::S))
			tf.Translation -= forward * speed * dt;
		if (ignis::Input::IsKeyPressed(ignis::KeyCode::A))
			tf.Translation -= right * speed * dt;
		if (ignis::Input::IsKeyPressed(ignis::KeyCode::D))
			tf.Translation += right * speed * dt;
		if (ignis::Input::IsKeyPressed(ignis::KeyCode::E))
			tf.Translation += world_up * speed * dt;
		if (ignis::Input::IsKeyPressed(ignis::KeyCode::Q))
			tf.Translation -= world_up * speed * dt;
	}

	void OnDestroy() override {}

private:
	double m_mouse_x = 0.0;
	double m_mouse_y = 0.0;

	float  m_sensitivity = 0.002f;
	float  m_speed = 5.0f;
	float  m_boost_factor = 3.0f;
};

IGNIS_SCRIPT(CameraController)