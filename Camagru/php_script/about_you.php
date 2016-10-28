<?php
	if (!isset($_SESSION['logged_on_us'])) {
		header("Location: ../index.php");
	} else {
		include("config/database.php");
		$info = array("login" => $_SESSION['logged_on_us']);
		try {
			$pdo = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD);
			$pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
			$pdo->exec("USE db_camagru;");
			$sql = "SELECT `id` FROM users WHERE `login` = :login;";
			$pre = $pdo->prepare($sql, array(PDO::ATTR_CURSOR => PDO::CURSOR_FWDONLY));
			$pre->execute(array("login" => $_SESSION['logged_on_us']));
			$ret = $pre->fetchAll();
			if (!isset($ret[0]['id'])) {
				$_POST['error'] = "No id for that login";
			} else {
				$sql = "SELECT `mail` FROM user_info WHERE `id` = :id;";
				$pre = $pdo->prepare($sql, array(PDO::ATTR_CURSOR => CURSOR_FWDONLY));
				$pre->execute(array('id' => $ret[0]['id']));
				$ret = $pre->fetchAll();
				if (!isset($ret[0]['mail'])) {
					$_POST['error'] = "No mail found";
				} else {
					$info['mail'] = $ret[0]['mail'];
				}
			}
			$pdo = null;
		} catch (PDOException $error) {
			$_POST['error'] = "An error occured while connecting to database";
		}
		unset($pdo, $sql, $pre, $ret, $DB_USER, $DB_DSN, $DB_PASSWORD);
	}
?>
