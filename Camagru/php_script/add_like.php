<?php
	session_start();
	include("../config/database.php");
	if (!isset($_SESSION['logged_on_us'])) {
		$_POST['error'] = "No user logged";
		echo "Error Logged";
	} else {
		if (!isset($_POST['id'])) {
			$_POST['error'] = "Post not set";
			echo "Error qwery";
		} else {
			$id_img = htmlspecialchars($_POST['id']);
			$trans = 0;
			try {
				$pdo = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD);
				$pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
				$pdo->exec("USE db_camagru;");
				$sql = "SELECT `array_like` FROM img_info WHERE `id_img` = :id_img";
				$pre = $pdo->prepare($sql, array(PDO::ATTR_CURSOR => PDO::CURSOR_FWDONLY));
				$pre->execute(array('id_img' => $id_img));
				$ret = $pre->fetchAll();
				if (!isset($ret[0]['array_like'])) {
					$_POST['error'] = "Error like";
					echo "Error getting likes";
				} else {
					$ret = $_SESSION['logged_on_us'] . ""
				}
			} catch (PDOException $error) {
				if ($trans) {
					$_POST['error'] = "error update";
					echo "Error transaction";
				} else {
					$_POST['error'] = "error db";
					echo "Error database";
				}
				unset($trans, $pdo, $sql, $pre, $ret, $id_img);
			}
		}
	}
	unset($DB_DSN, $DB_USER, $DB_PASSWORD);
?>
