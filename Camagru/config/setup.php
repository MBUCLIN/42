<?php
	include("database.php");
	try {
		$pdo = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD, array(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION));
		$sql = 'CREATE DATABASE IF NOT EXISTS db_camagru;
						USE db_camagru;';
		$pdo->exec($sql);
		$sql = "DROP TABLE IF EXISTS `users`;
				DROP TABLE IF EXISTS `user_info`;
				DROP TABLE IF EXISTS `images`;
				DROP TABLE IF EXISTS `image_info`;
				DROP TABLE IF EXISTS `wt_conf`;";
		$pdo->exec($sql);
		$sql = "CREATE TABLE `wt_conf` (login VARCHAR(16) NOT NULL, passwd CHAR(128) NOT NULL, mail VARCHAR(320) NOT NULL, token VARCHAR(100));
				CREATE TABLE `users` (id VARCHAR(32) PRIMARY KEY NOT NULL, login VARCHAR(16) NOT NULL, passwd CHAR(128) NOT NULL);
				CREATE TABLE `user_info` (id VARCHAR(32) PRIMARY KEY NOT NULL, mail VARCHAR(320) NOT NULL);
				CREATE TABLE `images` (id_img VARCHAR(32) PRIMARY KEY NOT NULL, id VARCHAR(32) NOT NULL);
				CREATE TABLE `img_info` (id_img INT(11) PRIMARY KEY, array_tag VARCHAR(1500), array_like VARCHAR(1500), array_comment TEXT);";
		$pdo->exec($sql);
		$pdo = null;
		$sql = null;
		$DB_DSN = null;
		$DB_USER = null;
		$DB_PASSWORD = null;
	} catch (PDOException $error) {
		echo 'Exception caught : ' . $error->getMessage() . '\n';
		exit();
	}
	header("Location: ../index.php");
?>
