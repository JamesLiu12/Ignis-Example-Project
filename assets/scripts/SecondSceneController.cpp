#include "Ignis.h"

using namespace ignis;

class SecondSceneController : public ScriptBehaviour
{
private:
	bool m_t_was_pressed = false;

public:
	void OnCreate() override
	{
		Log::Info("SecondSceneController: Menu Scene loaded - Press T to start race (will show loading screen)");
	}

	void OnUpdate(float dt) override
	{
		// Detect single key press by tracking previous state
		bool t_pressed = Input::IsKeyPressed(KeyCode::T);
		
		if (t_pressed && !m_t_was_pressed)
		{
			Log::Info("SecondSceneController: Starting race - transitioning to loading screen...");
			
			// Go to loading scene first (loads instantly)
			SceneManager::LoadScene("assets/scenes/LoadingScene.igscene");
		}
		
		m_t_was_pressed = t_pressed;
	}

	void OnDestroy() override
	{
		// Don't log during shutdown - logger may be destroyed
	}
};

IGNIS_SCRIPT(SecondSceneController)
