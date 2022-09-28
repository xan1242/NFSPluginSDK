// clang-format off
//
//  BSD 3-Clause License
//  
//  Copyright (c) 2019, Electronic Arts
//  All rights reserved.
//  
//  Redistribution and use in source and binary forms, with or without
//  modification, are permitted provided that the following conditions are met:
//  
//  1. Redistributions of source code must retain the above copyright notice, this
//     list of conditions and the following disclaimer.
//  
//  2. Redistributions in binary form must reproduce the above copyright notice,
//     this list of conditions and the following disclaimer in the documentation
//     and/or other materials provided with the distribution.
//  
//  3. Neither the name of the copyright holder nor the names of its
//     contributors may be used to endorse or promote products derived from
//     this software without specific prior written permission.
//  
//  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
//  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
//  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
//  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
//  FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
//  DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
//  SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
//  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
//  OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
//  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// clang-format on

#ifndef EASTL_ATOMIC_INTERNAL_COMPILER_GCC_STORE_H
#define EASTL_ATOMIC_INTERNAL_COMPILER_GCC_STORE_H

#if defined(EA_PRAGMA_ONCE_SUPPORTED)
	#pragma once
#endif


#define EASTL_GCC_ATOMIC_STORE_N(integralType, ptr, val, gccMemoryOrder) \
	{																	 \
		integralType valIntegral = EASTL_ATOMIC_TYPE_PUN_CAST(integralType, (val)); \
		__atomic_store(EASTL_ATOMIC_VOLATILE_INTEGRAL_CAST(integralType, (ptr)), &valIntegral, gccMemoryOrder); \
	}


#define EASTL_GCC_ATOMIC_STORE_8(ptr, val, gccMemoryOrder)		\
	EASTL_GCC_ATOMIC_STORE_N(uint8_t, ptr, val, gccMemoryOrder)

#define EASTL_GCC_ATOMIC_STORE_16(ptr, val, gccMemoryOrder)		\
	EASTL_GCC_ATOMIC_STORE_N(uint16_t, ptr, val, gccMemoryOrder)

#define EASTL_GCC_ATOMIC_STORE_32(ptr, val, gccMemoryOrder)		\
	EASTL_GCC_ATOMIC_STORE_N(uint32_t, ptr, val, gccMemoryOrder)

#define EASTL_GCC_ATOMIC_STORE_64(ptr, val, gccMemoryOrder)		\
	EASTL_GCC_ATOMIC_STORE_N(uint64_t, ptr, val, gccMemoryOrder)

#define EASTL_GCC_ATOMIC_STORE_128(ptr, val, gccMemoryOrder)	\
	EASTL_GCC_ATOMIC_STORE_N(__uint128_t, ptr, val, gccMemoryOrder)


/////////////////////////////////////////////////////////////////////////////////
//
// void EASTL_COMPILER_ATOMIC_STORE_*_N(type, type * ptr, type val)
//
#define EASTL_COMPILER_ATOMIC_STORE_RELAXED_8(type, ptr, val)	\
	EASTL_GCC_ATOMIC_STORE_8(ptr, val, __ATOMIC_RELAXED)

#define EASTL_COMPILER_ATOMIC_STORE_RELAXED_16(type, ptr, val)	\
	EASTL_GCC_ATOMIC_STORE_16(ptr, val, __ATOMIC_RELAXED)

#define EASTL_COMPILER_ATOMIC_STORE_RELAXED_32(type, ptr, val)	\
	EASTL_GCC_ATOMIC_STORE_32(ptr, val, __ATOMIC_RELAXED)

#define EASTL_COMPILER_ATOMIC_STORE_RELAXED_64(type, ptr, val)	\
	EASTL_GCC_ATOMIC_STORE_64(ptr, val, __ATOMIC_RELAXED)

#define EASTL_COMPILER_ATOMIC_STORE_RELAXED_128(type, ptr, val)	\
	EASTL_GCC_ATOMIC_STORE_128(ptr, val, __ATOMIC_RELAXED)


#define EASTL_COMPILER_ATOMIC_STORE_RELEASE_8(type, ptr, val)	\
	EASTL_GCC_ATOMIC_STORE_8(ptr, val, __ATOMIC_RELEASE)

#define EASTL_COMPILER_ATOMIC_STORE_RELEASE_16(type, ptr, val)	\
	EASTL_GCC_ATOMIC_STORE_16(ptr, val, __ATOMIC_RELEASE)

#define EASTL_COMPILER_ATOMIC_STORE_RELEASE_32(type, ptr, val)	\
	EASTL_GCC_ATOMIC_STORE_32(ptr, val, __ATOMIC_RELEASE)

#define EASTL_COMPILER_ATOMIC_STORE_RELEASE_64(type, ptr, val)	\
	EASTL_GCC_ATOMIC_STORE_64(ptr, val, __ATOMIC_RELEASE)

#define EASTL_COMPILER_ATOMIC_STORE_RELEASE_128(type, ptr, val)	\
	EASTL_GCC_ATOMIC_STORE_128(ptr, val, __ATOMIC_RELEASE)


#define EASTL_COMPILER_ATOMIC_STORE_SEQ_CST_8(type, ptr, val)	\
	EASTL_GCC_ATOMIC_STORE_8(ptr, val, __ATOMIC_SEQ_CST)

#define EASTL_COMPILER_ATOMIC_STORE_SEQ_CST_16(type, ptr, val)	\
	EASTL_GCC_ATOMIC_STORE_16(ptr, val, __ATOMIC_SEQ_CST)

#define EASTL_COMPILER_ATOMIC_STORE_SEQ_CST_32(type, ptr, val)	\
	EASTL_GCC_ATOMIC_STORE_32(ptr, val, __ATOMIC_SEQ_CST)

#define EASTL_COMPILER_ATOMIC_STORE_SEQ_CST_64(type, ptr, val)	\
	EASTL_GCC_ATOMIC_STORE_64(ptr, val, __ATOMIC_SEQ_CST)

#define EASTL_COMPILER_ATOMIC_STORE_SEQ_CST_128(type, ptr, val)	\
	EASTL_GCC_ATOMIC_STORE_128(ptr, val, __ATOMIC_SEQ_CST)


#endif /* EASTL_ATOMIC_INTERNAL_COMPILER_GCC_STORE_H */
