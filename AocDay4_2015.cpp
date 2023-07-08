#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cstring>
#include <sstream>
#include <cmath>
#include "md5.h"

//const int size_of_array = 64;
//
//
//constexpr uint32_t S[size_of_array] = {
//    7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22,
//    5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20,
//    4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23,
//    6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21
//};
//constexpr uint32_t K[size_of_array] = {
//    0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee,
//    0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501,
//    0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be,
//    0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821,
//    0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa,
//    0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8,
//    0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed,
//    0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a,
//    0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c,
//    0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,
//    0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05,
//    0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665,
//    0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039,
//    0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1,
//    0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1,
//    0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391
//};
//
//inline unsigned int leftRotate(uint32_t x, uint32_t c) {
//    return (x << c) | (x >> (32 - c));
//}
//
//std::string md5(const std::string& message) {
//    uint32_t a0 = 0x67452301; // A
//    uint32_t b0 = 0xefcdab89; // B
//    uint32_t c0 = 0x98badcfe; // C
//    uint32_t d0 = 0x10325476; // D
//
//    uint32_t bitLen = message.length() * 8;
//    uint32_t paddingLen = (448 - (message.length() * 8 + 1) % 512) % 512;
//    uint32_t msgLen = message.length() + 1 + paddingLen / 8 + 8;
//    unsigned char* msg = new unsigned char[msgLen];
//    memset(msg, 0, msgLen);
//
//    memcpy(msg, message.c_str(), message.length());
//    msg[message.length()] = 0x80;
//    memcpy(msg + msgLen - 8, &bitLen, 8);
//
//    for (unsigned int i = 0; i < msgLen; i += 64)
//    {
//        uint32_t M[16];
//        memcpy(M, msg + i, 64);
//
//        uint32_t A = a0;
//        uint32_t B = b0;
//        uint32_t C = c0;
//        uint32_t D = d0;
//
//        for (unsigned int j = 0; j < 64; j++)
//        {
//            uint32_t F, g;
//            if (j < 16) {
//                F = (B & C) | ((~B) & D);
//                g = j;
//            }
//            else if (j < 32) {
//                F = (D & B) | ((~D) & C);
//                g = (5 * j + 1) % 16;
//            }
//            else if (j < 48) {
//                F = B ^ C ^ D;
//                g = (3 * j + 5) % 16;
//            }
//            else {
//                F = C ^ (B | (~D));
//                g = (7 * j) % 16;
//            }
//            F = F + A + K[j] + M[g];
//            A = D;
//            D = C;
//            C = B;
//            B += leftRotate(F, S[j]);
//        }
//        a0 += A;
//        b0 += B;
//        c0 += C;
//        d0 += D;
//    }
//    delete[] msg;
//    std::ostringstream oss;
//    oss << std::hex << std::setfill('0')
//        << std::setw(8) << a0 << std::setw(8) << b0 << std::setw(8) << c0 << std::setw(8) << d0;
//    return oss.str();
//}
void findLowestNumber(const char* secretKey) {
    int number = 1;
    MD5 md5;
    while (true) {
        std::string numberStr = std::to_string(number);
        size_t len1 = std::strlen(secretKey);
        
        char* combined = new char[len1 + numberStr.length() + 1];
        std::strcpy(combined, secretKey);
        std::strcat(combined, numberStr.c_str());
        char* hash = md5.digestString(combined);
        
        if (hash[0] == '0' && hash[1] == '0' && hash[2] == '0' && hash[3] == '0' && hash[4] == '0' && hash[5] == '0') {
            std::cout << "Lowest number: " << number << std::endl;
            break;
        }
        number++;
    }
}

int main()
{   
    
    MD5 md5;
    const char* inputString = "yzbqklnj";
    auto hash =  md5.digestString(const_cast<char*>(inputString));
    findLowestNumber(inputString);
}
