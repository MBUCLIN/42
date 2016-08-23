<?php
	session_start();
	include "php_function/login_logout.php";
	if (!isset($_SESSION['logged_on_us'])) {
		$menu = 'js/menu_visit.js';
	} else {
		$menu = 'js/menu_logged.js';
	}
	echo $log;
?>
<!DOCTYPE html public>
<html lang='en'><head>
	<title>Home Page</title>
	<link href="css/structure-page.css" type="text/css" rel="stylesheet" />
</head><body>
	<header name="header"><h1 name="header_text">Hello World</h1></header>
	<div id="disp_menu"><h3 id="menu">M</h3></div>
	<div id="hidd_menu" style="display:none"></div>
	<div id="rolling-menu" name="head_menu"></div>
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
	<script src="<?php echo $menu;?>" type="text/javascript"></script>
	<?php unset($menu); ?>
	<footer></footer>
</body></html>
