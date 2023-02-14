#include <FString.h>
#include <Console.h>
#include <WebClient.h>
#include <Uri.h>
#include <Exception.h>


#define instanceof(a, b) Instanceof<a>(b)

/*
class A : public Object
{

public:
	void Test (const FString& msg, const FString& a)
	{
		LOG(msg);
		LOG(a);
	}

	REGISTER_METHOD(Test, &A::Tst, this, std::vector<ParameterInfo>({ ParameterInfo("msg", "FString", 0), ParameterInfo("a", "FString", 1) }))	
};

ENUM(Test, Giusy = 1, Gabriel = 5, Hugo)
ENUM(Test1, Benoit = 1, Pierre = 2, Aymeric, Thibaud = 2)

std::cout << *Test::Giusy << std::endl;
	for (Test t : TestSupport::Values{})
	{
		std::cout << *t << std::endl;
	}
	A a;
	MethodInfo<void, const FString&, const FString&>* method = a.GetMethod<void, const FString&, const FString&>("Test");
	if (_method == nullptr)
	{
		std::cout << "Function is null";
		return 4;
	}

	for (ParameterInfo _params : method->Parameter())
	{
		std::cout << "Type: " << _params.TypeName() << ", param name: " << _params.Name() << " position: " << _params.Position() << std::endl;
	}
*/

int main()
{
	
	try
	{
		Core::Net::WebClient _request = Core::Net::WebClient(Core::Net::Uri("Test_fichier_txt.jpg"));
		_request.DownloadFile("C://Users/pierr/source/repos/O3DLibrary");
	}
	catch (const Core::Exception& e)
	{
		LOG_ERROR(e);
	}
	return 0;
}

