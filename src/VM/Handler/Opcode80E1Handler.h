#pragma once

#include "../../ILogger.h"
#include "../../VM/OpcodeHandler.h"

namespace Falltergeist
{
    namespace VM
    {
        namespace Handler
        {
            class Opcode80E1 : public OpcodeHandler
            {
                public:
                    Opcode80E1(VM::Script *script, std::shared_ptr<ILogger> logger);

                private:
                    std::shared_ptr<ILogger> logger;
                    void _run() override;
            };
        }
    }
}
