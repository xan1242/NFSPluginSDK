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

#ifndef NFSPLUGINSDK_GAME_CARBON_TYPES_EVENTSEQUENCER_H
#define NFSPLUGINSDK_GAME_CARBON_TYPES_EVENTSEQUENCER_H
#pragma once

#include <NFSPluginSDK/Game.Carbon/Types.h>
#include <NFSPluginSDK/Game.Carbon/Types/UTL.h>

namespace NFSPluginSDK::Carbon {
  struct EventSequencer {
    struct System;
    struct IEngine;
    struct IContext {
      virtual UTL::COM::IUnknown* GetContextOwner()                                          = 0;
      virtual bool                GetDynamicData(System* system, void* pOutEventDynamicData) = 0;
      virtual const char*         GetContextDebugName()                                      = 0;
      virtual ~IContext();
      virtual void __null_sub__() = 0;
    };
  };
}  // namespace NFSPluginSDK::Carbon

#endif  // NFSPLUGINSDK_GAME_CARBON_TYPES_EVENTSEQUENCER_H