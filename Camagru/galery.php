<?php
	session_start();
	if (!isset($_SESSION['logged_on_us'])) {
		header("Location: index.php");
	}
?>
<!DOCTYPE html public>
<html><head>
	<meta charset="utf-8">
	<meta name="viewport" content="width=device-width, user-scalable=no">
	<title>Lot of picture</title>
	<link href="css/structure-page.css" type="text/css" rel="stylesheet" />
	<link href="css/galery.css" type="text/css" rel="stylesheet" />
</head><body>
	<header name="header"><h1 name="header_text">See it all</h1></header>
	<div id="disp_menu"><h3 id="menu">M</h3></div>
	<div id="hidd_menu" style="display:none"><?php include("php_script/menu_logged.php"); ?></div>
	<div id="rolling-menu" name="head_menu"><?php include("php_script/menu_logged.php"); ?></div>
	<div id="disp_log"><h3 id="hlog">L</h3></div>
	<div id="log"><?php include("php_script/logout.php"); ?></div>
	<div id="wordfromdev" name="speaktou"><p>Toto was a very good friend for Mike. They have known each other for quit some times. One day, Mike wanted to organize a surprise for Toto. But it has been a long time they did not see each other, he wasn't sure of what would make him happy. So he finaly decided that his idea was bad and finish his day on the couch</p></div>
	<div id="load">
		<p id="status">Nothing loaded now</p>
	</div>
	<div id="galery">
		<button id="loadMore" type="button">Display more</button>
	</div>
	<script src="js/function_event.js" type="text/javascript"></script>
	<script src="js/display_menu.js" type="text/javascript"></script>
	<script src="js/display_log.js" type="text/javascript"></script>
	<script src="js/function_event.js" type="text.havascript"></script>
	<script src="js/function_pictures.js" type="text/javascript"></script>
	<script src="js/display_pictures.js" type="text/javascript"></script>
</body></html>
