<?php
	session_start();
	if (isset($_SESSION['logged_on_us']))
		header("Location: index.php");

?>
<!DOCTYPE html public>
<html><head>
	<meta charset="utf-8">
	<meta name="viewport" content="width=device-width, user-scalable=no">
	<title>Create an account</title>
	<link href="css/structure-page.css" type="text/css" rel="stylesheet" /><link href="css/subscribe.css" type="text/css" rel="stylesheet" />
</head><body>
	<header name="header"><h1 name="header_text">Subscribe</h1></header>
	<div id="disp_menu"><h3 id="menu">M</h3></div>
	<div id="hidd_menu"><?php include("php_script/menu_visit.php"); ?></div>
	<div id="rolling-menu" name="head_menu"><?php include("php_script/menu_visit.php"); ?></div>
	<div id="disp_log"><h3 id="hlog">L</h3></div>
	<div id='log' name='log_div'><?php include('php_script/login.php'); ?></div>
	<div id="wordfromdev" name="speaktou"><p>Toto was a very good friend for Mike. They have known each other for quit some times. One day, Mike wanted to organize a surprise for Toto. But it has been a long time they did not see each other, he wasn't sure of what would make him happy. So he finaly decided that his idea was bad and finish his day on the couch</p></div>
	<div id="div_form_sub" name="div_form">
		<h3 id="h3text">Subscribe Here my brother!</h3>
		<div class="h5_div"><h5 name="us_trace">User name :</h5></div><div class="h5_div"><h5 name="pw_trace">Password :</h5></div><div class="h5_div"><h5 name="cpw_trace">Confirm password :</h5></div><div class="h5_div"><h5 name="em_trace">E-mail :</h5></div>
		<form method='POST' id="sub_form" name="sub_form" action="php_script/confirm_subsend.php">
			<input id="user_name" type="text" name="user_name" maxlength="15" pattern="[A-Za-z0-9]+" minlength="4" class='sub' placeholder="User name"/>
			<input id="passwd" type="password" name="passwd" maxlength="40" pattern="[A-Za-z0-9]+" minlength="6" class='sub' placeholder="password"/>
			<input id="conf_passwd" type="password" name="conf_passwd" maxlength="40" minlength="6" pattern="[A-Za-z0-9]+" minlength="6" class='sub' placeholder="conf password"/>
			<input id="mail" type="email" name="mail" pattern="[A-Za-z0-9.]+@[a-zA-Z0-9.]+" maxlength="320" minlength="6" class='sub' placeholder="e-mail"/><br />
			<button id="submit" class="submit" type="submit" name="submit">Submit</button>
		</form>
		<img src="face/face0.png" alt="meme" id="meme" />
	</div>
	<script src="js/display_menu.js" type="text/javascript"></script>
	<script src="js/display_log.js" type="text/javascript"></script>
	<footer>
		<a class="footer-link" href="http://www.intra.42.fr" alt="intra" title="subject">Intra link</a>
		<br />
		<a class="footer-link" href="https://cdn.intra.42.fr/pdf/pdf/595/camagru.fr.pdf" alt="subject" title="subject">PDF subject camagru link</a>
		<p id="footer-copy">&copy mbuclin</p>
		<p id="footer-me">mail: mbuclin@student.42.fr :: date: 2016</p>
	</footer>
</body></html>
