<?php
	session_start();
	if (!isset($_SESSION['logged_on_us'])) {
		$_POST['error'] = "No user logged";
		echo "Error log";
	} else if (!isset($_POST['num'])) {
		$_POST['error'] = "The POST request is not set";
		echo "Error post";
	} else {
		include ("../config/database.php");
		$number = $_POST['num'];
		try {
			$pdo = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD);
			$pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
			$pdo->exec("USE db_camagru");
			$sql = "SELECT `id_img`, `id_user` FROM images ORDER BY `id` DESC LIMIT 10 OFFSET $number";
			$pre = $pdo->prepare($sql);
			$pre->execute();
			$ret = $pre->fetchAll();
			if ($ret && $ret[0]) {
				$key = 0;
				while (isset($ret[$key])) {
						$array[$key][0] = $ret[$key]['id_img'];
						$sql = "SELECT `login` FROM users WHERE `id` = :id";
						$pre = $pdo->prepare($sql, array(PDO::ATTR_CURSOR => CURSOR_FWDONLY));
						$pre->execute(array('id' => $ret[$key]['id_user']));
						$login = $pre->fetchAll();
						$array[$key][1] = $login[0]['login'];
						$sql = "SELECT `array_comment` `array_like` FROM img_info WHERE `id_img` = :id_img";
						$pre = $pdo->prepare($sql, array(PDO::ATTR_CURSOR => PDO::CURSOR_FWDONLY));
						$pre->execute(array('id_img' => $ret[$key]['id_img']));
						$landc = $pre->fetchAll();
						if ($landc[0]['array_comment'])
							$array[$key][2] = $landc[0]['array_comment'];
						if ($landc[0]['array_like'])
							$array[$key][3] = $landc[0]['array_like'];
						$key++;
				}
				unset($pdo, $sql, $pre, $ret, $key, $login, $landc);
			}
		} catch (PDOException $error) {
			$_POST['error'] = "Error DB";
			echo " Error database";
		}
		unset($DB_DSN, $DB_USER, $DB_PASSWORD);
		if (!isset($_POST['error'])) {
			echo "Success";
			if ($array && $array[0]) {
				foreach ($array as $key => $value) {
					echo ";(" . $array[$key][0] . ";" . $array[$key][1];
					if ($array[$key][2])
						echo ";" . $array[$key][2];
					if ($array[$key][3])
						echo ";" . $array[$key][3];
					echo ")";
				}
				echo $number;
				unset($number, $array);
			}
		}
	}
?>
