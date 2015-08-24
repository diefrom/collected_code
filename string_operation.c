#include <string.h>
#include "string_operation.h"

int clr_space(char *word)
{
    char *pbeg;
    char *pend;
    size_t len;

    if (NULL == word)
        return UNDEFINED_ERROR;
    if ('\0' == *word)
        return SUCCESS;
    len = strlen(word);

    pbeg = word;
    while ((' ' == *pbeg) || ('\r' == *pbeg) || ('\t' == *pbeg) || ('\n' == *pbeg))
        pbeg++;

    pend = word + len - 1;
    while ((' ' == *pend) || ('\r' == *pend) || ('\t' == *pend) || ('\n' == *pend)) {
        pend--;
        if (pend < pbeg) {
            *word = '\0';
            return SUCCESS;
        }
    }

    if (pend + 1 <= word + (len - 1)) 
        pend[1] = '\0';

    if (pend != word)
        memmove(word, pbeg, pend-pbeg+2);

    return SUCCESS;
}
