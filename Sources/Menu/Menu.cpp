//------------------------------------------
//              Decode Menu
//------------------------------------------


// Includes
#include "Menu.h"


// Namespace Decode
namespace Decode
{
    // Bool color_text
	bool Menu::color_text(HANDLE hout, short x, short y, DWORD n, WORD color)
	{

		COORD p = { x, y };
		DWORD l = 0;
		return FillConsoleOutputAttribute(hout, color, n, p, &l);

	}
	
    // Void put_char
	void Menu::put_char(HANDLE hout, CHAR ch, short x, short y, WORD color)
	{

		COORD p = { x, y };
		DWORD n = 0;
		WriteConsoleOutputCharacterA(hout, &ch, 1, p, &n);
		WriteConsoleOutputAttribute(hout, &color, 1, p, &n);

	}

    // Int select_menu
	int Menu::select_menu(short x, short y, const char* arr[], int num, short height)
	{

        char ch = '\x10';
        static HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
        static HANDLE hin = GetStdHandle(STD_INPUT_HANDLE);
        if ((hout == INVALID_HANDLE_VALUE) || (hin == INVALID_HANDLE_VALUE))
            return -1;

        const WORD tcol = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;
        const WORD scol = FOREGROUND_RED | FOREGROUND_GREEN | BACKGROUND_BLUE | FOREGROUND_INTENSITY | BACKGROUND_INTENSITY;
        const WORD pcol = FOREGROUND_GREEN | FOREGROUND_INTENSITY;

        COORD p = { x + 1, y };
        DWORD m = 0, n = 0;

        static int   prev = -1, index = 0;
        static DWORD smax = 0;

        if (prev == -1) 
        {
            for (int j = 0; j < num; ++j) 
            {
                if ((m = (DWORD)strlen(arr[j])) > smax)
                    smax = m;
            }

            std::string s;
            for (int i = 0; i < num; ++i, p.Y += height) 
            {
                s = arr[i];
                CharToOemBuffA(&s[0], &s[0], s.length());
                WriteConsoleOutputCharacterA(hout, s.c_str(), s.length(), p, &n);
                if (index == i) 
                {
                    put_char(hout, ch, x, y, pcol);
                    color_text(hout, p.X, p.Y, smax, scol);
                }
                else
                    color_text(hout, p.X, p.Y, smax, tcol);
            }

            prev = 0;
        }

        INPUT_RECORD rs[128];
        while (ReadConsoleInput(hin, rs, 128, &n)) 
        {
            for (DWORD i = 0; i < n; ++i) 
            {
                if ((rs[i].EventType != KEY_EVENT) || !rs[i].Event.KeyEvent.bKeyDown)
                    continue;

                switch (rs[i].Event.KeyEvent.wVirtualKeyCode) 
                {

                case VK_UP: // ¬верх
                    if (index > 0)
                        prev = index--;
                    break;
                case VK_DOWN: // ¬низ
                    if (index < (num - 1))
                        prev = index++;
                    break;
                case VK_RETURN:
                    FlushConsoleInputBuffer(hin);
                    return index;

                }

                if (index != prev) 
                {
                    put_char(hout, ' ', x, y + prev * height, pcol);
                    color_text(hout, p.X, y + prev * height, smax, tcol);
                    put_char(hout, ch, x, y + index * height, pcol);
                    color_text(hout, p.X, y + index * height, smax, scol);
                    prev = index;
                }
            }
        }

        return -1;
	}
}
