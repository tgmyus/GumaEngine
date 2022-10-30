#pragma once

#ifdef GUMA_PLATFORM_WINDOWS

extern Guma::Application* Guma::CreateApplication();

int main(int argc, char** argv)
{
	Guma::Log::Init();

	auto* App = Guma::CreateApplication();
	App->Run();
	delete App;
}

#endif
