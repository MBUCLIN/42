<?php
	session_start();
	include("../config/database.php");
	if (!isset($_SESSION['logged_on_us'])) {
		$_POST['error'] = "No user logged";
		echo "Error log";
	} else {
		if (!isset($_POST['comment']) || !isset($_POST['id_img'])) {
			$_POST['error'] = "No comment sended??";
			echo "Error comment";
		} else {
			$id_img = htmlspecialchars(trim($_POST['id_img']));
			$comment = filter_var($_POST['comment'], FILTER_SANITIZE_SPECIAL_CHARS);
			$trans = 0;
			$comment = "(" . $_SESSION['logged_on_us'] . "{,}" . $comment . ")";
			try {
				$pdo = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD);
				$pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
				$pdo->exec("USE db_camagru");
				$sql = "SELECT `id_user` FROM images WHERE `id_img` = :id_img";
				$pre = $pdo->prepare($sql, array(PDO::ATTR_CURSOR => PDO::CURSOR_FWDONLY));
				$pre->execute(array('id_img' => $id_img));
				$ret = $pre->fetchAll();
				if (!isset($ret[0]['id_user'])) {
					$_POST['error'] = "No id_user for that id_img";
					echo "Error IDS";
				} else {
					$proprio = $ret[0]['id_user'];
					unset($ret, $sql, $pre);
					$sql = "SELECT `array_comment` FROM img_info WHERE `id_img` = :id_img";
					$pre = $pdo->prepare($sql, array(PDO::ATTR_CURSOR => PDO::CURSOR_FWDONLY));
					$pre->execute(array('id_img' => $id_img));
					$ret = $pre->fetchAll();
					if (!isset($ret[0]['array_comment'])) {
						$_POST['error'] = "No column comment on this picture";
						echo "Error database";
					} else {
						$cpy_comment = $comment;
						$last_comment = $ret[0]['array_comment'];
						unset($ret, $sql, $pre);
						if ($last_comment !== "No comment yet") {
							$comment = $last_comment . $comment;
						}
						$trans = 1;
						$pdo->beginTransaction();
						$sql = "UPDATE img_info SET `array_comment` = :comment WHERE `id_img` = :id_img";
						$pre = $pdo->prepare($sql, array(PDO::ATTR_CURSOR => PDO::CURSOR_FWDONLY));
						$pre->execute(array('comment' => $comment, 'id_img' => $id_img));
						$pdo->commit();
						$trans = 0;
						unset($sql, $pre, $ret);
						$sql = "SELECT `mail` FROM user_info WHERE `id` = :proprio";
						$pre = $pdo->prepare($sql, array(PDO::ATTR_CURSOR => PDO::CURSOR_FWDONLY));
						$pre->execute(array('proprio' => $proprio));
						$ret = $pre->fetchAll();
						if (!isset($ret[0]['mail'])) {
							$_POST['error'] = "No mail for that user";
							echo "Error mail";
						} else {
							$mail = $ret[0]['mail'];
						}
						unset($pdo, $pre, $ret, $sql, $last_comment, $comment, $id_img, $proprio);
					}
				}
			} catch (PDOException $error) {
				if ($trans == 1) {
					$_POST['error'] = "Error transaction";
					echo "Error Transaction";
				} else {
					$_POST['error'] = "Error database";
					echo "Error connecting database";
				}
			}
			if (!isset($_POST['error'])) {
				echo "Success";
				echo ";" . $cpy_comment;
				$responseMail = "Hello,

	One of your image have a new commentary from ". $_SESSION['logged_on_us'] . "!";
				mail($mail, "New commentary", $responseMail);
				unset($responseMail, $mail, $proprio);
			}
		}
	}
	unset($DB_DSN, $DB_USER, $DB_PASSWORD);
?>
