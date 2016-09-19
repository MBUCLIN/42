<?php
	session_start();
	include("../config/database.php");
	if (!isset($_SESSION['logged_on_us'])) {
		$_POST['error'] = "No user logged";
		echo "No logged user:";
	} else {
		$user = $_SESSION['logged_on_us'];
		$gotit = $_POST['id'];
		$gotit = explode(":", $gotit);
		$trans = 0;
		try {
			$pdo = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD);
			$pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
			$pdo->exec("USE db_camagru;");
			$sql = "SELECT `id` FROM users WHERE `login` = :login;";
			$pre = $pdo->prepare($sql, array(PDO::ATTR_CURSOR => PDO::CURSOR_FWDONLY));
			$pre->execute(array("login" => $user));
			$ret = $pre->fetchAll();
			if (!isset($ret[0]['id'])) {
				$_POST['error'] = "Error id";
				echo "No login for that user:";
			} else {
				$sql = "SELECT `id_img` FROM images WHERE `id` = :id AND `id_img` <> :ids;";
				$pre = $pdo->prepare($sql, array(PDO::ATTR_CURSOR => PDO::CURSOR_FWDONLY));
				foreach ($gotit as $key => $value) {
					$pre->execute(array("id" => $ret[0]['id'], "ids" => $gotit[$key]));
				}
				$ret = $pre->fetchAll();
				$pdo = null;
			}
		} catch (PDOException $error) {
			if ($trans) {
				$pdo->rollBack();
				$pdo = null;
			}
			$_POST['error'] = "Error Transaction";
			echo $error->getMessage() . ":";
		}
		if (!isset($_POST['error'])) {
			echo "Success";
			foreach ($ret as $key => $value) {
				echo ":" . $ret[$key]['id_img'];
			}
		}
	}

?>
