<?php
	include("config/database.php");
	$path = "images/";
	try {
		$pdo = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD);
		$pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
		$pdo->exec("USE db_camagru");
		$sql = "SELECT `id` FROM users WHERE `login` = :login;";
		$pre = $pdo->prepare($sql, array(PDO::ATTR_CURSOR => PDO::CURSOR_FWDONLY));
		$pre->execute(array("login" => $_SESSION['logged_on_us']));
		$ret = $pre->fetchAll();
		if (!isset($ret[0]['id'])) {
			echo "No id for your login !!";
		} else {
			$sql = "SELECT `id_img` FROM images WHERE id = :id;";
			$pre = $pdo->prepare($sql, array(PDO::ATTR_CURSOR => PDO::CURSOR_FWDONLY));
			$pre->execute(array("id" => $ret[0]['id']));
			$ret = $pre->fetchAll();
			if (!isset($ret[0]['id_img'])) {
				$path = "no_images/";
				$files = scandir($path);
				foreach ($files as $key => $value) {
					if ($files[$key][0] !== '.') {
						$images[] = $files[$key];
					}
				}
				unset($files);
			} else {
				$images = array();
				foreach ($ret as $key => $value) {
					$images[] = $ret[$key]['id_img'] . ".png";
				}
				$pdo = null;
				unset($pdo, $sql, $pre, $ret);
			}
		}
	} catch (PDOException $error) {
		echo $error->getMessage();
		if (!isset($images)) {
			$path = "no_images/";
			$files = scandir($path);
			foreach ($files as $key => $value) {
				if ($files[$key][0] !== '.') {
					$images[] = $files[$key];
				}
			}
			unset($files);
		}
	}
	foreach ($images as $key => $value) {
		if ($key < 10) {
			echo "<img src='" . $path . $images[$key] . "' id='last" . $key . "' class='last_pictures'/>";
		}
	}

?>
