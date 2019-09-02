#include <iostream>
#include "MessagePublicService.h"
#include "MessagePublicDTO.h"
#include <sqlpp11/mysql/mysql.h>
#include <sqlpp11/sqlpp11.h>
#include <cassert>
#include <iostream>
#include <vector>
#include"MyTable.h"
#include "DBContextFactory.h"
namespace mysql=sqlpp::mysql;
//增添消息
bool MessagePublicService::Add(MessagePublicDTO messagePublicDTO)
{
    mysql::connection &db=DBContextFactory::Instance();
    const auto tab=PublicMessage{};
    db(insert_into(tab).set(
        tab.Context = messagePublicDTO.Context,
        tab.GroupID = messagePublicDTO.Group_ID,
        tab.SenderID = messagePublicDTO.Sender_ID,
        tab.MessageTime = messagePublicDTO.Time,
        tab.MessageType = messagePublicDTO.Type,
        tab.IsDelete = 0
    ));
}
		//删除消息（撤回？）
bool MessagePublicService::Del(MessagePublicDTO messagePublicDTO)
{
    mysql::connection &db=DBContextFactory::Instance();
    const auto tab=PublicMessage{};
    db(update(tab).set(tab.IsDelete=1).where(tab.IsDelete==1));
}
		//获取该群组里的消息列表，其中id是group的id，返回结果数
int MessagePublicService::GetMessagePublicList(vector<MessagePublicDTO>& messageList, 
				int sender_id, int group_id)
{
    mysql::connection &db=DBContextFactory::Instance();
    const auto tab=PublicMessage{};
    for (const auto& row:db(select(all_of(tab)).from(tab).where(tab.SenderID==sender_id
                            and tab.GroupID==group_id)))
    {
        MessagePublicDTO messagePublicDTO;
        messagePublicDTO.Context = row.Context;
        messagePublicDTO.Sender_ID = row.SenderID;
        messagePublicDTO.Group_ID = row.GroupID;
        messagePublicDTO.Time = row.MessageTime;
        messagePublicDTO.Type = row.MessageType;
        messageList.push_back(messagePublicDTO);
    }
    return messageList.size();
}