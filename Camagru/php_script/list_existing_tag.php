<?php
	include("config/database.php");
	$tags = array("troll", "fun", "wtf", "cute", "freedom", "cantcategorize");
	$existing = array();
	try {
		$pdo = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD);
		$pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
		$pdo->exec("USE db_camagru;");
		foreach ($tags as $key => $value) {
			$sql = "SELECT `id_img` FROM img_info WHERE `tag` = :tag;";
			$pre = $pdo->prepare($sql, array(PDO::ATTR_CURSOR => CURSOR_FWDONLY));
			$pre->execute(array('tag' => $tags[$key]));
			$ret = $pre->fetchAll();
			if (isset($ret[0]['id_img'])) {
				$existing[] = $tags[$key];
			}
		}
		$pdo = null;
	} catch (PDOException $error) {
		$pdo = null;
		echo "An error occured";
		unset($existing);
	}
	if (isset($existing))
		foreach ($existing as $key => $value) {
			echo "<li class='tag' value='" . $existing[$key] ."'>" . $existing[$key] . "</li>";
		}
	unset($DB_DSN, $DB_USER, $DB_PASSWORD, $pdo, $sql, $pre, $ret, $tags, $existing);
?>
