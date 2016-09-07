<?php
	include("config/database.php");
	try {
		$pdo = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD);
		$pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
		$pdo->exec("USE db_camagru");
		$sql = "SELECT `id` FROM users WHERE `login` = :login;";
		$pre = $pdo->prepare($sql, array(PDO::ATTR_CURSOR => PDO::CURSOR_FWDONLY));
		$pre->execute(array("login" => $_SESSION['logged_on_us']);
		$ret = $pre->fetchAll();
		if (!isset($ret[0]['login'])) {
			$_POST['error'] = "you does not exists";
		} else {

		}
	} catch (PDOException $error) {

	}
	unset($pdo, $pre, $sql, $ret, $DB_DSN, $DB_USER, $DB_PASSWORD)
?>
