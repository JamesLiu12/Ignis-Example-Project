#include <Ignis.h>

class ButtonClick : public ignis::ScriptBehaviour
{
public:
	void OnPointerClick(int btn) override
	{
		if (btn == 0)
		{
			auto& text = GetEntity().GetComponent<ignis::UITextComponent>();
			text.Color = m_colors[current_index];
			current_index = (current_index + 1) % m_colors.size();
		}
	}

private:
	std::array<glm::vec4, 4> m_colors = {
		glm::vec4(0.94f, 0.33f, 0.31f, 1.0f),
		glm::vec4(0.20f, 0.69f, 0.53f, 1.0f),
		glm::vec4(0.29f, 0.56f, 0.89f, 1.0f),
		glm::vec4(0.98f, 0.75f, 0.15f, 1.0f),
	};
	int current_index = 0;
};

IGNIS_SCRIPT(ButtonClick)