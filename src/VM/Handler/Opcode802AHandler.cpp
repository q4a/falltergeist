/*
 * Copyright 2012-2018 Falltergeist Developers.
 *
 * This file is part of Falltergeist.
 *
 * Falltergeist is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Falltergeist is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Falltergeist.  If not, see <http://www.gnu.org/licenses/>.
 */

// Related headers
#include "../../VM/Handler/Opcode802AHandler.h"

// C++ standard includes

// Falltergeist includes
#include "../../Logger.h"
#include "../../VM/Script.h"

// Third party includes

namespace Falltergeist
{
namespace VM
{
namespace Handler
{

Opcode802A::Opcode802A(std::shared_ptr<VM::Script> script) : OpcodeHandler(script) {
}

void Opcode802A::_run() {
    Logger::debug("SCRIPT") << "[802A] [*] op_pop_to_base" << std::endl;
    while (_script->dataStack()->size() > _script->DVARbase()) {
        _script->dataStack()->pop();
    }
}

}
}
}
