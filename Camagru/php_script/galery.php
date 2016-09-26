<?php
	session_start();
	if (!isset($_SESSION['logged_on_us'])) {
		$_POST['error'] = "No user logged";
		echo "Error log";
	} else if ($_POST[]) {

	}
?>
