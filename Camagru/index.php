<?php
	session_start();
	if (!isset($_SESSION['logged_on_us'])) {
		$menu = 'php_script/menu_visit.php';
	} else {
		$menu = 'php_script/menu_logged.php';
	}
?>
<!DOCTYPE html public>
<html lang='en'><head>
	<title>Home Page</title>
	<link href="css/structure-page.css" type="text/css" rel="stylesheet" />
</head><body>
	<header name="header"><h1 name="header_text">Hello World</h1></header>
	<div id="disp_menu"><h3 id="hmenu" style="color:red;">M</h3></div>
	<div id="hidd_menu" style="display:none"><?php include($menu); ?></div>
	<div id="rolling-menu" name="head_menu"><?php include($menu); unset($menu);?></div>
	<div id="disp_log"><h3 id="hlog" style="color:red;">L</h3></div>
	<div id='log' name='log_div'>
	<?php
		if (!isset($_SESSION['logged_on_us'])) {
			include 'php_script/login.php';
		} else {
			include 'php_script/logout.php';
		}
	?>
	</div>
	<script src="js/display_menu.js" type="text/javascript"></script>
	<script src="js/display_log.js" type="text/javascript"></script>
	<footer></footer>
</body></html>
