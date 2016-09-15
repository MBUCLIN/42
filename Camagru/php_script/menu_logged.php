<?php
	$ref = array("index.php", "galery.php", "myprofil.php", "pictures.php");
	$list = array("Home", "Galery", "Profil", "Pictures");
	$li = "<li name='head_list' class='menu_list' id='hidd_li'>";
	$a = "<a ";
	$end_a = "</a>";
	$ul = "<ul class='menu_ul'>";
	$end_ul = "</ul>";
	$end_li = "</li>";

	$i = 0;
	echo $li;
	while ($i < count($list)) {
		echo $ul . $a . "href='" . $ref[$i] . "' name='" . $list[$i] . "_ref' class='menu_link'><span>" . $list[$i] . "</span>" . $end_a . $end_ul;
		$i++;
	}
	echo $end_li;
?>
