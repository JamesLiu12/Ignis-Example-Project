#include <pch.h>
#include "Ignis/Script/ScriptBehaviour.h"
#include "Ignis/Script/ScriptAutoRegistry.h"

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