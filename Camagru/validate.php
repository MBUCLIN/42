<?php
	session_start();
	if (isset($_SESSION['logged_on_us'])) {
		header('Location : index.php');
	}
?>
