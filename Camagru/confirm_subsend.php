<?php
	session_start();
	if (isset($_SESSION['logged_on_us'])) {
		header("Location: index.php");
	}
	$user_name = $_POST['user_name'];
	$password = $_POST['passwd'];
	$e_mail = $_POST['mail'];
?>
