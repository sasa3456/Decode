//------------------------------------------
//              Decode Decoder
//------------------------------------------


// Includes
#pragma once
#include <iostream>
#include <bitset>
#include <string>
#include <iomanip>
#include <sstream>

// Namespace Decode
namespace Decode
{
	// Class decoder
	class Decoder
	{

	public:
		static std::string textToBinaryString(const std::string& text);
		static std::string textToHexadecimalString(const std::string& text);
		static std::string textToOctalString(const std::string& text);

	};
}