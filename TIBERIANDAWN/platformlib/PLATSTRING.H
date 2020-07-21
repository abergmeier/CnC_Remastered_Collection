
#ifndef TD_PLATSTRING_H
#define TD_PLATSTRING_H

#ifndef _MSC_VER

#include <cctype>

#define stricmp strcasecmp

char* strupr(char* s)
{
    char* tmp = s;

    for (;*tmp;++tmp) {
        *tmp = static_cast<char>(std::toupper(static_cast<unsigned char>(*tmp)));
    }

    return s;
}
#endif //_MSC_VER

#endif //TD_PLATSTRING_H
