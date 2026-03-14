#include "Ignis.h"

using namespace ignis;

class StartSceneController : public ScriptBehaviour
{
private:
	bool m_r_was_pressed = false;

public:
	void OnCreate() override
	{
		Log::Info("StartSceneController: Race Scene loaded - Press R to return to menu");
	}

	void OnUpdate(float dt) override
	{
		// Detect single key press by tracking previous state
		bool r_pressed = Input::IsKeyPressed(KeyCode::R);
		
		if (r_pressed && !m_r_was_pressed)
		{
			Log::Info("StartSceneController: Returning to menu...");
			SceneManager::LoadScene("assets/scenes/SecondScene.igscene");
		}
		
		m_r_was_pressed = r_pressed;
	}

	void OnDestroy() override
	{
		// Don't log during shutdown - logger may be destroyed
	}
};

IGNIS_SCRIPT(StartSceneController)
