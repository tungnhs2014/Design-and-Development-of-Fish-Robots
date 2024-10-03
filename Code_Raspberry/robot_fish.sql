-- MySQL dump 10.19  Distrib 10.3.29-MariaDB, for debian-linux-gnueabihf (armv7l)
--
-- Host: localhost    Database: robot_fish
-- ------------------------------------------------------
-- Server version	10.3.29-MariaDB-0+deb10u1

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
-- Table structure for table `envData`
--

DROP TABLE IF EXISTS `envData`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `envData` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `temperature` int(11) NOT NULL,
  `humidity` int(11) NOT NULL,
  `deep` int(11) NOT NULL,
  `update_only_time` time DEFAULT curtime(),
  `update_time` datetime DEFAULT current_timestamp(),
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=93 DEFAULT CHARSET=utf8mb4;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `envData`
--

LOCK TABLES `envData` WRITE;
/*!40000 ALTER TABLE `envData` DISABLE KEYS */;
INSERT INTO `envData` VALUES (1,30,70,3,'17:14:50','2021-07-02 17:14:50'),(2,30,73,2,'17:15:14','2021-07-02 17:15:14'),(3,30,73,2,'17:15:15','2021-07-02 17:15:15'),(4,30,73,2,'17:15:15','2021-07-02 17:15:15'),(5,32,73,1,'17:15:21','2021-07-02 17:15:21'),(6,30,70,5,'16:15:43','2021-07-04 16:15:43'),(7,28,78,4,'16:15:43','2021-07-04 16:15:43'),(8,28,78,4,'16:15:43','2021-07-04 16:15:43'),(9,20,77,4,'16:15:44','2021-07-04 16:15:44'),(10,20,77,4,'16:15:44','2021-07-04 16:15:44'),(11,20,77,4,'16:15:44','2021-07-04 16:15:44'),(12,25,82,4,'16:15:45','2021-07-04 16:15:45'),(13,25,82,4,'16:15:45','2021-07-04 16:15:45'),(14,25,82,4,'16:15:45','2021-07-04 16:15:45'),(15,32,78,1,'16:15:46','2021-07-04 16:15:46'),(16,32,78,1,'16:15:46','2021-07-04 16:15:46'),(17,32,78,1,'16:15:46','2021-07-04 16:15:46'),(18,34,81,3,'16:15:47','2021-07-04 16:15:47'),(19,34,81,3,'16:15:47','2021-07-04 16:15:47'),(20,34,81,3,'16:15:47','2021-07-04 16:15:47'),(21,34,84,1,'16:15:48','2021-07-04 16:15:48'),(22,34,84,1,'16:15:48','2021-07-04 16:15:48'),(23,34,84,1,'16:15:48','2021-07-04 16:15:48'),(24,32,84,1,'16:15:49','2021-07-04 16:15:49'),(25,32,84,1,'16:15:49','2021-07-04 16:15:49'),(26,32,84,1,'16:15:49','2021-07-04 16:15:49'),(27,33,72,4,'16:15:50','2021-07-04 16:15:50'),(28,33,72,4,'16:15:50','2021-07-04 16:15:50'),(29,33,72,4,'16:15:50','2021-07-04 16:15:50'),(30,35,80,1,'16:15:51','2021-07-04 16:15:51'),(31,28,80,4,'16:15:52','2021-07-04 16:15:52'),(32,28,80,4,'16:15:52','2021-07-04 16:15:52'),(33,28,80,4,'16:15:52','2021-07-04 16:15:52'),(34,38,77,2,'16:15:53','2021-07-04 16:15:53'),(35,38,77,2,'16:15:53','2021-07-04 16:15:53'),(36,29,78,1,'16:15:55','2021-07-04 16:15:55'),(37,25,76,3,'16:15:56','2021-07-04 16:15:56'),(38,25,76,3,'16:15:56','2021-07-04 16:15:56'),(39,23,74,1,'16:15:57','2021-07-04 16:15:57'),(40,23,74,1,'16:15:57','2021-07-04 16:15:57'),(41,23,74,1,'16:15:57','2021-07-04 16:15:57'),(42,26,84,3,'16:15:58','2021-07-04 16:15:58'),(43,26,84,3,'16:15:58','2021-07-04 16:15:58'),(44,26,84,3,'16:15:58','2021-07-04 16:15:58'),(45,28,73,5,'16:16:04','2021-07-04 16:16:04'),(46,28,73,5,'16:16:04','2021-07-04 16:16:04'),(47,28,73,5,'16:16:04','2021-07-04 16:16:04'),(48,30,85,4,'16:16:06','2021-07-04 16:16:06'),(49,30,85,4,'16:16:06','2021-07-04 16:16:06'),(50,22,85,5,'16:16:07','2021-07-04 16:16:07'),(51,23,84,1,'16:16:09','2021-07-04 16:16:09'),(52,23,84,1,'16:16:09','2021-07-04 16:16:09'),(53,23,84,1,'16:16:09','2021-07-04 16:16:09'),(54,23,75,5,'16:16:10','2021-07-04 16:16:10'),(55,23,75,5,'16:16:10','2021-07-04 16:16:10'),(56,23,75,5,'16:16:10','2021-07-04 16:16:10'),(57,27,79,5,'16:16:11','2021-07-04 16:16:11'),(58,27,79,5,'16:16:11','2021-07-04 16:16:11'),(59,27,79,5,'16:16:11','2021-07-04 16:16:11'),(60,22,79,5,'16:16:12','2021-07-04 16:16:12'),(61,22,79,5,'16:16:12','2021-07-04 16:16:12'),(62,22,79,5,'16:16:12','2021-07-04 16:16:12'),(63,36,82,2,'16:16:14','2021-07-04 16:16:14'),(64,36,82,2,'16:16:14','2021-07-04 16:16:14'),(65,36,82,2,'16:16:14','2021-07-04 16:16:14'),(66,32,76,3,'16:16:15','2021-07-04 16:16:15'),(67,32,76,3,'16:16:15','2021-07-04 16:16:15'),(68,32,76,3,'16:16:15','2021-07-04 16:16:15'),(69,33,78,2,'16:16:16','2021-07-04 16:16:16'),(70,33,78,2,'16:16:16','2021-07-04 16:16:16'),(71,33,78,2,'16:16:16','2021-07-04 16:16:16'),(72,31,80,2,'16:16:17','2021-07-04 16:16:17'),(73,31,80,2,'16:16:17','2021-07-04 16:16:17'),(74,31,80,2,'16:16:17','2021-07-04 16:16:17'),(75,38,84,1,'16:16:18','2021-07-04 16:16:18'),(76,38,84,1,'16:16:18','2021-07-04 16:16:18'),(77,38,84,1,'16:16:18','2021-07-04 16:16:18'),(78,26,78,5,'16:16:19','2021-07-04 16:16:19'),(79,26,78,5,'16:16:19','2021-07-04 16:16:19'),(80,35,83,1,'16:16:20','2021-07-04 16:16:20'),(81,35,83,1,'16:16:20','2021-07-04 16:16:20'),(82,21,72,3,'16:16:21','2021-07-04 16:16:21'),(83,21,72,3,'16:16:21','2021-07-04 16:16:21'),(84,21,72,3,'16:16:21','2021-07-04 16:16:21'),(85,29,80,5,'16:16:22','2021-07-04 16:16:22'),(86,29,80,5,'16:16:22','2021-07-04 16:16:22'),(87,23,78,1,'16:16:23','2021-07-04 16:16:23'),(88,23,78,1,'16:16:23','2021-07-04 16:16:23'),(89,23,78,1,'16:16:23','2021-07-04 16:16:23'),(90,37,72,2,'16:16:24','2021-07-04 16:16:24'),(91,37,72,2,'16:16:24','2021-07-04 16:16:24'),(92,37,72,2,'16:16:24','2021-07-04 16:16:24');
/*!40000 ALTER TABLE `envData` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `settime`
--

DROP TABLE IF EXISTS `settime`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `settime` (
  `ontime` time NOT NULL,
  `offtime` time NOT NULL,
  `update_time` time DEFAULT curtime()
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `settime`
--

LOCK TABLES `settime` WRITE;
/*!40000 ALTER TABLE `settime` DISABLE KEYS */;
INSERT INTO `settime` VALUES ('15:29:00','15:30:00','10:08:10');
/*!40000 ALTER TABLE `settime` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2021-07-04 16:16:25
