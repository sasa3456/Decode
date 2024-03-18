//------------------------------------------
//              Decode Menu
//------------------------------------------


// Includes
#pragma once
#include <windows.h>
#include <iostream>
#include <cstring>


// Namespace Decode
namespace Decode
{
	// Class Menu
	class Menu
	{
	public:

		int select_menu(short x, short y, const char* arr[], int num, short height);

	private:

		bool color_text(HANDLE hout, short x, short y, DWORD n, WORD color);
		void put_char(HANDLE hout, CHAR ch, short x, short y, WORD color);

	};
 
}


