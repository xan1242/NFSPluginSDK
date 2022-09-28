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

#ifndef EASTL_STRING_MAP_H
#define EASTL_STRING_MAP_H

#if defined(EA_PRAGMA_ONCE_SUPPORTED)
	#pragma once 
#endif

#include <NFSPluginSDK/Core/EASTL/EASTL/map.h>
#include <NFSPluginSDK/Core/EASTL/EASTL/string.h>

namespace eastl
{


template<typename T, typename Predicate = str_less<const char*>, typename Allocator = EASTLAllocatorType>
class string_map : public eastl::map<const char*, T, Predicate, Allocator>
{
public:
	typedef eastl::map<const char*, T, Predicate, Allocator> base;
	typedef string_map<T, Predicate, Allocator>              this_type;
	typedef typename base::base_type::allocator_type         allocator_type;
	typedef typename base::base_type::insert_return_type     insert_return_type;
	typedef typename base::base_type::iterator               iterator;
	typedef typename base::base_type::reverse_iterator       reverse_iterator;
	typedef typename base::base_type::const_iterator         const_iterator;
	typedef typename base::base_type::size_type              size_type;
	typedef typename base::base_type::key_type               key_type;
	typedef typename base::base_type::value_type             value_type;
	typedef typename base::mapped_type                       mapped_type;

		                string_map(const allocator_type& allocator = allocator_type()) : base(allocator) {}
						string_map(const string_map& src, const allocator_type& allocator = allocator_type());
						~string_map();
	void				clear();
	
	this_type&			operator=(const this_type& x);

	insert_return_type	insert(const char* key, const T& value);
	insert_return_type	insert(const char* key);
	iterator			erase(iterator position);
	size_type			erase(const char* key);
	mapped_type&		operator[](const char* key);

private:
	char*				strduplicate(const char* str);

	// Not implemented right now
	// insert_return_type	insert(const value_type& value);
	// iterator			    insert(iterator position, const value_type& value);
    // reverse_iterator	    erase(reverse_iterator position);
    // reverse_iterator	    erase(reverse_iterator first, reverse_iterator last);
    // void				    erase(const key_type* first, const key_type* last);
};



template<typename T, typename Predicate, typename Allocator>
string_map<T, Predicate, Allocator>::string_map(const string_map& src, const allocator_type& allocator) : base(allocator)
{
	for (const_iterator i=src.begin(), e=src.end(); i!=e; ++i)
		base::base_type::insert(eastl::make_pair(strduplicate(i->first), i->second));
}

template<typename T, typename Predicate, typename Allocator>
string_map<T, Predicate, Allocator>::~string_map()
{
	clear();
}

template<typename T, typename Predicate, typename Allocator>
void
string_map<T, Predicate, Allocator>::clear()
{
	allocator_type& allocator = base::base_type::get_allocator();
	for (const_iterator i=base::base_type::begin(), e=base::base_type::end(); i!=e; ++i)
		allocator.deallocate((void*)i->first, 0);
	base::base_type::clear();
}

template<typename T, typename Predicate, typename Allocator>
typename string_map<T, Predicate, Allocator>::this_type&
string_map<T, Predicate, Allocator>::operator=(const this_type& x)
{
	allocator_type allocator = base::base_type::get_allocator();
	this->~this_type();
	new (this) this_type(x, allocator);
	return *this;
}

template<typename T, typename Predicate, typename Allocator>
typename string_map<T, Predicate, Allocator>::insert_return_type
string_map<T, Predicate, Allocator>::insert(const char* key)
{
	return insert(key, mapped_type());
}

template<typename T, typename Predicate, typename Allocator>
typename string_map<T, Predicate, Allocator>::insert_return_type
string_map<T, Predicate, Allocator>::insert(const char* key, const T& value)
{
	EASTL_ASSERT(key);
	iterator i = base::base_type::find(key);
	if (i != base::base_type::end())
	{
		insert_return_type ret;
		ret.first = i;
		ret.second = false;
		return ret;
	}
	return base::base_type::insert(eastl::make_pair(strduplicate(key), value));
}

template<typename T, typename Predicate, typename Allocator>
typename string_map<T, Predicate, Allocator>::iterator
string_map<T, Predicate, Allocator>::erase(iterator position)
{
	const char* key = position->first;
	iterator result = base::base_type::erase(position);
	base::base_type::get_allocator().deallocate((void*)key, 0);
	return result;
}

template<typename T, typename Predicate, typename Allocator>
typename string_map<T, Predicate, Allocator>::size_type
string_map<T, Predicate, Allocator>::erase(const char* key)
{
	const iterator it(base::base_type::find(key));

    if(it != base::base_type::end())
    {
        erase(it);
        return 1;
    }
    return 0;
}

template<typename T, typename Predicate, typename Allocator>
typename string_map<T, Predicate, Allocator>::mapped_type&
string_map<T, Predicate, Allocator>::operator[](const char* key)
{
	using base_value_type = typename base::base_type::value_type;

	EASTL_ASSERT(key);
	iterator i = base::base_type::find(key);
	if (i != base::base_type::end())
		return i->second;
	return base::base_type::insert(base_value_type(pair_first_construct, strduplicate(key))).first->second;
}

template<typename T, typename Predicate, typename Allocator>
char*
string_map<T, Predicate, Allocator>::strduplicate(const char* str)
{
	size_t len = strlen(str);
	char* result = (char*)base::base_type::get_allocator().allocate(len + 1);
	memcpy(result, str, len+1);
	return result;
}


}

#endif
