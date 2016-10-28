<?php
	if (!isset($_SESSION['logged_on_us'])) {
		header("Location: ../index.php");
	}
	$name = "face";
	$i = 0;
	echo "<p>Choose a sticker to put in your picture :</p>";
	while ($i < 5) {
		$file = $name . '/' . $name . $i . ".png";
		echo '<label for="' . $name . $i . '" id="'. $i . $name . $i .'"><img src="' . $file . '" id="' . $i . $name . '" /></label>';
		echo '<input type="radio" id="' . $name . $i . '" />';
		$i++;
	}
?>
