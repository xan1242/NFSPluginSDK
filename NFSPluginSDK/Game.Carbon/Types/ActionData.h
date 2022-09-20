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

#ifndef NFSPLUGINSDK_GAME_CARBON_TYPES_ACTIONDATA_H
#define NFSPLUGINSDK_GAME_CARBON_TYPES_ACTIONDATA_H
#pragma once

#include <NFSPluginSDK/Game.Carbon/Types.h>

namespace NFSPluginSDK::Carbon {
  struct ActionData {
    enum class ActionID : std::uint32_t {
      NULL_ACTION,
      GAMEACTION_STEERLEFT,
      GAMEACTION_STEERRIGHT,
      GAMEACTION_OVERSTEER,
      GAMEACTION_OVERSTEERLEFT,
      GAMEACTION_OVERSTEERRIGHT,
      GAMEACTION_TURNLEFT,
      GAMEACTION_TURNRIGHT,
      GAMEACTION_GAS,
      GAMEACTION_GAS_SLOTCAR,
      GAMEACTION_BRAKE,
      GAMEACTION_HANDBRAKE,
      GAMEACTION_GAMEBREAKER,
      GAMEACTION_SHIFTUP,
      GAMEACTION_SHIFTDOWN,
      GAMEACTION_SHIFTFIRST,
      GAMEACTION_SHIFTSECOND,
      GAMEACTION_SHIFTTHIRD,
      GAMEACTION_SHIFTFOURTH,
      GAMEACTION_SHIFTFIFTH,
      GAMEACTION_SHIFTSIXTH,
      GAMEACTION_SHIFTNEUTRAL,
      GAMEACTION_SHIFTREVERSE,
      GAMEACTION_NOS,
      GAMEACTION_RESET,
      GAMEACTION_HYDRAULICALL,
      GAMEACTION_HYDRAULICFRONT,
      GAMEACTION_HYDRAULICLEFT,
      GAMEACTION_HYDRAULICREAR,
      GAMEACTION_HYDRAULICRIGHT,
      GAMEACTION_CREWAGGRESSIVE,
      GAMEACTION_CREWDEFENSIVE,
      GAMEACTION_CREWDEFAULT,
      GAMEACTION_CREWSPEED,
      GAMEACTION_FORWARD,
      GAMEACTION_BACK,
      GAMEACTION_JUMP,
      GAMEACTION_DEBUGHUMAN1,
      GAMEACTION_DEBUGHUMAN2,
      GAMEACTION_DEBUGHUMAN3,
      GAMEACTION_DEBUGHUMAN4,
      GAMEACTION_CLUTCH,
      GAMEACTION_CLUTCH_KICK,
      CAMERAACTION_CHANGE,
      CAMERAACTION_DEBUG,
      CAMERAACTION_ENABLE_ICE,
      CAMERAACTION_LOOKBACK,
      CAMERAACTION_PULLBACK,
      CAMERAACTION_ROT_LEFT,
      CAMERAACTION_ROT_RIGHT,
      CAMERAACTION_360,
      FRONTENDACTION_UP,
      FRONTENDACTION_DOWN,
      FRONTENDACTION_LEFT,
      FRONTENDACTION_RIGHT,
      FRONTENDACTION_RUP,
      FRONTENDACTION_RDOWN,
      FRONTENDACTION_RLEFT,
      FRONTENDACTION_RRIGHT,
      FRONTENDACTION_ACCEPT,
      FRONTENDACTION_CANCEL,
      FRONTENDACTION_CANCEL_ALT,
      FRONTENDACTION_START,
      FRONTENDACTION_BUTTON0,
      FRONTENDACTION_BUTTON1,
      FRONTENDACTION_BUTTON2,
      FRONTENDACTION_BUTTON3,
      FRONTENDACTION_BUTTON4,
      FRONTENDACTION_BUTTON5,
      FRONTENDACTION_LTRIGGER,
      FRONTENDACTION_RTRIGGER,
      HUDACTION_PAUSEREQUEST,
      HUDACTION_MESSENGER,
      HUDACTION_RACE_NOW,
      HUDACTION_ENGAGE_EVENT,
      HUDACTION_PAD_LEFT,
      HUDACTION_PAD_DOWN,
      HUDACTION_PAD_RIGHT,
      HUDACTION_SKIPNIS,
      HUDACTION_NEXTSONG,
      VOIPACTION_PUSHTOTALK,
      DEBUGACTION_MOVE_UP,
      DEBUGACTION_MOVE_DOWN,
      DEBUGACTION_MOVE_LEFT,
      DEBUGACTION_MOVE_RIGHT,
      DEBUGACTION_MOVE_FORWARD,
      DEBUGACTION_MOVE_BACK,
      DEBUGACTION_MOVE_D_LEFT,
      DEBUGACTION_MOVE_D_RIGHT,
      DEBUGACTION_MOVE_D_FORWARD,
      DEBUGACTION_MOVE_D_BACK,
      DEBUGACTION_LOOK_UP,
      DEBUGACTION_LOOK_DOWN,
      DEBUGACTION_LOOK_LEFT,
      DEBUGACTION_LOOK_RIGHT,
      DEBUGACTION_LOOK_D_UP,
      DEBUGACTION_LOOK_D_DOWN,
      DEBUGACTION_LOOK_D_LEFT,
      DEBUGACTION_LOOK_D_RIGHT,
      DEBUGACTION_TURBO,
      DEBUGACTION_SUPER_TURBO,
      DEBUGACTION_DROPCAR,
      DEBUGACTION_TOGGLEAI,
      DEBUGACTION_TOGGLESIMSTEP,
      DEBUGACTION_SIMSTEP,
      DEBUGACTION_SCREENSHOT,
      DEBUGACTION_STOPRECORDPATH,
      DEBUGACTION_TOGGLECARCOLOUR,
      DEBUGACTION_TOGGLEDEMOCAMERAS,
      DEBUGACTION_ITERCAMERATARGET,
      ICE_ACTION_START,
      ICE_ACTION_SELECT,
      ICE_ACTION_SOUTH,
      ICE_ACTION_SOUTH_PRESS,
      ICE_ACTION_NORTH,
      ICE_ACTION_NORTH_PRESS,
      ICE_ACTION_WEST,
      ICE_ACTION_WEST_PRESS,
      ICE_ACTION_EAST,
      ICE_ACTION_EAST_PRESS,
      ICE_ACTION_DOWN,
      ICE_ACTION_DOWN_PRESS,
      ICE_ACTION_UP,
      ICE_ACTION_UP_PRESS,
      ICE_ACTION_LEFT,
      ICE_ACTION_LEFT_PRESS,
      ICE_ACTION_RIGHT,
      ICE_ACTION_RIGHT_PRESS,
      ICE_ACTION_L1,
      ICE_ACTION_L1_PRESS,
      ICE_ACTION_R1,
      ICE_ACTION_R1_PRESS,
      ICE_ACTION_L2,
      ICE_ACTION_L2_PRESS,
      ICE_ACTION_R2,
      ICE_ACTION_R2_PRESS,
      ICE_ACTION_L3,
      ICE_ACTION_L3_PRESS,
      ICE_ACTION_R3,
      ICE_ACTION_R3_RELEASE,
      ICE_ACTION_LEFTSTICK_LEFT,
      ICE_ACTION_LEFTSTICK_RIGHT,
      ICE_ACTION_LEFTSTICK_DOWN,
      ICE_ACTION_LEFTSTICK_UP,
      ICE_ACTION_RIGHTSTICK_LEFT,
      ICE_ACTION_RIGHTSTICK_RIGHT,
      ICE_ACTION_RIGHTSTICK_DOWN,
      ICE_ACTION_RIGHTSTICK_UP,
      ACTION_EXITAPPLICATION,
      ACTION_PLUGGED,
      ACTION_UNPLUGGED,
      ACTION_FLUSH
    };

    ActionID     mId;
    std::int32_t mSlot;
    float        mData;
  };
}  // namespace NFSPluginSDK::Carbon

#endif  // NFSPLUGINSDK_GAME_CARBON_TYPES_ACTIONDATA_H