<?php
	if (!isset($call_menu)) {
		header("Location: ../index.php");
	} else {
		$ref = array("index.php", "galery.php", "myprofil.php", "pictures.php");
		$list = array("Home", "Galery", "Profil", "Pictures");
		$ul = "<ul name='head_list' class='menu_ul' id='menu_list'>";
		$a = "<a ";
		$end_a = "</a>";
		$li = "<li>";
		$end_li = "</li>";
		$end_ul = "</ul>";
		$i = 0;
		echo $ul;
		while ($i < count($list)) {
			echo $li . $a . "href='" . $ref[$i] . "' name='" . $list[$i] . "_ref' class='menu_link'><span>" . $list[$i] . "</span>" . $end_a . $end_li;
			$i++;
		}
		echo $end_lu;
		unset($ref, $list, $ul, $a, $end_a, $li, $end_li, $end_ul);
	}
?>
