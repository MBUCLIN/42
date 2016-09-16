<?php
	include("config/database.php");
	if (isset($_SESSION['logged_on_us'])) {
		header("Location: index.php");
	} else if (!isset($_POST['login']) || !isset($_POST['mail'])) {
		header("Location: forgot_password.php");
	} else {
		$trans = 0;
		$login = htmlspecialchars($_POST['login']);
		$mail = htmlspecialchars($_POST['mail']);
		try {
			$pdo = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD);
			$pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
			$sql = "USE db_camagru;";
			$pdo->exec($sql);
			$sql = "SELECT `id` FROM users WHERE `login` = :login";
			$pre = $pdo->prepare($sql, array(PDO::ATTR_CURSOR => PDO::CURSOR_FWDONLY));
			$pre->execute(array("login" => $login));
			$ret = $pre->fetchAll();
			if (!isset($ret[0]['id'])) {
				$_POST['error'] = "The login that you entered isn't valid.";
				header("Location: forgot_password.php");
			} else {
				$id = $ret[0]['id'];
				$sql = "SELECT `mail` FROM user_info WHERE `id` = :id";
				$pre = $pdo->prepare($sql, array(PDO::ATTR_CURSOR => PDO::CURSOR_FWDONLY));
				$pre->execute(array("id" => $id));
				$ret = $pre->fetchAll();
				if (!isset($ret[0]['mail'])) {
					$_POST['error'] = "A mail could not been found for your login ..";
					header("Location: forgot_password.php");
				} else {
					$trans = 1;
					$pdo->beginTransaction();
					$token = hash('md5', microtime().rand());
					$sql = "UPDATE users SET `passwd` = :newpassword WHERE `id` = :id";
					$pre = $pdo->prepare($sql, array(PDO::ATTR_CURSOR => PDO::CURSOR_FWDONLY));
					$pre->execute(array('newpassword' => hash('sha512', $token), 'id' => $id));
					$pdo->commit();
					$trans = 0;
				}
			}
		} catch (PDOException $error) {
			if ($trans) {
				$pdo->rollBack();
			}
			$pdo = null;
			$_POST['error'] = "An error occured while connection to database";
			header("Location: index.php");
		}
		$msg = "Hi dear custumer,

	You seem to have forgotten your password!
	I'm a nice guy so, i'll give you a new one!!
	Don't forget to change it for the next conexion!
	You're new password is : " . $token . ".
	Have a nice day with Camagru!";
		$msg = wordwrap($msg, 70, '\n');
		if (mail($mail, 'New password for Camagru', $msg) === FALSE) {
			$_POST['error'] = 'Could not send the mail.';
			header("Location: forgot_password.php");
		}
		header("Location: index.php");
		unset($pdo, $sql, $ret, $pre, $login, $mail, $DB_DSN, $DB_USER, $DB_PASSWORD, $msg, $token, $id);
	}
?>
