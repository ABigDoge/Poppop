#include <iostream>
#include "MessageService.h"
#include "MessageDTO.h"
#include <sqlpp11/mysql/mysql.h>
#include <sqlpp11/sqlpp11.h>
#include <cassert>
#include <iostream>
#include <vector>
#include"MyTable.h"
namespace mysql=sqlpp::mysql;
//增添消息
bool MessageService::Add(MessageDTO messageDTO, mysql::connection db){
    const auto tab=_Message{};
    db(insert_into(tab).set(
        tab.SenderID=messageDTO.Sender_ID,
        tab.Context=messageDTO.Context,
        tab.GroupID=messageDTO.Group_ID,
        tab.MessageType=messageDTO.Type
    ));
}
		//删除消息（撤回？）
bool MessageService::Del(MessageDTO messageDTO,mysql::connection db){
    const auto tab=_Message{};
    db(update(tab).set(tab.IsDelete=1).where(tab.IsDelete==1));
}
		//获取该群组里的消息列表，其中id是group的id，返回结果数
int MessageService::GetMessageList(vector<MessageDTO>& messageList, int id,mysql::connection db){
    const auto tab=_Message{};
    for (const auto& row:db(select(all_of(tab)).from(tab).where(tab.GroupID==id)))
    {
        MessageDTO messageDTO;
        messageDTO.Context=row.Context;
        messageDTO.Group_ID=row.GroupID;
        messageDTO.Sender_ID=row.SenderID;
        messageDTO.Type=row.MessageType;
        messageList.push_back(messageDTO);
    }
    return messageList.size();
}