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

#ifndef EASTL_ATOMIC_INTERNAL_COMPILER_MSVC_FETCH_XOR_H
#define EASTL_ATOMIC_INTERNAL_COMPILER_MSVC_FETCH_XOR_H

#if defined(EA_PRAGMA_ONCE_SUPPORTED)
	#pragma once
#endif


#if defined(EA_PROCESSOR_X86_64)

	#define EASTL_MSVC_ATOMIC_FETCH_XOR_INTRIN_8 _InterlockedXor8_np
	#define EASTL_MSVC_ATOMIC_FETCH_XOR_INTRIN_16 _InterlockedXor16_np
	#define EASTL_MSVC_ATOMIC_FETCH_XOR_INTRIN_32 _InterlockedXor_np
	#define EASTL_MSVC_ATOMIC_FETCH_XOR_INTRIN_64 _InterlockedXor64_np

#else

	#define EASTL_MSVC_ATOMIC_FETCH_XOR_INTRIN_8 _InterlockedXor8
	#define EASTL_MSVC_ATOMIC_FETCH_XOR_INTRIN_16 _InterlockedXor16
	#define EASTL_MSVC_ATOMIC_FETCH_XOR_INTRIN_32 _InterlockedXor
	#define EASTL_MSVC_ATOMIC_FETCH_XOR_INTRIN_64 _InterlockedXor64

#endif


#define EASTL_MSVC_ATOMIC_FETCH_XOR_N(integralType, xorIntrinsic, type, ret, ptr, val, MemoryOrder) \
	EASTL_MSVC_ATOMIC_FETCH_OP_N(integralType, xorIntrinsic, type, ret, ptr, val, MemoryOrder, \
								 EASTL_MSVC_NOP_PRE_INTRIN_COMPUTE)


#define EASTL_MSVC_ATOMIC_FETCH_XOR_8(type, ret, ptr, val, MemoryOrder)	\
	EASTL_MSVC_ATOMIC_FETCH_XOR_N(char, EASTL_MSVC_ATOMIC_FETCH_XOR_INTRIN_8, type, ret, ptr, val, MemoryOrder)

#define EASTL_MSVC_ATOMIC_FETCH_XOR_16(type, ret, ptr, val, MemoryOrder) \
	EASTL_MSVC_ATOMIC_FETCH_XOR_N(short, EASTL_MSVC_ATOMIC_FETCH_XOR_INTRIN_16, type, ret, ptr, val, MemoryOrder)

#define EASTL_MSVC_ATOMIC_FETCH_XOR_32(type, ret, ptr, val, MemoryOrder) \
	EASTL_MSVC_ATOMIC_FETCH_XOR_N(long, EASTL_MSVC_ATOMIC_FETCH_XOR_INTRIN_32, type, ret, ptr, val, MemoryOrder)

#define EASTL_MSVC_ATOMIC_FETCH_XOR_64(type, ret, ptr, val, MemoryOrder) \
	EASTL_MSVC_ATOMIC_FETCH_XOR_N(__int64, EASTL_MSVC_ATOMIC_FETCH_XOR_INTRIN_64, type, ret, ptr, val, MemoryOrder)


/////////////////////////////////////////////////////////////////////////////////
//
// void EASTL_COMPILER_ATOMIC_FETCH_XOR_*_N(type, type ret, type * ptr, type val)
//
#define EASTL_COMPILER_ATOMIC_FETCH_XOR_RELAXED_8(type, ret, ptr, val)	\
	EASTL_MSVC_ATOMIC_FETCH_XOR_8(type, ret, ptr, val, RELAXED)

#define EASTL_COMPILER_ATOMIC_FETCH_XOR_RELAXED_16(type, ret, ptr, val)	\
	EASTL_MSVC_ATOMIC_FETCH_XOR_16(type, ret, ptr, val, RELAXED)

#define EASTL_COMPILER_ATOMIC_FETCH_XOR_RELAXED_32(type, ret, ptr, val)	\
	EASTL_MSVC_ATOMIC_FETCH_XOR_32(type, ret, ptr, val, RELAXED)

#define EASTL_COMPILER_ATOMIC_FETCH_XOR_RELAXED_64(type, ret, ptr, val)	\
	EASTL_MSVC_ATOMIC_FETCH_XOR_64(type, ret, ptr, val, RELAXED)


#define EASTL_COMPILER_ATOMIC_FETCH_XOR_ACQUIRE_8(type, ret, ptr, val)	\
	EASTL_MSVC_ATOMIC_FETCH_XOR_8(type, ret, ptr, val, ACQUIRE)

#define EASTL_COMPILER_ATOMIC_FETCH_XOR_ACQUIRE_16(type, ret, ptr, val)	\
	EASTL_MSVC_ATOMIC_FETCH_XOR_16(type, ret, ptr, val, ACQUIRE)

#define EASTL_COMPILER_ATOMIC_FETCH_XOR_ACQUIRE_32(type, ret, ptr, val)	\
	EASTL_MSVC_ATOMIC_FETCH_XOR_32(type, ret, ptr, val, ACQUIRE)

#define EASTL_COMPILER_ATOMIC_FETCH_XOR_ACQUIRE_64(type, ret, ptr, val)	\
	EASTL_MSVC_ATOMIC_FETCH_XOR_64(type, ret, ptr, val, ACQUIRE)


#define EASTL_COMPILER_ATOMIC_FETCH_XOR_RELEASE_8(type, ret, ptr, val)	\
	EASTL_MSVC_ATOMIC_FETCH_XOR_8(type, ret, ptr, val, RELEASE)

#define EASTL_COMPILER_ATOMIC_FETCH_XOR_RELEASE_16(type, ret, ptr, val)	\
	EASTL_MSVC_ATOMIC_FETCH_XOR_16(type, ret, ptr, val, RELEASE)

#define EASTL_COMPILER_ATOMIC_FETCH_XOR_RELEASE_32(type, ret, ptr, val)	\
	EASTL_MSVC_ATOMIC_FETCH_XOR_32(type, ret, ptr, val, RELEASE)

#define EASTL_COMPILER_ATOMIC_FETCH_XOR_RELEASE_64(type, ret, ptr, val)	\
	EASTL_MSVC_ATOMIC_FETCH_XOR_64(type, ret, ptr, val, RELEASE)


#define EASTL_COMPILER_ATOMIC_FETCH_XOR_ACQ_REL_8(type, ret, ptr, val)	\
	EASTL_MSVC_ATOMIC_FETCH_XOR_8(type, ret, ptr, val, ACQ_REL)

#define EASTL_COMPILER_ATOMIC_FETCH_XOR_ACQ_REL_16(type, ret, ptr, val)	\
	EASTL_MSVC_ATOMIC_FETCH_XOR_16(type, ret, ptr, val, ACQ_REL)

#define EASTL_COMPILER_ATOMIC_FETCH_XOR_ACQ_REL_32(type, ret, ptr, val)	\
	EASTL_MSVC_ATOMIC_FETCH_XOR_32(type, ret, ptr, val, ACQ_REL)

#define EASTL_COMPILER_ATOMIC_FETCH_XOR_ACQ_REL_64(type, ret, ptr, val)	\
	EASTL_MSVC_ATOMIC_FETCH_XOR_64(type, ret, ptr, val, ACQ_REL)


#define EASTL_COMPILER_ATOMIC_FETCH_XOR_SEQ_CST_8(type, ret, ptr, val)	\
	EASTL_MSVC_ATOMIC_FETCH_XOR_8(type, ret, ptr, val, SEQ_CST)

#define EASTL_COMPILER_ATOMIC_FETCH_XOR_SEQ_CST_16(type, ret, ptr, val)	\
	EASTL_MSVC_ATOMIC_FETCH_XOR_16(type, ret, ptr, val, SEQ_CST)

#define EASTL_COMPILER_ATOMIC_FETCH_XOR_SEQ_CST_32(type, ret, ptr, val)	\
	EASTL_MSVC_ATOMIC_FETCH_XOR_32(type, ret, ptr, val, SEQ_CST)

#define EASTL_COMPILER_ATOMIC_FETCH_XOR_SEQ_CST_64(type, ret, ptr, val)	\
	EASTL_MSVC_ATOMIC_FETCH_XOR_64(type, ret, ptr, val, SEQ_CST)


#endif /* EASTL_ATOMIC_INTERNAL_COMPILER_MSVC_FETCH_XOR_H */
