#include "../../Game/Game.h"
#include "../../State/Location.h"
#include "../../VM/IFalloutStack.h"
#include "../../VM/Handler/Opcode8101.h"

namespace Falltergeist
{
    namespace VM
    {
        namespace Handler
        {
            void Opcode8101::applyTo(std::shared_ptr<IFalloutContext> context)
            {
                context->dataStack()->push(Game::getInstance()->locationState()->currentMapIndex());
            }

            int Opcode8101::number()
            {
                return 0x8101;
            }

            std::string Opcode8101::name()
            {
                return "int cur_map_index(void)";
            }

            std::string Opcode8101::notes()
            {
                return "";
            }
        }
    }
}