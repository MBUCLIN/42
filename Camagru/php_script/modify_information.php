<?php
	include("../config/database.php");

	if (!isset($_SESSION['logged_on_us'])) {
		header("Location: ../index.php");
	} else if (!isset($_POST['oldpw']) || !isset($_POST['newpw']) || !isset($_POST['confpw'])) {
		if (!isset($_POST['pw']) || !isset($_POST['mail'])) {
			header("Location: ../change_password.php");
		} else {
			$mail = htmlspecialchars($_POST['mail']);
			$pw = hash('sha512', htmlspecialchars($_POST['pw']));
		}
	} else if (!isset($_POST['mail']) || !isset($_POST['pw'])) {
		if (!isset($_POST['oldpw']) || !isset($_POST['newpw']) || !isset($_POST['confpw'])) {
			header("Location: ../change_password.php");
		} else {
			$pw = hash('sha512', htmlspecialchars($_POST['oldpw']));
			$newpw = hash('sha512', htmlspecialchars($_POST['newpw']));
			$confpw = hash('sha512', htmlspecialchars($_POST['confpw']));
			if ($newpw !== $confpw) {
				$_POST['error'] = "The new password and his confirmation has to be an exact match.";
				header("Location: ../change_password.php");
			}
		}
	}
	try {
		$pdo = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD);
		$pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
		$pdo->exec("USE db_camagru;");
		$sql = "SELECT `id`, `passwd` FROM users WHERE `login` = :login";
		$pre = $pdo->prepare($sql, array(PDO::ATTR_CURSOR => PDO::CURSOR_FWDONLY));
		$pre->execute(array("login" => $_SESSION['logged_on_us']));
		$ret = $pre->fetchAll();
		if (!isset($ret[0]['id']) || !isset($ret[0]['passwd'])) {
			$_POST['error'] = 'Error database ...';
			$_SESSION['logged_on_us'] = null;
			session_destroy();
			header("Location: ../index.php");
		} else {
			if ($ret[0]['passwd'] !== $pw) {
				$_POST['error'] = 'Wrong password given...';
				header("Location: ../change_password.php");
			} else {
				$pdo->beginTransaction();
				if (isset($mail)) {
					$sql = "UPDATE user_info SET `mail` = :mail WHERE `id` = :id;";
					$pre = $pdo->prepare($sql, array(PDO::ATTR_CURSOR => PDO::CURSOR_FWDONLY));
					$pre->execute(array("mail" => $mail, "id" => $ret[0]['id']));
				} else {
					$sql = "UPDATE users SET `passwd` = :passwd WHERE `id` = :id;";
					$pre = $pdo->prepare($sql, array(PDO::ATTR_CURSOR => PDO::CURSOR_FWDONLY));
					$pre->execute(array("passwd" => $newpw, "id" => $ret[0]['id']));
				}
				$pdo->commit();
			}
		}
		unset($pdo, $sql, $pre, $ret, $pw, $mail, $newpw, $confpw);
	} catch (PDOException $error) {
		header("Location: ../index.php");
	}
	if (!isset($_POST['error'])) {
		header("Location: ../index.php");
	}
?>
