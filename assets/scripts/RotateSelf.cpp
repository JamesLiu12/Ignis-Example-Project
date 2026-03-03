#include "Ignis.h"

class RotateSelf : public ignis::ScriptBehaviour
{
public:
	void OnUpdate(float dt) override
	{
		auto& tf = GetEntity().GetComponent<ignis::TransformComponent>();
		tf.Rotation.y += dt;
	}
};

IGNIS_SCRIPT(RotateSelf)