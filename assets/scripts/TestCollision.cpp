#include <Ignis.h>

class TestCollision : public ignis::ScriptBehaviour
{
public:
	void OnCollisionEnter(ignis::Entity other) override
	{
		if (other.HasComponent<ignis::TagComponent>())
		{
			auto& tag = other.GetComponent<ignis::TagComponent>();
			ignis::Log::Info("[COLLISION ENTER] {} hit {}", 
				GetEntity().GetComponent<ignis::TagComponent>().Tag, 
				tag.Tag);
		}
	}
	
	void OnCollisionExit(ignis::Entity other) override
	{
		if (other.HasComponent<ignis::TagComponent>())
		{
			auto& tag = other.GetComponent<ignis::TagComponent>();
			ignis::Log::Info("[COLLISION EXIT] {} separated from {}", 
				GetEntity().GetComponent<ignis::TagComponent>().Tag, 
				tag.Tag);
		}
	}
	
	void OnTriggerEnter(ignis::Entity other) override
	{
		if (other.HasComponent<ignis::TagComponent>())
		{
			auto& tag = other.GetComponent<ignis::TagComponent>();
			ignis::Log::Info("[TRIGGER ENTER] {} entered {}", 
				tag.Tag,
				GetEntity().GetComponent<ignis::TagComponent>().Tag);
		}
	}
	
	void OnTriggerExit(ignis::Entity other) override
	{
		if (other.HasComponent<ignis::TagComponent>())
		{
			auto& tag = other.GetComponent<ignis::TagComponent>();
			ignis::Log::Info("[TRIGGER EXIT] {} left {}", 
				tag.Tag,
				GetEntity().GetComponent<ignis::TagComponent>().Tag);
		}
	}
};

IGNIS_SCRIPT(TestCollision)
