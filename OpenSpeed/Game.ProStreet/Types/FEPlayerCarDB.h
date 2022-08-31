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

#pragma once
#include <OpenSpeed/Game.ProStreet/Types.h>
#include <OpenSpeed/Game.ProStreet/Types/FECareerRecord.h>
#include <OpenSpeed/Game.ProStreet/Types/FECarPartRecord.h>
#include <OpenSpeed/Game.ProStreet/Types/FECarRecord.h>
#include <OpenSpeed/Game.ProStreet/Types/FECustomizationRecord.h>
#include <OpenSpeed/Game.ProStreet/Types/FEInfractionsData.h>
#include <OpenSpeed/Game.ProStreet/Types/FELinkedPool.h>
#include <OpenSpeed/Game.ProStreet/Types/FEVinylRecord.h>

namespace OpenSpeed::ProStreet {
  struct FEPlayerCarDB {
    FECarRecord                                                                 CarTable[410];
    FECustomizationRecord                                                       Customizations[80];
    FECareerRecord                                                              CareerRecords[80];
    FELinkedPool<FECarPartRecord, std::uint16_t, std::uint16_t, 9500 /*14000*/> CarParts;
    FELinkedPool<FEVinylRecord, std::uint16_t, std::uint16_t, 700 /*760*/>      Vinyls;
    std::uint32_t                                                               SoldHistoryBounty;
    std::uint16_t                                                               SoldHistoryNumEvadedPursuits;
    std::uint16_t                                                               SoldHistoryNumBustedPursuits;
    FEInfractionsData                                                           SoldHistoryUnservedInfractions;
    FEInfractionsData                                                           SoldHistoryServedInfractions;
    unsigned char                                                               __pad[0x4768];
    std::uint32_t                                                               LastAwardedKingCarHistoryCarHandle;
    BluePrintType                                                               LastAwardedKingCarHistoryCarMode;
    std::int8_t                                                                 mInitializingCarStable;

    FECarRecord* GetCarRecordByHandle(std::uint32_t handle) {
      return reinterpret_cast<FECarRecord*(__thiscall*)(FEPlayerCarDB*, std::uint32_t)>(0x5332F0)(this, handle);
    }
    FECarRecord* GetCarByIndex(std::uint32_t idx) {
      return reinterpret_cast<FECarRecord*(__thiscall*)(FEPlayerCarDB*, std::uint32_t)>(0x5333B0)(this, idx);
    }
  };
}  // namespace OpenSpeed::ProStreet