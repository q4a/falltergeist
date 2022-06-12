// Project includes
#include "../../VM/Handler/Opcode8132Handler.h"
#include "../../Game/ContainerItemObject.h"
#include "../../Game/DoorSceneryObject.h"
#include "../../VM/Script.h"

// Third-party includes

// stdlib

namespace Falltergeist
{
    namespace VM
    {
        namespace Handler
        {
            Opcode8132::Opcode8132(std::shared_ptr<ILogger> logger) : OpcodeHandler(), _logger(logger)
            {

            }

            void Opcode8132::_run(VM::Script& script)
            {
                _logger->debug() << "[8132] [+] void obj_close(GameDoorSceneryObject* object) " << std::endl;
                auto object = script.dataStack()->popObject();
                if (!object) {
                    _error("obj_close: object is NULL");
                }
                // @TODO: need some refactoring to get rid of this ugly if-elses
                if (auto door = dynamic_cast<Game::DoorSceneryObject *>(object)) {
                    door->setOpened(false);
                } else if (auto container = dynamic_cast<Game::ContainerItemObject *>(object)) {
                    container->setOpened(false);
                } else {
                    _error("obj_close: object is not openable type!");
                }
            }
        }
    }
}


