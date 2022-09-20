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

#ifndef NFSPLUGINSDK_GAME_MW05_TYPES_ATTRIB_CLASS_H
#define NFSPLUGINSDK_GAME_MW05_TYPES_ATTRIB_CLASS_H
#pragma once

#include <NFSPluginSDK/Game.MW05/Types.h>

namespace NFSPluginSDK::MW05::Attrib {
  struct Class {
    std::uint32_t mKey;
    std::uint32_t mRefCount;
    ClassPrivate& mPrivates;

    inline Definition* GetDefinition(std::uint32_t key) {
      return reinterpret_cast<Definition*(__thiscall*)(Class*, std::uint32_t)>(0x457380)(this, key);
    }
    inline std::uint32_t GetNumDefinitions() {
      return reinterpret_cast<std::uint32_t(__thiscall*)(Class*)>(0x451660)(this);
    }
    inline std::uint32_t GetFirstDefinition() {
      return reinterpret_cast<std::uint32_t(__thiscall*)(Class*)>(0x451670)(this);
    }
    inline std::uint32_t GetNextDefinition(std::uint32_t key) {
      return reinterpret_cast<std::uint32_t(__thiscall*)(Class*, std::uint32_t)>(0x4573C0)(this, key);
    }

    inline Collection* GetCollection(std::uint32_t key) {
      return reinterpret_cast<Collection*(__thiscall*)(Class*, std::uint32_t)>(0x455960)(this, key);
    }
    inline std::uint32_t GetNumCollections() {
      return reinterpret_cast<std::uint32_t(__thiscall*)(Class*)>(0x453FC0)(this);
    }
    inline std::uint32_t GetFirstCollection() {
      return reinterpret_cast<std::uint32_t(__thiscall*)(Class*)>(0x456B00)(this);
    }
    inline std::uint32_t GetNextCollection(std::uint32_t key) {
      return reinterpret_cast<std::uint32_t(__thiscall*)(Class*, std::uint32_t)>(0x456B20)(this, key);
    }
  };
}  // namespace NFSPluginSDK::MW05::Attrib

#endif  // NFSPLUGINSDK_GAME_MW05_TYPES_ATTRIB_CLASS_H