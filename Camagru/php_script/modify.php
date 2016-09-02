<?php
	include("config/database.php");

	$login = $_SESSION['logged_on_us'];
	try {
		$pdo = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD);
		$pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
		$pdo->exec("USE db_camagru;");
		$sql = "SELECT `id` FROM users WHERE `login` = :login";
		$pre = $pdo->prepare($sql, array(PDO::ATTR_CURSOR => PDO::CURSOR_FWDONLY));
		$pre->execute(array('login' => $login));
		$ret = $pre->fetchAll();
		if (!isset($ret[0]['id'])) {
			$_POST['error'] = 'login was not found in our database';
			echo '<div id="error"><p>' . $_POST['error'] . '</p></div>';
		} else {
			$sql = "SELECT `mail` FROM user_info WHERE `id` = :id;";
			$pre = $pdo->prepare($sql, array(PDO::ATTR_CURSOR => PDO::CURSOR_FWDONLY));
			$pre->execute(array('id' => $ret[0]['id']));
			$ret = $pre->fetchAll();
			if (!isset($ret[0]['mail'])) {
				$_POST['error'] = 'No mail address find for your login';
				echo '<div id="error"><p>' . $_POST['error'] . '</p></div>';
			} else {
				$mail = $ret[0]['mail'];
				unset($pdo, $sql, $ret, $pre);
			}
		}
	} catch (PDOExecption $error) {
		$_POST['error'] = 'Could not connect to database';
		echo '<div id="error"><p>' . $_POST['error'] . '</p></div>';
	}
	if (!isset($_POST['error'])) {
		$mod_pass = "<div id='mod_pass' name='change_pass'>";
		$mod_mail = "<div id='mod_mail' name='change_mail'>";
		$button_mail = "<button id='mail_send' class='mod' name='mail_click'>Modify</button>";
		$button_pass = "<button id='pass_send' class='mod' name='pass_click'>Modify</button>";
		$end_div = "</div>";
		echo $mod_pass . "<p>Modify password :</p>" . $button_pass . $end_div;
		echo $mod_mail . "<p>Modify e mail   :</p>" . $button_mail . $end_div;
	}
?>
