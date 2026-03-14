#include "Ignis.h"

using namespace ignis;

class StartSceneController : public ScriptBehaviour
{
public:
	void OnCreate() override
	{
		Log::Info("StartSceneController: Scene loaded - Press R to go to SecondScene");
	}

	void OnUpdate(float dt) override
	{
		// Check if R key is pressed
		if (Input::IsKeyPressed(KeyCode::R))
		{
			Log::Info("StartSceneController: R pressed - Loading SecondScene...");
			SceneManager::LoadScene("assets/scenes/SecondScene.igscene");
		}
	}

	void OnDestroy() override
	{
		Log::Info("StartSceneController: Leaving StartScene");
	}
};

IGNIS_SCRIPT(StartSceneController)
