<?php
	session_start();
	include("config/database.php");
	if (isset($_SESSION['logged_on_us'])) {
		header("Location: index.php");
	}
	$user_name = htmlspecialchars($_POST['user_name']);
	$password = hash('sha512', $_POST['passwd']);
	$e_mail = htmlspecialchars($_POST['mail']);
	$token = hash('md5', time());

	try {
		$pdo = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD);
		$pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
		$sql = 'USE db_camagru;';
		$pdo->exec($sql);
		$pdo->beginTransaction();
		$sql = 'SELECT login, mail FROM `users`, `user_info` WHERE login = :user OR mail = :mail';
		$pre =  $pdo->prepare($sql, array(PDO::ATTR_CURSOR => PDO::CURSOR_FWDONLY));
		$pre->execute(array(':user' => $user_name, ':mail' => $e_mail));
		$ret = $pre->fetchAll();
		$pdo->commit();
		if (isset($ret['login']) || isset($ret['mail'])) {
			$_POST['error'] = 'Your login or password already exists.';
			unset($ret, $pdo, $sql, $pre, $user_name, $password, $e_mail, $_POST['user_name'], $_POST['passwd'], $_POST['mail']);
			header('Location: subscribe.php');
		}
		$pdo->beginTransaction();
		$sql = "INSERT INTO wt_conf VALUES (?, ?, ?, ?);";
		$pre = $pdo->prepare($sql);
		$pre->execute(array($user_name, $password, $e_mail, $token));
		$pdo->commit();
	} catch (PDOException $error) {
		$pdo->rollback();
		$_POST['error'] = "An error occured while connection to database";
		$pdo = null;
		unset($error);
		header("Location : subscribe.php");
	}
//	$msg = 'Hello world! and welcome to Camagru,\r\n\r\nYou have to validate your account with the link below :\r\nhttp://localhost:8080/Camagru/validate.php\r\nEnter your login and password and let\'s\r\ntake some pictures !!';
//	$msg = wordwrap($msg, 70, '\r\n');
//	$true = mail($e_mail, 'Confirm account Camagru', $msg);
	unset($ret, $pdo, $sql, $pre, $user_name, $password, $e_mail, $token, $_POST['user_name'], $_POST['passwd'], $_POST['mail']);
	header("Location: validate.php");
?>
