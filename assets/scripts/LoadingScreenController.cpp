#include "Ignis.h"

using namespace ignis;

class LoadingScreenController : public ScriptBehaviour
{
private:
	AsyncSceneLoader m_loader;
	bool m_loading_started = false;
	
public:
	void OnCreate() override
	{
		Log::Info("LoadingScreenController: Loading screen active - preparing to load race level");
	}
	
	void OnUpdate(float dt) override
	{
		if (!m_loading_started)
		{
			// Resolve the asset path to absolute path
			std::filesystem::path scene_path = VFS::Resolve("assets://scenes/StartScene.igscene");
			
			// Start async load of the heavy race scene (StartScene)
			m_loader.LoadSceneAsync(scene_path);
			m_loading_started = true;
			Log::Info("LoadingScreenController: Started async loading of StartScene (race level)...");
		}
		
		// Check if loading is complete
		if (m_loader.IsReady())
		{
			Log::Info("LoadingScreenController: Loading complete! Transitioning to race level...");
			
			// Transition to the loaded scene
			SceneManager::LoadScene("assets/scenes/StartScene.igscene");
		}
		else
		{
			// Display progress (currently 0.0 or 1.0)
			float progress = m_loader.GetProgress();
			
			// TODO: Update UI text/progress bar here
			// Example: Update a UI Text component with progress percentage
			
			// Log progress occasionally
			static int frame_count = 0;
			if (++frame_count % 60 == 0)
			{
				Log::Info("LoadingScreenController: Loading progress: {:.0f}%", progress * 100.0f);
			}
		}
	}
	
	void OnDestroy() override
	{
		// Don't log during shutdown - logger may be destroyed
	}
};

IGNIS_SCRIPT(LoadingScreenController)
