#include <iostream>
#include "MessagePrivateService.h"
#include "MessagePrivateDTO.h"
#include <sqlpp11/mysql/mysql.h>
#include <sqlpp11/sqlpp11.h>
#include <cassert>
#include <iostream>
#include <vector>
#include"MyTable.h"
#include "DBContextFactory.h"
namespace mysql=sqlpp::mysql;
//增添消息
bool MessagePrivateService::Add(MessagePrivateDTO messagePrivateDTO)
{
    mysql::connection &db=DBContextFactory::Instance();
    const auto tab=PrivateMessage{};
    db(insert_into(tab).set(
        tab.Context = messagePrivateDTO.Context,
        tab.RecverID = messagePrivateDTO.Recver_ID,
        tab.SenderID = messagePrivateDTO.Sender_ID,
        tab.MessageTime = messagePrivateDTO.Time,
        tab.MessageType = messagePrivateDTO.Type,
        tab.IsDelete = 0
    ));
}
		//删除消息（撤回？）
bool MessagePrivateService::Del(MessagePrivateDTO messagePrivateDTO)
{
    mysql::connection &db=DBContextFactory::Instance();
    const auto tab=PrivateMessage{};
    db(update(tab).set(tab.IsDelete=1).where(tab.IsDelete==1));
}
		//获取该群组里的消息列表，其中id是group的id，返回结果数
int MessagePrivateService::GetMessagePrivateList(vector<MessagePrivateDTO>& messageList, 
				int sender_id, int recv_id)
{
    mysql::connection &db=DBContextFactory::Instance();
    const auto tab=PrivateMessage{};
    for (const auto& row:db(select(all_of(tab)).from(tab).where(tab.SenderID==sender_id
                            and tab.RecverID==recv_id)))
    {
        MessagePrivateDTO messagePrivateDTO;
        messagePrivateDTO.Context = row.Context;
        messagePrivateDTO.Sender_ID = row.SenderID;
        messagePrivateDTO.Recver_ID = row.RecverID;
        messagePrivateDTO.Time = row.MessageTime;
        messagePrivateDTO.Type = row.MessageType;
        messageList.push_back(messagePrivateDTO);
    }
    return messageList.size();
}