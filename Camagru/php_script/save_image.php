<?php
	//function part
	// *** CREATE AN IMAGE OBJECT FROM A B64 IMAGE STRING *** //
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
	// *** CREATE AN ARRAY WITH THE NUMBER OF THE MEME AND THE POSITION THEIR THE IMAGE *** //
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
	// *** MERGE THE MEME WITH THE IMAGE AND RETURN THE IMAGE OBJECT *** //
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
	// *** CREATE A PNG IMAGE FILE WITH AN IMAGE OBJECT *** //
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
	} else if (!isset($_POST['image']) || !isset($_POST['pos']) || !isset($_POST['tag'])) {
		$_POST['error'] = "Post not set";
		echo "Error request";
	} else {
		$tag = htmlspecialchars($_POST['tag']);
		$pic64 = $_POST['image'];
		$pos = htmlspecialchars($_POST['pos']);
		$file_name = hash("md5", time().rand());
		$image = get_imagefrompict($pic64, $file_name, "../images/");
		unset($pic64);
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
							$sql = "INSERT INTO images VALUES (:imgI, :id);";
							$pre = $pdo->prepare($sql, array(PDO::ATTR_CURSOR => PDO::CURSOR_FWDONLY));
							$pre->execute(array('imgI' => $file_name, 'id' => $ret[0]['id']));
							$pdo->commit();
							$pdo->beginTransaction();
							$sql = "INSERT INTO img_info VALUES (:imgII, :tag, :likes, :comment);";
							$pre = $pdo->prepare($sql, array(PDO::ATTR_CURSOR => PDO::CURSOR_FWDONLY));
							$pre->execute(array('imgII' => $file_name, 'tag' => $tag, 'likes' => "No likes yet", 'comment' => "No comment yet"));
							$pdo->commit();
							$trans = 0;
							$pdo = null;
						}
					} catch (PDOException $error) {
						if (file_exists("../images/" . $file_name . ".png")) {
							unlink("../images/" . $file_name . ".png");
						}
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
					$_POST['error'] = "Could not create the file";
					echo "Error file";
				}
			} else {
				$_POST['error'] = "Could not merge the images";
				echo "Error merge";
			}
		} else {
			$_POST['error'] = "Could not create an image from string";
			echo "Error image";
		}
		if (!isset($_POST['error'])) {
			echo "Succes";
		}
	}
?>
