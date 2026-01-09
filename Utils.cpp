#include "Utils.h"

std::string dataNaString(time_t czas) {
    char buffer[80];
    struct tm* timeinfo = localtime(&czas);
    strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", timeinfo);
    return std::string(buffer);
}