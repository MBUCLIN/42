<?php
	session_start();
	if (!isset($_SESSION['logged_on_us'])) {
		$_POST['error'] = "Error session";
		echo "No user connected";
	} else {
		include("../config/database.php");
		if (!isset($_POST['ids'])) {
			$_POST['error'] = "Error POST";
			echo "No image id send";
		} else {
			$file_names = explode(":", htmlspecialchars($_POST['ids']));
			$trans = 0;
			try {
				$pdo = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD);
				$pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
				$pdo->exec("USE db_camagru;");
				$sql = "SELECT `id` FROM users WHERE `login` = :login;";
				$pre = $pdo->prepare($sql, array(PDO::ATTR_CURSOR => PDO::CURSOR_FWDONLY));
				$pre->execute(array('login' => $_SESSION['logged_on_us']));
				$ret = $pre->fetchAll();
				if (!isset($ret[0]['id'])) {
					$_POST['error'] = "Error user";
					echo "No id for this user";
				} else {
					$id_user = $ret[0]['id'];
					$sql = "SELECT `id_user` FROM images WHERE `id_img` = :id_img;";
					$pre = $pdo->prepare($sql, array(PDO::ATTR_CURSOR => PDO::CURSOR_FWDONLY));
					foreach($file_names as $key => $value) {
						$pre->execute(array('id_img' => $file_names[$key]));
						$ret = $pre->fetchAll();
						if (!isset($ret[0]['id_user']) || $id_user !== $ret[0]['id_user']) {
							$_POST['error'] = "Id doesn't match";
							echo "No match found";
							die();
						}
					}
					foreach($file_names as $key => $value) {
						$trans = 1;
						$pdo->beginTransaction();
						$sql = "DELETE FROM images WHERE `id_img` = :id_img;";
						$pre = $pdo->prepare($sql, array(PDO::ATTR_CURSOR => PDO::CURSOR_FWDONLY));
						$pre->execute(array('id_img' => $file_names[$key]));
						$pdo->commit();
						$trans = 0;
					}
					foreach ($file_names as $key => $value) {
						$trans = 1;
						$pdo->beginTransaction();
						$sql = "DELETE FROM img_info WHERE `id_img` = :id_img;";
						$pre = $pdo->prepare($sql, array(PDO::ATTR_CURSOR => PDO::CURSOR_FWDONLY));
						$pre->execute(array('id_img' => $file_name[$key]));
						$pdo->commit();
						$trans = 0;
					}
				}
			} catch (PDOException $error) {
				if ($trans) {
					$_POST['error'] = "Error transaction";
					echo "The update has failed";
					echo $error->getMessage();
					$pdo->rollBack();
					$pdo = null;
				} else {
					$_POST['error'] = "Error database";
					echo "Failed to connect database";
					$pdo = null;
				}
			}
			$pdo = null;
			if (!isset($_POST['error'])) {
				echo "Success";
				foreach($file_names as $key => $value) {
					unlink("../images/" . $file_names[$key] . ".png");
					unlink("../resized/" . $file_names[$key] . ".png");
				}
				unset($pdo, $sql, $pre, $ret, $id_user, $file_names, $trans);
			} else {
				unset($pdo, $sql, $pre, $ret, $id_user, $file_names, $trans);
			}
		}
	}
?>
