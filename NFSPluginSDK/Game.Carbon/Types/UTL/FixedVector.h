// clang-format off
//
//    Copyright (C) 2022 Berkay Yigit <mail@berkay.link>
//
//    This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU Affero General Public License as published
//    by the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
//    GNU Affero General Public License for more details.
//
//    You should have received a copy of the GNU Affero General Public License
//    along with this program. If not, see <https://www.gnu.org/licenses/>.
//
// clang-format on

#ifndef NFSPLUGINSDK_GAME_CARBON_TYPES_UTL_FIXEDVECTOR_H
#define NFSPLUGINSDK_GAME_CARBON_TYPES_UTL_FIXEDVECTOR_H
#pragma once

#include <NFSPluginSDK/Game.Carbon/Types.h>
#include <NFSPluginSDK/Game.Carbon/Types/UTL/Vector.h>

namespace NFSPluginSDK::Carbon::UTL {
  template <typename T, std::size_t nT, std::size_t VectorCapacity>
  struct FixedVector : Vector<T, VectorCapacity> {
    T mVectorSpace[nT];

    virtual ~FixedVector() {}
    virtual T*          AllocVectorSpace() { return mVectorSpace; }
    virtual void        FreeVectorSpace() { std::memset(mVectorSpace, 0, sizeof(T) * nT); }
    virtual std::size_t GetGrowSize() { return nT; }
    virtual std::size_t GetMaxCapacity() { return nT; }
    virtual void        OnGrowRequest() {}

    FixedVector() : Vector<T, nT>() { this->mBegin = mVectorSpace; }
  };
}  // namespace NFSPluginSDK::Carbon::UTL

#endif  // NFSPLUGINSDK_GAME_CARBON_TYPES_UTL_FIXEDVECTOR_H