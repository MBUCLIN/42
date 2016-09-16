<?php
	$ref = array("index.php", "galery.php", "subscribe.php", "validate.php");
	$list = array("Home", "Galery", "Sub", "Valid");
	$ul = "<ul name='head_list' class='menu_ul' id='menu_list'>";
	$a = "<a ";
	$end_a = "</a>";
	$li = "<li >";
	$end_li = "</li>";
	$end_ul = "</ul>";

	$i = 0;
	echo $ul;
	while ($i < count($list)) {
		echo $li . $a . "href='" . $ref[$i] . "' name='" . $list[$i] . "_ref' class='menu_link'><span>" . $list[$i] . "</span>" . $end_a . $end_li;
		$i++;
	}
	echo $end_ul;
?>
