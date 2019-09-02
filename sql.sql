create database PoppopDatabase;
create table User(
    ID int auto_increment primary key,
    PassWord varchar(30) not null,
    UserName nvarchar(20) not null,
    Sex nvarchar(1) default null,
    ImagePath varchar(100),
    DepartmentName nvarchar(20),
    Motto nvarchar(100),
    IsDelete int(1),
    IPAddr INT UNSIGNED,
    IsOnline INT);

create table _Group(
    ID int auto_increment primary key,
    GroupName nvarchar(20) not null,
    Owner_ID int,
    foreign key(Owner_ID) references User(ID),
    IsDelete int(1)
);

create table Friend(
    This_ID int,
    That_ID int,
    GroupID int,
    foreign key(This_ID) references User(ID),
    foreign key(That_ID) references User(ID),
    foreign key(GroupID) references _Group(ID),
    primary key(This_ID,That_ID),
    IsDelete int(1)
);
create table GroupChat(
    ID int auto_increment primary key,
    GroupChatName nvarchar(20) not null,
    MemberIDList nvarchar(500),
    ImagePath varchar(100),
    IsDelete int(1)
);
create table PrivateMessage(
    Sender_ID int,
    Context nvarchar(200),
    MessageType int(1),
    MessageTime varchar(20),
    Recver_ID int,
    foreign key(Sender_ID) references User(ID),
    IsDelete int(1) 
);

create table PublicMessage(
    Sender_ID int,
    Context nvarchar(200),
    MessageType int(1),
    MessageTime varchar(20),
    GroupID int,
    foreign key(Sender_ID) references User(ID),
    foreign key(GroupID) references GroupChat(ID),
    IsDelete int(1) 
);
