<?php
	session_start();
	include("config/database.php");
	if (!isset($_SESSION['logged_on_us'])) {
		header("Location: ../index.php");
	}

?>
<!DOCTYPE html public>
<html><head>
	<title>I love me</title><link href="css/structure-page.css" type="text/css" rel='stylesheet' /><link href="css/profil.css" type="text/css" rel="stylesheet" />
</head><body>
	<header name="header"><h1 name="header_text">Love me more</h1></header>
	<div id="disp_menu"><h3 id="menu">M</h3></div>
	<div id="hidd_menu"></div>
	<div id="rolling-menu" name="head_menu"></div>
	<div id="about_you" name="div_about"><?php include("php_script/about_you.php"); ?></div>
	<div id="log" name="log_div"><?php include("php_script/logout.php"); ?></div>
	<script src="js/display_menu.js" type="text/javascript"></script>
	<script src="js/menu_logged.js" type="text/javascript"></script>
</body></html>
