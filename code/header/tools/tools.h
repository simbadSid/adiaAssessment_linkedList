/**
 * @def tools
 * @details Contains all the snippets of code that are shared in the project.
 * @author Riyane
 * @date 26/09/2022
 */


#ifndef ADIAASSESSMENT_LINKEDLIST_TOOLS_H
#define ADIAASSESSMENT_LINKEDLIST_TOOLS_H

#include <cstdarg>
#include <stdio.h>


#ifdef LOG
    void log(const char *format, ...);
#else
    #define log(...) ((void)0)
#endif

void log_error(const char *format, ...);

#endif //ADIAASSESSMENT_LINKEDLIST_TOOLS_H
