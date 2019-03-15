#ifndef BIOSEQ_INCLUDES_BIOSEQ_H_
#define BIOSEQ_INCLUDES_BIOSEQ_H_

#if defined (_WIN32)
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#endif

#if defined (__unix__)
#include <unistd.h>
#else
#error "Unix not defined!"
#endif // OS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#endif // BIOSEQ_INCLUDES_BIOSEQ_H_
