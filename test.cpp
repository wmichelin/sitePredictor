#include <OnixS/FIXEngine.h>

using namespace std;

try
{
	OnixS::FIX::Engine::init();

	cout << "hello fix" << endl;

	OnixS::FIX::Engine::shutdown();


}
catch(const Exception& ex)
{
	cout << ex.what() << " error!" << endl;
}