-- MySQL dump 10.16  Distrib 10.1.37-MariaDB, for debian-linux-gnu (x86_64)
--
-- Host: localhost    Database: PoppopDatabase
-- ------------------------------------------------------
-- Server version	10.1.37-MariaDB-0+deb9u1

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `Friend`
--

DROP TABLE IF EXISTS `Friend`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Friend` (
  `This_ID` int(11) NOT NULL,
  `That_ID` int(11) NOT NULL,
  `GroupID` int(11) DEFAULT NULL,
  `IsDelete` int(1) DEFAULT NULL,
  PRIMARY KEY (`This_ID`,`That_ID`),
  KEY `That_ID` (`That_ID`),
  KEY `GroupID` (`GroupID`),
  CONSTRAINT `Friend_ibfk_1` FOREIGN KEY (`This_ID`) REFERENCES `User` (`ID`),
  CONSTRAINT `Friend_ibfk_2` FOREIGN KEY (`That_ID`) REFERENCES `User` (`ID`),
  CONSTRAINT `Friend_ibfk_3` FOREIGN KEY (`GroupID`) REFERENCES `_Group` (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `GroupChat`
--

DROP TABLE IF EXISTS `GroupChat`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `GroupChat` (
  `ID` int(11) NOT NULL AUTO_INCREMENT,
  `GroupChatName` varchar(20) CHARACTER SET utf8 NOT NULL,
  `MemberIDList` varchar(500) CHARACTER SET utf8 DEFAULT NULL,
  `ImagePath` varchar(100) DEFAULT NULL,
  `IsDelete` int(1) DEFAULT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `User`
--

DROP TABLE IF EXISTS `User`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `User` (
  `ID` int(11) NOT NULL AUTO_INCREMENT,
  `PassWord` varchar(30) NOT NULL,
  `UserName` varchar(20) CHARACTER SET utf8 NOT NULL,
  `Sex` varchar(1) CHARACTER SET utf8 DEFAULT NULL,
  `ImagePath` varchar(100) DEFAULT NULL,
  `DepartmentName` varchar(20) CHARACTER SET utf8 DEFAULT NULL,
  `Motto` varchar(100) CHARACTER SET utf8 DEFAULT NULL,
  `IsDelete` int(1) DEFAULT NULL,
  `IPAddr` int(10) unsigned DEFAULT NULL,
  `IsOnline` int(11) DEFAULT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf8mb4;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `_Group`
--

DROP TABLE IF EXISTS `_Group`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `_Group` (
  `ID` int(11) NOT NULL AUTO_INCREMENT,
  `GroupName` varchar(20) CHARACTER SET utf8 NOT NULL,
  `Owner_ID` int(11) DEFAULT NULL,
  `IsDelete` int(1) DEFAULT NULL,
  PRIMARY KEY (`ID`),
  KEY `Owner_ID` (`Owner_ID`),
  CONSTRAINT `_Group_ibfk_1` FOREIGN KEY (`Owner_ID`) REFERENCES `User` (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `_Message`
--

DROP TABLE IF EXISTS `_Message`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `_Message` (
  `Sender_ID` int(11) DEFAULT NULL,
  `Context` varchar(200) CHARACTER SET utf8 DEFAULT NULL,
  `MessageType` int(1) DEFAULT NULL,
  `MessageTime` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  `GroupID` int(11) DEFAULT NULL,
  `IsDelete` int(1) DEFAULT NULL,
  KEY `Sender_ID` (`Sender_ID`),
  KEY `GroupID` (`GroupID`),
  CONSTRAINT `_Message_ibfk_1` FOREIGN KEY (`Sender_ID`) REFERENCES `User` (`ID`),
  CONSTRAINT `_Message_ibfk_2` FOREIGN KEY (`GroupID`) REFERENCES `GroupChat` (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;
/*!40101 SET character_set_client = @saved_cs_client */;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2019-09-01 20:12:23
