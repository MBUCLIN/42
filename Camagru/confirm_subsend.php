<?php
	session_start();
	include("config/database.php");
	if (isset($_SESSION['logged_on_us'])) {
		header("Location: index.php");
	} else if (empty($_POST['user_name']) || empty($_POST['passwd']) || empty($_POST['mail'])) {
		$_POST['error'] = "You have to fill all the input fields.";
		header("Location: subscribe.php");
	} else {
		$user_name = htmlspecialchars($_POST['user_name']);
		$password = hash('sha512', htmlspecialchars($_POST['passwd']));
		$e_mail = htmlspecialchars($_POST['mail']);
		$token = hash('md5', time());
		unset($_POST['user_name'], $_POST['passwd'], $_POST['mail']);
		try {
			$pdo = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD);
			$pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
			$sql = 'USE db_camagru;';
			$pdo->exec($sql);
			$pdo->beginTransaction();
			$sql = "SELECT `login` FROM wt_conf WHERE `login` = :login";
			$rep =  $pdo->prepare($sql, array(PDO::ATTR_CURSOR => PDO::CURSOR_FWDONLY));
			$rep->execute(array('login' => $user_name));
			$ret = $rep->fetchAll();
			$pdo->commit();
			if (isset($ret[0]['login'])) {
				$_POST['error'] = "Login already exists.";
				header("Location: subscribe.php");
			} else {
				$pdo->beginTransaction();
				$sql = "SELECT `login` FROM users WHERE `login` = :login";
				$rep = $pdo->prepare($sql, array(PDO::ATTR_CURSOR => PDO::CURSOR_FWDONLY));
				$rep->execute(array('login' => $user_name));
				$ret = $rep->fetchAll();
				$pdo->commit();
				if (isset($ret[0]['login'])) {
					$_POST['error'] = "Login already exists.";
					header("Location: subscribe.php");
				} else {
					$pdo->beginTransaction();
					$sql = "INSERT INTO wt_conf VALUES (?, ?, ?, ?);";
					$pre = $pdo->prepare($sql);
					$pre->execute(array($user_name, $password, $e_mail, $token));
					$pdo->commit();
				}
			}
		} catch (PDOException $error) {
			$pdo->rollback();
			$_POST['error'] = "An error occured while connection to database";
			$pdo = null;
			unset($error);
			header("Location : subscribe.php");
		}
		$msg = 'Hello world! and welcome to Camagru,

		You have to validate your account with the link below :
		http://localhost:8080/Camagru/validate.php
		Enter the code :' . $token .'
		Enter your login and password and let\'s
		take some pictures !!';
		$msg = wordwrap($msg, 70, '\n');
		mail($e_mail, 'Confirm account Camagru', $msg);
		unset($ret, $pdo, $sql, $rep, $user_name, $password, $e_mail, $token);
		if (!isset($_POST['error']))
			header("Location: validate.php");
	}
?>
