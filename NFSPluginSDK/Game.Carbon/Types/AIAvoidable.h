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

#ifndef NFSPLUGINSDK_GAME_CARBON_TYPES_AIAVOIDABLE_H
#define NFSPLUGINSDK_GAME_CARBON_TYPES_AIAVOIDABLE_H
#pragma once

#include <NFSPluginSDK/Core/EASTL/EASTL/list.h>

#include <NFSPluginSDK/Game.Carbon/Types.h>
#include <NFSPluginSDK/Game.Carbon/Types/Grid.h>
#include <NFSPluginSDK/Game.Carbon/Types/UTL.h>

namespace NFSPluginSDK::Carbon {
  struct AIAvoidable {
    Grid<AIAvoidable>*        mGridNode;
    eastl::list<AIAvoidable*> mNeighbors;
    UTL::COM::IUnknown*       mUnk;

    virtual ~AIAvoidable();
    virtual bool OnUpdateAvoidable(UMath::Vector3& pos, float& sweep) = 0;

    inline const auto& GetAvoidableNeighbors() { return mNeighbors; }
    inline void        SetAvoidableObject(UTL::COM::IUnknown* obj) { mUnk = obj; }
  };
}  // namespace NFSPluginSDK::Carbon

#endif  // NFSPLUGINSDK_GAME_CARBON_TYPES_AIAVOIDABLE_H