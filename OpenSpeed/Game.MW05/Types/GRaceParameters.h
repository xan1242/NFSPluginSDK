// clang-format off
//
//    Copyright (C) 2021 Berkay Yigit <berkaytgy@gmail.com>
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
#include <OpenSpeed/Game.MW05/Types.h>

namespace OpenSpeed::MW05 {
  struct GRaceParameters {
    GRaceIndexData*        mIndex;
    Attrib::Gen::gameplay* mRaceRecord;
    GVault*                mParentVault;
    GVault*                mChildVault;

    virtual void GetCheckpointPosition(std::uint32_t idx, UMath::Vector3& to);
    virtual void GetCheckpointDirection(std::uint32_t idx, UMath::Vector3& to);
    virtual ~GRaceParameters();
  };
}  // namespace OpenSpeed::MW05