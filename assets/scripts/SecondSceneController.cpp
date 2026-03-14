#include "Ignis.h"

using namespace ignis;

class SecondSceneController : public ScriptBehaviour
{
public:
	void OnCreate() override
	{
		Log::Info("SecondSceneController: Scene loaded - Press R to go back to StartScene");
	}

	void OnUpdate(float dt) override
	{
		// Check if T key is pressed
		if (Input::IsKeyPressed(KeyCode::T))
		{
			Log::Info("SecondSceneController: R pressed - Loading StartScene...");
			SceneManager::LoadScene("assets/scenes/StartScene.igscene");
		}
	}

	void OnDestroy() override
	{
		Log::Info("SecondSceneController: Leaving SecondScene");
	}
};

IGNIS_SCRIPT(SecondSceneController)
