// 
// Copyright (c) 2005-2008 Kenichi Watanabe.
// Copyright (c) 2005-2008 Yasuhiro Watari.
// Copyright (c) 2005-2008 Hironori Ichibayashi.
// Copyright (c) 2008-2009 Kazuo Horio.
// Copyright (c) 2009-2015 Naruki Kurata.
// Copyright (c) 2005-2015 Ryota Shioya.
// Copyright (c) 2005-2015 Masahiro Goshima.
// 
// This software is provided 'as-is', without any express or implied
// warranty. In no event will the authors be held liable for any damages
// arising from the use of this software.
// 
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it
// freely, subject to the following restrictions:
// 
// 1. The origin of this software must not be misrepresented; you must not
// claim that you wrote the original software. If you use this software
// in a product, an acknowledgment in the product documentation would be
// appreciated but is not required.
// 
// 2. Altered source versions must be plainly marked as such, and must not be
// misrepresented as being the original software.
// 
// 3. This notice may not be removed or altered from any source
// distribution.
// 
// 


#ifndef SIM_PIPELINE_SCHEDULER_RESCHEDULE_EVENT_H
#define SIM_PIPELINE_SCHEDULER_RESCHEDULE_EVENT_H

#include "Sim/Foundation/Event/EventBase.h"
#include "Sim/Op/OpArray/OpArray.h"

namespace Onikiri 
{

    // レイテンシ予測を行った結果、書き込みポートの確保ができないと予測され
    // 後続の命令(consumer)を wake up しない場合に、レイテンシ予測を行った
    // 命令(producer)を再度発行してポートの確保、consumer の wake up を行う
    // ためのイベント
    // 一般のデータ予測ミスでは使用しないこと
    class OpRescheduleEvent : public EventBase<OpRescheduleEvent>
    {
    public:
        OpRescheduleEvent( const OpIterator& op );
        virtual void Update();
    private:
        OpIterator m_op;
    };

}; // namespace Onikiri

#endif // SIM_PIPELINE_SCHEDULER_RESCHEDULE_EVENT_H

