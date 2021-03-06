<?php
	include('../config/database.php');
	session_start();
	if (isset($_SESSION['logged_on_us'])) {
		header("Location: ../index.php");
	} else if (empty($_POST['username']) || empty($_POST['password'])) {
		$_POST['error'] = "Empty input field.";
		header("Location: ../index.php");
	} else {
		$login = $_POST['username'];
		$passwd = hash('sha512', $_POST['password']);
		try {
			$pdo = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD);
			$pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
			$sql = "USE db_camagru;";
			$pdo->exec($sql);
			$pdo->beginTransaction();
			$sql = "SELECT login, passwd FROM users WHERE login = :login;";
			$pre = $pdo->prepare($sql, array(PDO::ATTR_CURSOR => CURSOR_FWDONLY));
			$pre->execute(array(':login' => $login));
			$ret = $pre->fetchAll();
			$pdo->commit();
			if (!isset($ret[0]['login'])) {
				$_POST['error'] = 'That account does not exists, did you validated it?';
				header("Location: ../index.php");
			} else if ($passwd !== $ret[0]['passwd']) {
				$_POST['error'] = 'Your password is invalid!';
				header("Location: ../index.php");
			} else {
				$_SESSION['logged_on_us'] = $login;
			}
			$pdo = null;
		} catch (PDOException $error) {
			$_POST['error'] = 'An error occured while connecting to database';
			header("Location: ../index.php");
		}
		unset($pdo, $sql, $pre, $ret, $DB_DSN, $DB_USER, $DB_PASSWORD, $login, $passwd);
		if (!isset($_POST['error'])) {
			header("Location: ../index.php");
		}
	}
?>
