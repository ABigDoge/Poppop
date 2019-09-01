// generated by /home/wlj/code/Poppop/Poppop/scripts/ddl2cpp /home/wlj/code/Poppop/Poppop/temp/MyDatabase.ddl /home/wlj/code/Poppop/Poppop/DTO/MyTable MyTable
#ifndef MYTABLE_MYTABLE_H
#define MYTABLE_MYTABLE_H

#include <sqlpp11/table.h>
#include <sqlpp11/data_types.h>
#include <sqlpp11/char_sequence.h>

  namespace Friend_
  {
    struct UserOneID
    {
      struct _alias_t
      {
        static constexpr const char _literal[] =  "UserOneID";
        using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
        template<typename T>
        struct _member_t
          {
            T UserOneID;
            T& operator()() { return UserOneID; }
            const T& operator()() const { return UserOneID; }
          };
      };
      using _traits = sqlpp::make_traits<sqlpp::integer, sqlpp::tag::require_insert>;
    };
    struct UserTwoID
    {
      struct _alias_t
      {
        static constexpr const char _literal[] =  "UserTwoID";
        using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
        template<typename T>
        struct _member_t
          {
            T UserTwoID;
            T& operator()() { return UserTwoID; }
            const T& operator()() const { return UserTwoID; }
          };
      };
      using _traits = sqlpp::make_traits<sqlpp::integer, sqlpp::tag::require_insert>;
    };
    struct GroupOneID
    {
      struct _alias_t
      {
        static constexpr const char _literal[] =  "GroupOneID";
        using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
        template<typename T>
        struct _member_t
          {
            T GroupOneID;
            T& operator()() { return GroupOneID; }
            const T& operator()() const { return GroupOneID; }
          };
      };
      using _traits = sqlpp::make_traits<sqlpp::integer, sqlpp::tag::can_be_null>;
    };
    struct GroupTwoID
    {
      struct _alias_t
      {
        static constexpr const char _literal[] =  "GroupTwoID";
        using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
        template<typename T>
        struct _member_t
          {
            T GroupTwoID;
            T& operator()() { return GroupTwoID; }
            const T& operator()() const { return GroupTwoID; }
          };
      };
      using _traits = sqlpp::make_traits<sqlpp::integer, sqlpp::tag::can_be_null>;
    };
    struct IsDelete
    {
      struct _alias_t
      {
        static constexpr const char _literal[] =  "IsDelete";
        using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
        template<typename T>
        struct _member_t
          {
            T IsDelete;
            T& operator()() { return IsDelete; }
            const T& operator()() const { return IsDelete; }
          };
      };
      using _traits = sqlpp::make_traits<sqlpp::integer, sqlpp::tag::can_be_null>;
    };
  } // namespace Friend_

  struct Friend: sqlpp::table_t<Friend,
               Friend_::UserOneID,
               Friend_::UserTwoID,
               Friend_::GroupOneID,
               Friend_::GroupTwoID,
               Friend_::IsDelete>
  {
    struct _alias_t
    {
      static constexpr const char _literal[] =  "Friend";
      using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
      template<typename T>
      struct _member_t
      {
        T Friend;
        T& operator()() { return Friend; }
        const T& operator()() const { return Friend; }
      };
    };
  };
  namespace GroupChat_
  {
    struct ID
    {
      struct _alias_t
      {
        static constexpr const char _literal[] =  "ID";
        using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
        template<typename T>
        struct _member_t
          {
            T ID;
            T& operator()() { return ID; }
            const T& operator()() const { return ID; }
          };
      };
      using _traits = sqlpp::make_traits<sqlpp::integer, sqlpp::tag::must_not_insert, sqlpp::tag::must_not_update>;
    };
    struct GroupChatName
    {
      struct _alias_t
      {
        static constexpr const char _literal[] =  "GroupChatName";
        using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
        template<typename T>
        struct _member_t
          {
            T GroupChatName;
            T& operator()() { return GroupChatName; }
            const T& operator()() const { return GroupChatName; }
          };
      };
      using _traits = sqlpp::make_traits<sqlpp::varchar, sqlpp::tag::require_insert>;
    };
    struct MemberIDList
    {
      struct _alias_t
      {
        static constexpr const char _literal[] =  "MemberIDList";
        using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
        template<typename T>
        struct _member_t
          {
            T MemberIDList;
            T& operator()() { return MemberIDList; }
            const T& operator()() const { return MemberIDList; }
          };
      };
      using _traits = sqlpp::make_traits<sqlpp::varchar, sqlpp::tag::can_be_null>;
    };
    struct ImagePath
    {
      struct _alias_t
      {
        static constexpr const char _literal[] =  "ImagePath";
        using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
        template<typename T>
        struct _member_t
          {
            T ImagePath;
            T& operator()() { return ImagePath; }
            const T& operator()() const { return ImagePath; }
          };
      };
      using _traits = sqlpp::make_traits<sqlpp::varchar, sqlpp::tag::can_be_null>;
    };
    struct IsDelete
    {
      struct _alias_t
      {
        static constexpr const char _literal[] =  "IsDelete";
        using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
        template<typename T>
        struct _member_t
          {
            T IsDelete;
            T& operator()() { return IsDelete; }
            const T& operator()() const { return IsDelete; }
          };
      };
      using _traits = sqlpp::make_traits<sqlpp::integer, sqlpp::tag::can_be_null>;
    };
  } // namespace GroupChat_

  struct GroupChat: sqlpp::table_t<GroupChat,
               GroupChat_::ID,
               GroupChat_::GroupChatName,
               GroupChat_::MemberIDList,
               GroupChat_::ImagePath,
               GroupChat_::IsDelete>
  {
    struct _alias_t
    {
      static constexpr const char _literal[] =  "GroupChat";
      using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
      template<typename T>
      struct _member_t
      {
        T GroupChat;
        T& operator()() { return GroupChat; }
        const T& operator()() const { return GroupChat; }
      };
    };
  };
  namespace User_
  {
    struct ID
    {
      struct _alias_t
      {
        static constexpr const char _literal[] =  "ID";
        using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
        template<typename T>
        struct _member_t
          {
            T ID;
            T& operator()() { return ID; }
            const T& operator()() const { return ID; }
          };
      };
      using _traits = sqlpp::make_traits<sqlpp::integer, sqlpp::tag::must_not_insert, sqlpp::tag::must_not_update>;
    };
    struct PassWord
    {
      struct _alias_t
      {
        static constexpr const char _literal[] =  "PassWord";
        using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
        template<typename T>
        struct _member_t
          {
            T PassWord;
            T& operator()() { return PassWord; }
            const T& operator()() const { return PassWord; }
          };
      };
      using _traits = sqlpp::make_traits<sqlpp::varchar, sqlpp::tag::require_insert>;
    };
    struct UserName
    {
      struct _alias_t
      {
        static constexpr const char _literal[] =  "UserName";
        using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
        template<typename T>
        struct _member_t
          {
            T UserName;
            T& operator()() { return UserName; }
            const T& operator()() const { return UserName; }
          };
      };
      using _traits = sqlpp::make_traits<sqlpp::varchar, sqlpp::tag::require_insert>;
    };
    struct Sex
    {
      struct _alias_t
      {
        static constexpr const char _literal[] =  "Sex";
        using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
        template<typename T>
        struct _member_t
          {
            T Sex;
            T& operator()() { return Sex; }
            const T& operator()() const { return Sex; }
          };
      };
      using _traits = sqlpp::make_traits<sqlpp::varchar, sqlpp::tag::can_be_null>;
    };
    struct ImagePath
    {
      struct _alias_t
      {
        static constexpr const char _literal[] =  "ImagePath";
        using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
        template<typename T>
        struct _member_t
          {
            T ImagePath;
            T& operator()() { return ImagePath; }
            const T& operator()() const { return ImagePath; }
          };
      };
      using _traits = sqlpp::make_traits<sqlpp::varchar, sqlpp::tag::can_be_null>;
    };
    struct DepartmentName
    {
      struct _alias_t
      {
        static constexpr const char _literal[] =  "DepartmentName";
        using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
        template<typename T>
        struct _member_t
          {
            T DepartmentName;
            T& operator()() { return DepartmentName; }
            const T& operator()() const { return DepartmentName; }
          };
      };
      using _traits = sqlpp::make_traits<sqlpp::varchar, sqlpp::tag::can_be_null>;
    };
    struct Motto
    {
      struct _alias_t
      {
        static constexpr const char _literal[] =  "Motto";
        using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
        template<typename T>
        struct _member_t
          {
            T Motto;
            T& operator()() { return Motto; }
            const T& operator()() const { return Motto; }
          };
      };
      using _traits = sqlpp::make_traits<sqlpp::varchar, sqlpp::tag::can_be_null>;
    };
    struct IsDelete
    {
      struct _alias_t
      {
        static constexpr const char _literal[] =  "IsDelete";
        using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
        template<typename T>
        struct _member_t
          {
            T IsDelete;
            T& operator()() { return IsDelete; }
            const T& operator()() const { return IsDelete; }
          };
      };
      using _traits = sqlpp::make_traits<sqlpp::integer, sqlpp::tag::can_be_null>;
    };
  } // namespace User_

  struct User: sqlpp::table_t<User,
               User_::ID,
               User_::PassWord,
               User_::UserName,
               User_::Sex,
               User_::ImagePath,
               User_::DepartmentName,
               User_::Motto,
               User_::IsDelete>
  {
    struct _alias_t
    {
      static constexpr const char _literal[] =  "User";
      using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
      template<typename T>
      struct _member_t
      {
        T User;
        T& operator()() { return User; }
        const T& operator()() const { return User; }
      };
    };
  };
  namespace _Group_
  {
    struct ID
    {
      struct _alias_t
      {
        static constexpr const char _literal[] =  "ID";
        using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
        template<typename T>
        struct _member_t
          {
            T ID;
            T& operator()() { return ID; }
            const T& operator()() const { return ID; }
          };
      };
      using _traits = sqlpp::make_traits<sqlpp::integer, sqlpp::tag::must_not_insert, sqlpp::tag::must_not_update>;
    };
    struct GroupName
    {
      struct _alias_t
      {
        static constexpr const char _literal[] =  "GroupName";
        using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
        template<typename T>
        struct _member_t
          {
            T GroupName;
            T& operator()() { return GroupName; }
            const T& operator()() const { return GroupName; }
          };
      };
      using _traits = sqlpp::make_traits<sqlpp::varchar, sqlpp::tag::require_insert>;
    };
    struct OwnerID
    {
      struct _alias_t
      {
        static constexpr const char _literal[] =  "Owner_ID";
        using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
        template<typename T>
        struct _member_t
          {
            T OwnerID;
            T& operator()() { return OwnerID; }
            const T& operator()() const { return OwnerID; }
          };
      };
      using _traits = sqlpp::make_traits<sqlpp::integer, sqlpp::tag::can_be_null>;
    };
    struct IsDelete
    {
      struct _alias_t
      {
        static constexpr const char _literal[] =  "IsDelete";
        using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
        template<typename T>
        struct _member_t
          {
            T IsDelete;
            T& operator()() { return IsDelete; }
            const T& operator()() const { return IsDelete; }
          };
      };
      using _traits = sqlpp::make_traits<sqlpp::integer, sqlpp::tag::can_be_null>;
    };
  } // namespace _Group_

  struct _Group: sqlpp::table_t<_Group,
               _Group_::ID,
               _Group_::GroupName,
               _Group_::OwnerID,
               _Group_::IsDelete>
  {
    struct _alias_t
    {
      static constexpr const char _literal[] =  "_Group";
      using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
      template<typename T>
      struct _member_t
      {
        T Group;
        T& operator()() { return Group; }
        const T& operator()() const { return Group; }
      };
    };
  };
  namespace _Message_
  {
    struct SenderID
    {
      struct _alias_t
      {
        static constexpr const char _literal[] =  "Sender_ID";
        using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
        template<typename T>
        struct _member_t
          {
            T SenderID;
            T& operator()() { return SenderID; }
            const T& operator()() const { return SenderID; }
          };
      };
      using _traits = sqlpp::make_traits<sqlpp::integer, sqlpp::tag::can_be_null>;
    };
    struct Context
    {
      struct _alias_t
      {
        static constexpr const char _literal[] =  "Context";
        using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
        template<typename T>
        struct _member_t
          {
            T Context;
            T& operator()() { return Context; }
            const T& operator()() const { return Context; }
          };
      };
      using _traits = sqlpp::make_traits<sqlpp::varchar, sqlpp::tag::can_be_null>;
    };
    struct MessageType
    {
      struct _alias_t
      {
        static constexpr const char _literal[] =  "MessageType";
        using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
        template<typename T>
        struct _member_t
          {
            T MessageType;
            T& operator()() { return MessageType; }
            const T& operator()() const { return MessageType; }
          };
      };
      using _traits = sqlpp::make_traits<sqlpp::integer, sqlpp::tag::can_be_null>;
    };
    struct MessageTime
    {
      struct _alias_t
      {
        static constexpr const char _literal[] =  "MessageTime";
        using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
        template<typename T>
        struct _member_t
          {
            T MessageTime;
            T& operator()() { return MessageTime; }
            const T& operator()() const { return MessageTime; }
          };
      };
      using _traits = sqlpp::make_traits<sqlpp::time_point>;
    };
    struct GroupID
    {
      struct _alias_t
      {
        static constexpr const char _literal[] =  "GroupID";
        using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
        template<typename T>
        struct _member_t
          {
            T GroupID;
            T& operator()() { return GroupID; }
            const T& operator()() const { return GroupID; }
          };
      };
      using _traits = sqlpp::make_traits<sqlpp::integer, sqlpp::tag::can_be_null>;
    };
    struct IsDelete
    {
      struct _alias_t
      {
        static constexpr const char _literal[] =  "IsDelete";
        using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
        template<typename T>
        struct _member_t
          {
            T IsDelete;
            T& operator()() { return IsDelete; }
            const T& operator()() const { return IsDelete; }
          };
      };
      using _traits = sqlpp::make_traits<sqlpp::integer, sqlpp::tag::can_be_null>;
    };
  } // namespace _Message_

  struct _Message: sqlpp::table_t<_Message,
               _Message_::SenderID,
               _Message_::Context,
               _Message_::MessageType,
               _Message_::MessageTime,
               _Message_::GroupID,
               _Message_::IsDelete>
  {
    struct _alias_t
    {
      static constexpr const char _literal[] =  "_Message";
      using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
      template<typename T>
      struct _member_t
      {
        T Message;
        T& operator()() { return Message; }
        const T& operator()() const { return Message; }
      };
    };
  };
#endif
