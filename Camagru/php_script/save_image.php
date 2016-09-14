<?php
	//function part
	function	get_imagefrompict($pic, $fname, $fpath) {
		$encoded = str_replace("data:image/png;base64,", "", $pic);
		$encoded = str_replace(' ', '+', $encoded);
		$decoded = base64_decode($encoded);
		$image = imagecreatefromstring($decoded);
		if ($image) {
			return ($image);
		}
		return (FALSE);
	}
	function	prepare_posmeme($position) {
		$position = explode(":", $position);
		$submeme = array("num" => null, "x" => null, "y" => null);
		$meme = array();
		if (is_array($position)) {
			foreach ($position as $key => $value) {
				$subtab = explode(",", $position[$key]);
				if (isset($subtab[1])) {
					$submeme["num"] = $subtab[0];
					$submeme["x"] = $subtab[1];
					$submeme["y"] = $subtab[2];
					$meme[] = $submeme;
				}
			}
			return ($meme);
		} else {
			return (FALSE);
		}
	}
	function	merge_to_finalimg($image, $meme) {
		foreach ($meme as $i => $value) {
			echo "../face/face" . $meme[$i]['num'] . ".png";
			$merge = imagecreatefrompng("../face/face" . $meme[$i]["num"] . ".png");
			$size = getimagesize("../face/face" . $meme[$i]["num"] . ".png");
			imagecolortransparent($merge, imagecolorat($merge, 0, 0));
			if (imagecopymerge($image, $merge, $meme[$i]["x"], $meme[$i]["y"], 0 , 0, $size[0], $size[1], 100) === FALSE) {
				return (FALSE);
			}
			imagedestroy($merge);
		}
		return ($image);
	}
	function	image_puttofilepng($img, $name, $path) {
		if (file_exists($path . $name . ".png")) {
			return (FALSE);
		}
		imagepng($img, $path . $name . ".png");
		imagedestroy($img);
		return (TRUE);
	}
	//script part
	session_start();
	include("../config/database.php");
	if (!isset($_SESSION['logged_on_us'])) {
		$_POST['error'] = "No user logged";
		echo "Error log";
	} else if (!isset($_POST['image']) || !isset($_POST['pos'])) {
		$_POST['error'] = "Post not set";
		echo "Error request";
	} else {
		$pic64 = $_POST['image'];
		$pos = $_POST['pos'];
		$file_name = hash("md5", time().rand());
		$image = get_imagefrompict($pic64, $file_name, "../images/");
		unset($pic64);
		imagepng($image, "../toto.png");
		if ($image !== FALSE) {
			$meme = prepare_posmeme($pos);
			$image = merge_to_finalimg($image, $meme);
			unset($meme, $pos);
			if ($image !== FALSE) {
				if (image_puttofilepng($image, $file_name, "../images/") !== FALSE) {
					$trans = 0;
					unset($image);
					try {
						$pdo = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD);
						$pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
						$pdo->exec("USE db_camagru;");
						$sql = "SELECT `id` FROM users WHERE `login` = :login;";
						$pre = $pdo->prepare($sql, array(PDO::ATTR_CURSOR => PDO::CURSOR_FWDONLY));
						$pre->execute(array("login" => $_SESSION['logged_on_us']));
						$ret = $pre->fetchAll();
						if (!isset($ret[0]['id'])) {
							$_POST['error'] = "No id for this login";
							echo "Error id";
						} else {
							$trans = 1;
							$pdo->beginTransaction();
							$sql = "INSERT INTO images VALUES (:img, :id);";
							$pre = $pdo->prepare($sql, array(PDO::ATTR_CURSOR => PDO::CURSOR_FWDONLY));
							$pre->execute(array('img' => $file_name, 'id' => $ret[0]['id']));
							$pdo->commit();
							$trans = 0;
						}
					} catch (PDOException $error) {
						$_POST['error'] = "PDO error";
						if ($trans) {
							$pdo->rollBack();
							echo "Error transaction";
						} else {
							echo "Error connection";
						}
					}
					unset($pdo, $sql, $pre, $ret, $file_name, $trans);
				} else {
					echo "Error file";
				}
			} else {
				echo "Error merge";
			}
		} else {

			echo "Error image";
		}
		if (!isset($_POST['error'])) {
			echo "Succes";
		}
	}
?>
