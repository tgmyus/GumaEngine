#include <GumaEngine.h>

class App : public Guma::Application
{

};

Guma::Application* Guma::CreateApplication()
{
	return new App();
}
