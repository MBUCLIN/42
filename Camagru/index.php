<?php
	session_start();
	$call = 1;
	$call_menu = 1;
	if (!isset($_SESSION['logged_on_us'])) {
		$menu = 'php_script/menu_visit.php';
	} else {
		$menu = 'php_script/menu_logged.php';
	}
?>
<!DOCTYPE html public>
<html lang='en'><head>
	<meta charset="utf-8">
	<meta name="viewport" content="width=device-width, user-scalable=no">
	<title>Home Page</title>
	<link href="css/structure-page.css" type="text/css" rel="stylesheet" />
</head><body>
	<header name="header"><h1 name="header_text">Hello World</h1></header>
	<div id="disp_menu"><h3 id="hmenu">M</h3></div>
	<div id="hidd_menu" style="display:none"><?php include($menu); ?></div>
	<div id="rolling-menu" name="head_menu"><?php include($menu); unset($menu, $call_menu);?></div>
	<div id="disp_log"><h3 id="hlog">L</h3></div>
	<div id='log' name='log_div'>
	<?php
		if (!isset($_SESSION['logged_on_us'])) {
			include 'php_script/login.php';
		} else {
			include 'php_script/logout.php';
		}
	?>
	</div>
	<div id="wordfromdev" name="speaktou"><p>Toto was a very good friend for Mike. They have known each other for quit some times. One day, Mike wanted to organize a surprise for Toto. But it has been a long time they did not see each other, he wasn't sure of what would make him happy. So he finaly decided that his idea was bad and finish his day on the couch</p></div>
	<script src="js/display_menu.js" type="text/javascript"></script>
	<script src="js/display_log.js" type="text/javascript"></script>
	<footer>
		<a class="footer-link" href="https://signin.intra.42.fr/users/sign_in" alt="intra" title="subject">Intra link</a>
		<br />
		<a class="footer-link" href="https://cdn.intra.42.fr/pdf/pdf/595/camagru.fr.pdf" alt="subject" title="subject">PDF subject camagru link</a>
		<p id="footer-copy">&copy mbuclin</p>
		<p id="footer-me">mail: mbuclin@student.42.fr :: date: 2016</p>
	</footer>
</body></html>
