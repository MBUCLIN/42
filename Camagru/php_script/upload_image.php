<?php
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
	function	imageresize($img, $w, $h) {
		$width = imagesx($img);
		$height = imagesy($img);
		$dest = imagecreatetruecolor($w, $h);
		if (imagecopyresized($dest, $img, 0, 0, 0, 0, $w, $h, $width, $height) === true) {
			imagedestroy($img);
			return ($dest);
		} else {
			return (false);
		}

	}
	function	image_puttofilepng($img, $name, $path) {
		if (file_exists($path . $name . ".png")) {
			return (FALSE);
		}
		imagepng($img, $path . $name . ".png");
		imagedestroy($img);
		return (TRUE);
	}
	function	image_resized($name, $src_dir, $dest_dir, $percent) {
		$img = imagecreatefrompng($src_dir . $name . ".png");
		list($width, $height) = getimagesize($src_dir . $name . ".png");
		$newwidth = $width * $percent;
		$newheight = $height * $percent;
		$dest = imagecreatetruecolor($newwidth, $newheight);
		$true = imagecopyresized($dest, $img, 0, 0, 0, 0, $newwidth, $newheight, $width, $height);
		if ($true) {
			imagepng($dest, $dest_dir . $name . ".png");
			return (true);
		} else
			return (false);
	}
	session_start();
	include("../config/database.php");
	if (!isset($_SESSION['logged_on_us'])) {
		$_POST['error'] = "No user connected";
		echo "Error user";
	} else {
		if (!isset($_POST['img']) || !isset($_POST['pos']) || !isset($_POST['tag'])) {
			$_POST['error'] = "POST request is not set well";
			echo "Error POST";
		} else {
			$img = $_POST['img'];
			$pos = htmlspecialchars($_POST['pos']);
			$tag = htmlspecialchars($_POST['tag']);
			$file_name = hash("md5", time().rand());
			$cursor = strpos($img, ',') + 1;
			$img = substr($img, $cursor);
			$img = base64_decode($img);
			$fd = finfo_open();
			$info = finfo_buffer($fd, $img, FILEINFO_MIME_TYPE);
			finfo_close($fd);
			if (!strstr($info, "image/")) {
				$_POST['error'] = "No image file";
				echo "Error file";
			} else {
				$meme = prepare_posmeme($pos);
				unset($info, $cursor, $fd, $pos);
				$img = imagecreatefromstring($img);
				$img = imageresize($img, 320, 240);
				if (!$img) {
					$_POST['error'] = "Can't create image object";
					echo "Error image object";
				} else {
					$img = merge_to_finalimg($img, $meme);
					unset($meme);
					if (!$img) {
						$_POST['error'] = "Merged failed";
						echo "Error merge";
					} else {
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
								$_POST['error'] = "No login for you";
								echo "Error id";
							} else {
								$id = $ret[0]['id'];
								$pdo->beginTransaction();
								$trans = 1;
								$sql = "INSERT INTO images (`id_img`, `id_user`) VALUES (:id_img, :id_user);";
								$pre = $pdo->prepare($sql, array(PDO::ATTR_CURSOR => PDO::CURSOR_FWDONLY));
								$pre->execute(array('id_img' => $file_name, 'id_user' => $id));
								$pdo->commit();
								$trans = 0;
								$pdo->beginTransaction();
								$trans = 1;
								$sql = "INSERT INTO img_info VALUES (:id_img, :tag, 'No likes yet', 'No comment yet');";
								$pre = $pdo->prepare($sql, array(PDO::ATTR_CURSOR => PDO::CURSOR_FWDONLY));
								$pre->execute(array('id_img' => $file_name, 'tag' => $tag));
								$pdo->commit();
								$trans = 0;
								$pdo = null;
							}
						} catch (PDOException $error) {
							if ($trans) {
								$pdo->rollBack();
								$_POST['error'] = "Transaction failed";
								echo "Error transaction";
							} else {
								$_POST['error'] = "No connection database";
								echo "Error database";
							}
						}
						if (!image_puttofilepng($img, $file_name, "../images/")) {
							$_POST['error'] = "Could not save in the file";
							echo "Error copy to file";
						} else if (!image_resized($file_name, "../images/", "../resized/", 0.5)) {
							$_POST['error'] = "Could not copy resize";
							echo "Error resize copy";
						}
						unset($pdo, $sql, $pre, $ret, $trans, $file_name, $id, $tag, $meme, $img);
						if (!isset($_POST['error'])) {
							echo "Success";
						}
					}
				}
			}
		}
	}
?>
