create database Poppop;
create table User(
    ID int auto_increment primary key,
    PassWord varchar(30) not null,
    UserName nvarchar(20) not null,
    Sex nvarchar(1) default null,
    ImagePath varchar(100),
    DepartmentName nvarchar(20),
    Motto nvarchar(100),
    IsDelete int(1)
);
create table _Group(
    ID int auto_increment primary key,
    GroupName nvarchar(20) not null,
    Owner_ID int,
    foreign key(Owner_ID) references User(ID),
    IsDelete int(1)
);

create table Friend(
    UserOneID int,
    UserTwoID int,
    GroupOneID int,
    GroupTwoID int,
    foreign key(UserOneID) references User(ID),
    foreign key(UserTwoID) references User(ID),
    foreign key(GroupOneID) references _Group(ID),
    foreign key(GroupTwoID) references _Group(ID),
    primary key(UserOneID,UserTwoID),
    IsDelete int(1)
);
create table GroupChat(
    ID int auto_increment primary key,
    GroupChatName nvarchar(20) not null,
    MemberIDList nvarchar(500),
    ImagePath varchar(100),
    IsDelete int(1)
);
create table _Message(
    Sender_ID int,
    Context nvarchar(200),
    MessageType int(1),
    MessageTime TimeStamp,
    GroupID int,
    foreign key(Sender_ID) references User(ID),
    foreign key(GroupID) references GroupChat(ID),
    IsDelete int(1) 
);
