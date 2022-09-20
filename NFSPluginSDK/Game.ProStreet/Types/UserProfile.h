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

#ifndef NFSPLUGINSDK_GAME_PROSTREET_TYPES_USERPROFILE_H
#define NFSPLUGINSDK_GAME_PROSTREET_TYPES_USERPROFILE_H
#pragma once

#include <NFSPluginSDK/Game.ProStreet/Types.h>
#include <NFSPluginSDK/Game.ProStreet/Types/FEPlayerCarDB.h>
#include <NFSPluginSDK/Game.ProStreet/Types/EA.h>
#include <NFSPluginSDK/Game.ProStreet/Types/Gameplay.h>
#include <NFSPluginSDK/Game.ProStreet/Types/Jukebox.h>
#include <NFSPluginSDK/Game.ProStreet/Types/OptionsSettings.h>
#include <NFSPluginSDK/Game.ProStreet/Types/RaceDaySettings.h>
#include <NFSPluginSDK/Game.ProStreet/Types/UTL/FixedVector.h>  // Jukebox typedef

namespace NFSPluginSDK::ProStreet {
  struct UserProfile : EA::Memcard::IMemcardSavable {
    char                 mName[32];
    Jukebox              mPlaylist;
    FEPlayerCarDB        mCarStable;
    OptionsSettings      mOptionsSettings;
    std::uint32_t        mNumRaceDaySaves;
    std::uint32_t        mNumRaceDaySavesTotal;
    Gameplay::GHubRecord mCurrentRaceDayConfig;
    RaceDaySettings      mRaceDaySettings;
    std::uint32_t        mOnlineXPLevel;

    static inline UserProfile (**spUserProfiles)[4] = reinterpret_cast<UserProfile (**)[4]>(0xAB0EAC);

    static UserProfile* Get(std::size_t idx = 0) {
      if (!spUserProfiles) return nullptr;
      return (*spUserProfiles)[idx];
    }
  };
}  // namespace NFSPluginSDK::ProStreet

#endif  // NFSPLUGINSDK_GAME_PROSTREET_TYPES_USERPROFILE_H