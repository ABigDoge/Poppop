-- MySQL dump 10.16  Distrib 10.1.24-MariaDB, for debian-linux-gnu (x86_64)
--
-- Host: localhost    Database: PoppopDatabase
-- ------------------------------------------------------
-- Server version	10.1.24-MariaDB-6

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
-- Dumping data for table `Friend`
--

LOCK TABLES `Friend` WRITE;
/*!40000 ALTER TABLE `Friend` DISABLE KEYS */;
INSERT INTO `Friend` VALUES (7,8,1,0);
/*!40000 ALTER TABLE `Friend` ENABLE KEYS */;
UNLOCK TABLES;

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
-- Dumping data for table `GroupChat`
--

LOCK TABLES `GroupChat` WRITE;
/*!40000 ALTER TABLE `GroupChat` DISABLE KEYS */;
/*!40000 ALTER TABLE `GroupChat` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `PrivateMessage`
--

DROP TABLE IF EXISTS `PrivateMessage`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `PrivateMessage` (
  `Sender_ID` int(11) DEFAULT NULL,
  `Context` varchar(200) CHARACTER SET utf8 DEFAULT NULL,
  `MessageType` int(1) DEFAULT NULL,
  `MessageTime` varchar(20) DEFAULT NULL,
  `Recver_ID` int(11) DEFAULT NULL,
  `IsDelete` int(1) DEFAULT NULL,
  KEY `Sender_ID` (`Sender_ID`),
  CONSTRAINT `PrivateMessage_ibfk_1` FOREIGN KEY (`Sender_ID`) REFERENCES `User` (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `PrivateMessage`
--

LOCK TABLES `PrivateMessage` WRITE;
/*!40000 ALTER TABLE `PrivateMessage` DISABLE KEYS */;
/*!40000 ALTER TABLE `PrivateMessage` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `PublicMessage`
--

DROP TABLE IF EXISTS `PublicMessage`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `PublicMessage` (
  `Sender_ID` int(11) DEFAULT NULL,
  `Context` varchar(200) CHARACTER SET utf8 DEFAULT NULL,
  `MessageType` int(1) DEFAULT NULL,
  `MessageTime` varchar(20) DEFAULT NULL,
  `GroupID` int(11) DEFAULT NULL,
  `IsDelete` int(1) DEFAULT NULL,
  KEY `Sender_ID` (`Sender_ID`),
  KEY `GroupID` (`GroupID`),
  CONSTRAINT `PublicMessage_ibfk_1` FOREIGN KEY (`Sender_ID`) REFERENCES `User` (`ID`),
  CONSTRAINT `PublicMessage_ibfk_2` FOREIGN KEY (`GroupID`) REFERENCES `GroupChat` (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `PublicMessage`
--

LOCK TABLES `PublicMessage` WRITE;
/*!40000 ALTER TABLE `PublicMessage` DISABLE KEYS */;
/*!40000 ALTER TABLE `PublicMessage` ENABLE KEYS */;
UNLOCK TABLES;

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
) ENGINE=InnoDB AUTO_INCREMENT=9 DEFAULT CHARSET=utf8mb4;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `User`
--

LOCK TABLES `User` WRITE;
/*!40000 ALTER TABLE `User` DISABLE KEYS */;
INSERT INTO `User` VALUES (7,'hhh','lsy','','','','',0,1234,1),(8,'www','hsx','','','','',0,NULL,NULL);
/*!40000 ALTER TABLE `User` ENABLE KEYS */;
UNLOCK TABLES;

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
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8mb4;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `_Group`
--

LOCK TABLES `_Group` WRITE;
/*!40000 ALTER TABLE `_Group` DISABLE KEYS */;
INSERT INTO `_Group` VALUES (1,'默认分组',7,0);
/*!40000 ALTER TABLE `_Group` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2019-09-02 18:25:30
