﻿/*******************************************************************************
 * Copyright (C) 2018 - 2020, winsoft666, <winsoft666@outlook.com>.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 *
 * Expect bugs
 *
 * Please use and enjoy. Please let me know of any bugs/improvements
 * that you have found/implemented and I will fix/incorporate them into this
 * file.
 *******************************************************************************/

#ifndef AKALI_DEPRECATION_H_
#define AKALI_DEPRECATION_H_

// Annotate the declarations of deprecated functions with this to cause a compiler warning when
// they're used. Like so:
//
//   AKALI_DEPRECATED std::pony PonyPlz(const std::pony_spec& ps);
//
// NOTE: The annotation goes on the declaration in the .h file, not the definition in the .cc/.cpp
// file!
//
// Remove this when we can use [[deprecated]] from C++14.
//
#if defined(_MSC_VER)
#define AKALI_DEPRECATED(message) __declspec(deprecated(message))
#elif defined(__GNUC__)
#define AKALI_DEPRECATED __attribute__((__deprecated__))
#else
#define AKALI_DEPRECATED
#endif

#endif  // AKALI_DEPRECATION_H_
