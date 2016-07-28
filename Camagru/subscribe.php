<?php
	session_start();
	if (isset($_SESSION['logged_on_us']))
		header("Location: index.php");
?>
<!DOCTYPE html public>
<html><head>
	<title>Create an account</title>
	<link href="css/structure-page.css" type="text/css" rel="stylesheet" /><link href="css/subscribe.css" type="text/css" rel="stylesheet" />
</head><body>
	<header name="header"><h1 name="header_text">Subscribe here !</h1></header>
	<div id="disp_menu"><h3 id="menu">M</h3></div>
	<div id="hidd_menu"></div>
	<div id="rolling-menu" name="head_menu"></div>
	<div id="div_form" name="div_form">
		<form id="sub_form" name="sub_form">
			<h5 id="f_imput" name="us_trace">User name :</h5><h4 id="more_us" class="more">??</h4><input id="user_name" type="text" name="user_name" />
			<h5 class="input" name="pw_trace">Password :</h5><h4 id="more_pw" class="more">??</h4><input id="passwd" type="password" name="passwd" />
			<h5 class="input" name="cpw_trace">Confirm password :</h5><h4 id="more_cpw" class="more">??</h4><input id="conf_passwd" type="password" name="conf_passwd" />
			<h5 class= "input" name="em_trace">E-mail :</h5><h4 id="more_em" class="more">??</h4><input id="mail" type="email" name="mail" /><br />
			<button id="submit" class="submit" type="submit" name="submit">Submit</button>
		</form>
		<div id="us_info" name="us_info" class="hidden"></div><div id="pw_info" name="pw_info" class="hidden"></div><div id="cpw_info" name="cpw_info" class="hidden"></div><div id="em_info" name="em_info" class="hidden"></div>

	</div>
	<footer></footer>
		<script src="js/print_info.js" type="text/javascript"></script>
		<script src="js/sub_wtconfirm.js" type="text/javascript"></script>
		<script src="js/more_sub.js" type="text/javascript"></script>
		<script src="js/display_menu.js" type="text/javascript"></script>
		<script src="js/menu_visit.js" type="text/javascript"></script>
</body></html>
