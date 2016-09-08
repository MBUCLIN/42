<?php
	$name = "face";
	$i = 0;
	echo "<p>Choose a sticker to put in your picture :</p>";
	while ($i < 5) {
		$file = $name . '/' . $name . $i . ".png";
		echo '<label for="' . $name . $i . '"><img src="' . $file . '" id="' . $i . $name . '" /></label>';
		echo '<input type="checkbox" id="' . $name . $i . '" />';
		$i++;
	}
?>
