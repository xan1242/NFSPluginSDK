// clang-format off
//
//    Copyright (C) 2022 Berkay Yigit <berkaytgy@gmail.com>
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
#include <OpenSpeed/Game.ProStreet/Types/bNode.h>

namespace OpenSpeed::ProStreet {
  struct bList {
    bNode HeadNode;

    bList() = default;
    ~bList() {}
  };

  template <class T>
  struct bTList {
    bTNode<T> HeadNode;

    bTList() = default;
    ~bTList() {}
  };

  template <class T>
  struct bPList : bTList<bPNode> {
    bPNode* AddHead(T*);
    bPNode* AddTail(T*);
    bPNode* AddBefore(bNode*, T*);
    bPNode* AddAfter(bNode*, T*);

    bPList() = default;
    ~bPList() {}
  };
}  // namespace OpenSpeed::ProStreet