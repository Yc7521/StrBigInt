#pragma once

//#define STRNUMEXE

#ifdef STRNUMEXE
#include <algorithm>
#include <iomanip>
#include <sstream>
#include <stdio.h>
#include <string>
#include <vector>
#include <Windows.h>
#endif // STRNUMEXE
#include <tchar.h>
#include <iostream>

#include "targetver.h"
#ifndef STRBIGNUM
#include "bignum.h"
#endif // !STRBIGNUM

using namespace std;

#ifdef UNICODE
BDLLEXPIMPORT wistream &operator >>(wistream &is, bignum &num);
BDLLEXPIMPORT wostream &operator <<(wostream &os, bignum &num);
BDLLEXPIMPORT wistream &operator >>(wistream &is, bignum &&num);
BDLLEXPIMPORT wostream &operator <<(wostream &os, bignum &&num);
#else
BDLLEXPIMPORT istream &operator >>(istream &is, bignum &num);
BDLLEXPIMPORT ostream &operator <<(ostream &os, bignum &num);
BDLLEXPIMPORT istream &operator >>(istream &is, bignum &&num);
BDLLEXPIMPORT ostream &operator <<(ostream &os, bignum &&num);
#endif // UNICODE

#ifdef LINKLIB

#if !defined(_68K_) && !defined(_MPPC_) && !defined(_X86_) && !defined(_IA64_) && !defined(_AMD64_) && !defined(_ARM_) && !defined(_ARM64_) && defined(_M_IX86)
#define _X86_
#if !defined(_CHPE_X86_ARM64_) && defined(_M_HYBRID)
#define _CHPE_X86_ARM64_
#endif
#endif

#if !defined(_68K_) && !defined(_MPPC_) && !defined(_X86_) && !defined(_IA64_) && !defined(_AMD64_) && !defined(_ARM_) && !defined(_ARM64_) && defined(_M_AMD64)
#define _AMD64_
#endif

#if !defined(_68K_) && !defined(_MPPC_) && !defined(_X86_) && !defined(_IA64_) && !defined(_AMD64_) && !defined(_ARM_) && !defined(_ARM64_) && defined(_M_ARM)
#define _ARM_
#endif

#if !defined(_68K_) && !defined(_MPPC_) && !defined(_X86_) && !defined(_IA64_) && !defined(_AMD64_) && !defined(_ARM_) && !defined(_ARM64_) && defined(_M_ARM64)
#define _ARM64_
#endif

#if !defined(_68K_) && !defined(_MPPC_) && !defined(_X86_) && !defined(_IA64_) && !defined(_AMD64_) && !defined(_ARM_) && !defined(_ARM64_) && defined(_M_M68K)
#define _68K_
#endif

#if !defined(_68K_) && !defined(_MPPC_) && !defined(_X86_) && !defined(_M_IX86) && !defined(_AMD64_) && !defined(_ARM_) && !defined(_ARM64_) && defined(_M_IA64)
#if !defined(_IA64_)
#define _IA64_
#endif /* !_IA64_ */
#endif

#if defined(_X86_) || defined(_ARM_) || defined(_68K_)
#define _32__
#else
#define _64__
#endif

#ifdef UNICODE
#if defined(_32__) && defined(_DEBUG)
#pragma comment(lib,".\\lib\\u_StrBigNum_d32.lib")
#elif defined(_32__) && !defined(_DEBUG)
#pragma comment(lib,".\\lib\\u_StrBigNum_r32.lib")
#elif defined(_64__) && defined(_DEBUG)
#pragma comment(lib,".\\lib\\u_StrBigNum_d64.lib")
#elif defined(_64__) && !defined(_DEBUG)
#pragma comment(lib,".\\lib\\u_StrBigNum_r64.lib")
#endif
#else
#if defined(_32__) && defined(_DEBUG)
#pragma comment(lib,".\\lib\\a_StrBigNum_d32.lib")
#elif defined(_32__) && !defined(_DEBUG)
#pragma comment(lib,".\\lib\\a_StrBigNum_r32.lib")
#elif defined(_64__) && defined(_DEBUG)
#pragma comment(lib,".\\lib\\a_StrBigNum_d64.lib")
#elif defined(_64__) && !defined(_DEBUG)
#pragma comment(lib,".\\lib\\a_StrBigNum_r64.lib")
#endif
#endif // UNICODE

#endif