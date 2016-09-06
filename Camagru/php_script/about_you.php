<?php
	include("config/database.php");
	$info = array('login' => $_SESSION['logged_on_us'], 'mail' => null, 'id' => null, 'comment' => null);
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
			$info['id'] = $ret[0]['id'];
			$sql = "SELECT `mail`, `comment` FROM user_info WHERE `id` = :id;";
			$pre = $pdo->prepare($sql, array(PDO::ATTR_CURSOR => CURSOR_FWDONLY));
			$pre->execute(array('id' => $info['id']));
			$ret = $pre->fetchAll();
			if (!isset($ret[0]['mail'])) {
				$_POST['error'] = "no mail found";
			} else {
				$info['mail'] = $ret[0]['mail'];
				if ($ret[0]['comment'] === null) {
					$info['comment'][] = "No commentary yet";
				} else {
					$unse = unserialize($ret[0]['comment']);
					$info['comment'] = $unse;
				}
			}
		}
		$pdo = null;
		unset($pdo, $sql, $pre, $ret, $unse);
	} catch (PDOException $error) {
		$_POST['error'] = "An error occured while connecting to database";
	}
?>
