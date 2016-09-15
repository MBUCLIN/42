<?php
	include("../config/database.php");
	if (isset($_SESSION['logged_on_us'])) {
		header("Location: ../index.php");
	} else if (empty($_POST['token'])) {
		$_POST['error'] = "Empty input field.";
		header("Location: ../validate.php");
	} else {
		$trans = 0;
		$token = $_POST['token'];
		try {
			$pdo = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD);
			$pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
			$sql = 'USE db_camagru;';
			$pdo->exec($sql);
			$sql = "SELECT login, passwd, mail, token FROM wt_conf WHERE token = :token;";
			$pre = $pdo->prepare($sql, array(PDO::ATTR_CURSOR => PDO::CURSOR_FWDONLY));
			$pre->execute(array(":token" => $token));
			$ret = $pre->fetchAll();
			if (!isset($ret[0]['token'])) {
				$_POST['error'] = "This code does not exists. Get it on your mail box!";
				header("Location: ../validate.php");
			} else {
				$user = array("id" => hash("md5", microtime().rand()), "login" => $ret[0]['login'], "passwd" => $ret[0]['passwd'], "mail" => $ret[0]["mail"]);
				$trans = 1;
				$pdo->beginTransaction();
				$sql = "DELETE FROM wt_conf WHERE token = :token;";
				$pre = $pdo->prepare($sql, array(PDO::ATTR_CURSOR => PDO::CURSOR_FWDONLY));
				$pre->execute(array(':token' => $token));
				$pdo->commit();
				$trans = 0;
				$trans = 1;
				$pdo->beginTransaction();
				$sql = "INSERT INTO users (id, login, passwd) VALUES (:id, :login, :passwd);";
				$pre = $pdo->prepare($sql, array(PDO::ATTR_CURSOR => PDO::CURSOR_FWDONLY));
				$pre->execute(array('id' => $user['id'], ':login' => $user['login'], ':passwd' => $user['passwd']));
				$pdo->commit();
				$trans = 0;
				$trans = 1;
				$pdo->beginTransaction();
				$sql = "INSERT INTO user_info (id, mail, comment) VALUES (:id, :mail, :comment);";
				$pre = $pdo->prepare($sql, array(PDO::ATTR_CURSOR => PDO::CURSOR_FWDONLY));
				$pre->execute(array('id' => $user['id'], 'mail' => $user['mail'], 'comment' => null));
				$pdo->commit();
				$trans = 0;
				$pdo = null;
			}
		} catch (PDOException $error) {
			if ($trans) {
				$pdo->rollBack();
			}
			$pdo = null;
			$_POST['error'] = 'An error occured while connecting to database';
			header("Location: ../validate.php");
		}
		unset($pdo, $pre, $sql, $ret, $user, $token, $trans);
		if (!isset($_POST['error']))
			header("Location: ../index.php");
	}
?>
