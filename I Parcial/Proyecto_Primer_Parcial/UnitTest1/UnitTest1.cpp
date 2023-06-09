#include "CppUnitTest.h"
#include "../Proyecto_P1/Menu.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
        TEST_METHOD(menu)
        {
            Menu<std::string> menu;
            menu.ejecutar();
        }

	};
}
