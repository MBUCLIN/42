<?php
	//function part
	function	filepng($pic, $fname, $fpath) {
		$encoded = str_replace("data:image/png;base64,", "", $pic);
		$encoded = str_replace(' ', '+', $encoded);
		$decoded = base64_decode($encoded);
		$image = imagecreatefromstring($decoded);
		while (file_exists($fpath . $fname . ".png")) {
			$fname = hash("md5", time().rand());
		}
		if ($image) {
			imagepng($image, $fpath . $fname .".png");
			imagedestroy($image);
			return ($fname);
		}
		return (null);
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
			return (null);
		}
	}
	function	merge_to_finalimg($file_path, $meme) {
		
		foreach ($meme as $i => $value) {

		}
	}
	//script part
	session_start();
	include("../config/database.php");
	if (!isset($_SESSION['logged_on_us'])) {
		$_POST['error'] = "Logged out";
		echo "Logged out user";
	} else if (!isset($_POST['image']) || !isset($_POST['pos'])) {
		echo "No image or size set";
	} else {
		$pic = $_POST['image'];
		$pos = $_POST['pos'];
		$file_name = hash("md5", time().rand());
		$file_name = filepng($pic, $file_name, "../images/");
		if ($file_name !== null) {
			$meme = prepare_posmeme($pos);

		} else {
			echo "Error while creating a file";
		}
		if (!isset($_POST['error'])) {
			echo "succes";
		}
	}
?>
