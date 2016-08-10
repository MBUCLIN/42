<?php
	session_start();
	include("config/database.php");
	if (isset($_SESSION['logged_on_us'])) {
		header("Location: index.php");
	}
	$user_name = $_POST['user_name'];
	$password = hash('sha512', $_POST['passwd']);
	$e_mail = $_POST['mail'];
	try {
		$pdo = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD);
		$sql = 'USE db_camagru;';
		$pdo->exec($sql);
		$pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
		$pdo->beginTransaction();
		$sql = 'SELECT login, mail FROM `users`, `user_info` WHERE login = :user OR mail = :mail';
		$pre =  $pdo->prepare($sql, array(PDO::ATTR_CURSOR => PDO::CURSOR_FWDONLY));
		$pre->execute(array(':user' => $user_name, ':mail' => $e_mail));
		$ret = $pre->fetchAll();
		$pdo->commit();
		if (isset($ret['login']) || isset($ret['mail'])) {
			$_POST['error'] = 'Your login or password already exists.';
			unset($ret, $pdo, $sql, $pre, $user_name, $password, $e_mail, $_POST['user_name'], $_POST['passwd'], $_POST['mail']);
			header('Location : subscribe.php');
		}
		$pdo->beginTransaction();
		$sql = "INSERT INTO wt_conf VALUES (?, ?, ?);";
		$pre = $pdo->prepare($sql);
		$pre->execute(array($user_name, $password, $e_mail));
		$pdo->commit();
	} catch (PDOException $error) {
		$pdo->rollback();
		echo 'Exception catched : ' . $error->getMessage() . '\n';
		$pdo = null;
		unset($error);
		exit();
	}
	echo $e_mail . ' : e_mail' . '	<br />';
	$true = mail($e_mail, 'Confirm account Camagru',
		'Hello world! and welcome to Camagru,

	You have to validate your account with the link below :
	http://localhost:8080/Camagru/validate.php

	Enter your login and password and let\'s take some pictures !!');
	if ($true === FALSE)
		echo 'fait chier';
	unset($ret, $pdo, $sql, $pre, $user_name, $password, $e_mail, $_POST['user_name'], $_POST['passwd'], $_POST['mail']);
?>
