<?php
	$ref = array("index.php", "galery.php", "subscribe.php", "validate.php");
	$list = array("Home", "Galery", "Sub", "Valid");
	$li = "<li name='head_list' class='menu_list' id='menu_list'>";
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
