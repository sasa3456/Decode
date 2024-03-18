//------------------------------------------
//              Decode Decoder
//------------------------------------------


// Include
#include "Decoder.h"

// Namespace decode
namespace Decode
{
    // String textToBinaryString
    std::string Decoder::textToBinaryString(const std::string& text)
    {

        std::string binaryString;
        for (char c : text) 
        {
            binaryString += std::bitset<8>(c).to_string();
        }

        return binaryString;

    }

    // String textToHexademicalString
    std::string Decoder::textToHexadecimalString(const std::string& text) 
    {

        std::ostringstream hexStringStream;
        for (char c : text) 
        {
            hexStringStream << std::setw(2) << std::setfill('0') << std::hex << (int)c;
        }

        return hexStringStream.str();

    }

    std::string Decoder::textToOctalString(const std::string& text) 
    {
        std::ostringstream octalStringStream;
        for (char c : text) {
            octalStringStream << std::oct << (int)c;
        }
        return octalStringStream.str();
    }

}


