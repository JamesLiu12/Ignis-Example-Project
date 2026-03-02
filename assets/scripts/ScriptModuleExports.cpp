#include <pch.h>
#include "Ignis/Script/ScriptAutoRegistry.h"

#if defined(_WIN32)
#define GAME_EXPORT extern "C" __declspec(dllexport)
#else
#define GAME_EXPORT extern "C" __attribute__((visibility("default")))
#endif

GAME_EXPORT void RegisterProjectScripts(ignis::ScriptRegistry& registry)
{
	ignis::RegisterPendingScripts(registry);
}

GAME_EXPORT void UnregisterProjectScripts(ignis::ScriptRegistry& registry)
{
	ignis::UnregisterPendingScripts(registry);
}