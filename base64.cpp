#include "base64.h"
#include <string>

std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

std::string Encode(const std::string& bytes)
{
    std::string result;
    result.reserve(bytes.size() * 4 / 3);
    char bytes4[4];
    char bytes3[3];

    int count_zeros = 0;
    if (bytes.size() % 3) {
        count_zeros = 3 - (bytes.size() % 3);
    }
    int k = 0;
    while (k < bytes.size()){
        bytes3[0] = bytes[k];
        if (k + 1 >= bytes.size())
            bytes3[1] = 0;
        else
            bytes3[1] = bytes[k + 1];
        if (k + 2 >= bytes.size())
            bytes3[2] = 0;
        else
            bytes3[2] = bytes[k + 2];

        bytes4[0] = (bytes3[0] & 0xfc) >> 2;
        bytes4[1] = ((bytes3[0] & 0x03) << 4) + ((bytes3[1] & 0xf0) >> 4);
        bytes4[2] = ((bytes3[1] & 0x0f) << 2) + ((bytes3[2] & 0xc0) >> 6);
        bytes4[3] = bytes3[2] & 0x3f;
        k += 3;
        for (int i = 0; i < 4; i++) {
            result.push_back(alphabet[bytes4[i]]);
        }
    }
    while (count_zeros) {
        result[result.size() - count_zeros--] = '=';
    }

    return result;
}

std::string Decode(const std::string& bytes)
{

    std::string result;
    result.reserve(bytes.size() * 3 / 4);

    char bytes4[4];
    char bytes3[3];

    int k = 0;
    while (k < bytes.size() && bytes[k] != '=')
    {
        bytes4[0] = bytes[k];
        bytes4[1] = bytes[k + 1];
        bytes4[2] = bytes[k + 2];
        bytes4[3] = bytes[k + 3];

        for (int i = 0; i < 4; i++)
            bytes4[i] = alphabet.find(bytes4[i]) & 0xff;

        bytes3[0] = (bytes4[0] << 2) + ((bytes4[1] & 0x30) >> 4);
        bytes3[1] = ((bytes4[1] & 0x0f) << 4) + ((bytes4[2] & 0x3c) >> 2);
        bytes3[2] = ((bytes4[2] & 0x03) << 6) + bytes4[3];
        k += 4;
        for (int i = 0; i < 3; i++) {
            result.push_back(bytes3[i]);
        }
    }

    return result;
}
