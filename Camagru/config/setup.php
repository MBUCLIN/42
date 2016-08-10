<?php
	include("database.php");
	try {
		$pdo = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD, array(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION));
		$sql = 'USE db_camagru;
				DROP TABLE IF EXISTS `users`;
				DROP TABLE IF EXISTS `user_info`;
				DROP TABLE IF EXISTS `images`;
				DROP TABLE IF EXISTS `img_info`;
				DROP TABLE IF EXISTS `wt_conf`;';
		$pdo->exec($sql);
		echo 'TABLES DROPED<br />';
		$sql = 'CREATE TABLE `wt_conf` (login VARCHAR(16) NOT NULL, passwd CHAR(128) NOT NULL, mail VARCHAR(320) NOT NULL);
				CREATE TABLE `users` (id INT(11) PRIMARY KEY AUTO_INCREMENT, login VARCHAR(16) NOT NULL, passwd CHAR(128) NOT NULL);
				CREATE TABLE `user_info` (id INT(11) PRIMARY KEY AUTO_INCREMENT, mail VARCHAR(320) NOT NULL);
				CREATE TABLE `images` (id_img INT(11) PRIMARY KEY AUTO_INCREMENT, img_myname VARCHAR(255), id INT(11));
				CREATE TABLE `img_info` (id_img INT(11) PRIMARY KEY, tag VARCHAR(26) NOT NULL, img_usname VARCHAR(255) NOT NULL);';
		$pdo->exec($sql);
		echo 'TABLES CREATED<br />';
		$pdo = null;
		$sql = null;
		$DB_DSN = null;
		$DB_USER = null;
		$DB_PASSWORD = null;
	} catch (PDOException $error) {
		echo 'Exception caught : ' . $error->getMessage() . '\n';
		exit();
	}
?>
