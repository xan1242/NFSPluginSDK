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
#include <OpenSpeed/Core/EASTL/EASTL/map.h>

#include <OpenSpeed/Game.ProStreet/Types.h>
#include <OpenSpeed/Game.ProStreet/Types/Attrib/RefSpec.h>
#include <OpenSpeed/Game.ProStreet/Types/FECarRecord.h>
#include <OpenSpeed/Game.ProStreet/Types/ISelectablePart.h>
#include <OpenSpeed/Game.ProStreet/Types/Physics.h>

namespace OpenSpeed::ProStreet {
  struct TuningSelectablePart : ISelectablePart {
    enum class SliderType : std::uint32_t { Suspension, Engine, Drivetrain, Brakes };

    eastl::map<Attrib::RefSpec, Physics::Upgrades::Tuning, eastl::less<Attrib::RefSpec>> mTuningRanges;
    unsigned char                                                                        _mapPad1[4];
    eastl::map<Attrib::RefSpec, float, eastl::less<Attrib::RefSpec>>                     mTuningValues;
    unsigned char                                                                        _mapPad2[4];
    float                                                                                mRideHeight;
    FECarRecord*                                                                         mCarRecord;
    BluePrintNumber                                                                      mBlueprintNumber;
  };
}  // namespace OpenSpeed::ProStreet
