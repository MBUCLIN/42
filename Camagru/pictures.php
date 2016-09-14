<?php
	session_start();
	if (!isset($_SESSION['logged_on_us'])) {
		header("Location: index.php");
	}
?>
<!DOCTYPE html public>
<html><head>
	<title>Another world</title><link href="css/structure-page.css" type="text/css" rel="stylesheet" /><link href="css/picture.css" type="text/css" rel="stylesheet" />
</head><body id="body">
	<header name="header"><h1 name="header_text">don't forget to smile</h1></header>
	<div id="disp_menu"><h3 id="menu">M</h3></div>
	<div id="hidd_menu" style="display:none"></div>
	<div id="rolling-menu" name="head_menu"></div>
	<div id="video_div" name="div_video">
		<video id="video">Not availlable for you YOU ARE TOO WEAK!</video>
		<button class="but_vid" id="smile" type="button">Take</button><button class="but_vid" id="reset" type="button">Reset</button>
		<canvas id="canvas"></canvas>
		<select id="select">
			<option selected disabled>Choose tag</option>
			<option>to much fun</option>
			<option>fun</option>
			<option>medium fun</option>
			<option>little fun</option>
			<option>little serious</option>
			<option>medium serious</option>
			<option>serious</option>
			<option>more than serious</option>
		</select>
		<button class="but_vid" id="save" type="button">save</button>
	</div>
	<div id="merge_div"><?php include("php_script/list_merge.php"); ?>
	</div>
	<div id="log"><?php include("php_script/logout.php"); ?></div>
	<script src="js/videocanvas.js" type="text/javascript"></script>
	<script src="js/display_menu.js" type="text/javascript"></script>
	<script src="js/menu_logged.js" type="text/javascript"></script>
	<script src="js/face_stickers.js" type="text/javascript"></script>
	<footer></footer>
</body></html>
