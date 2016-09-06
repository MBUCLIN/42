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
	<div id="onceuppon">
		<p>One uppon a time, in a world where people loved them self.</p>
		<p>Humain people where surfing on a net giving all there knowledge and memory.</p>
	</div>
	<div id="hidd_comm" name="div_hidden"><?php include("php_script/all_commentary.php"); ?></div>
	<div id="about_you" name="div_about"><?php include("php_script/about_you.php"); ?>
		<p class='about'>You are :<?php echo "	" . $info['login']; ?></p>
		<p class='about'>Your e-mail :<?php echo "	" . $info['mail']; ?></p><a href='change_password.php' class='link_about'>change it!</a>
		<p class='about'>You love : Nothing loved yet (Favorite tag)</p>
		<p class='about' id='comm'>Your last com :<?php echo "	" . end($info['comment']); ?></p><button type="button" id="seeall" class="button_about">see all</button><button type="button" id="dispcomm">display</button>
	</div>
	<div id="log" name="log_div"><?php include("php_script/logout.php"); ?></div>
	<script src="js/display_menu.js" type="text/javascript"></script>
	<script src="js/menu_logged.js" type="text/javascript"></script>
	<script src="js/display_com.js" type="text/javascript"></script>
</body></html>
