<?php
	session_start();
	if (!isset($_SESSION['logged_on_us'])) {
		header("Location: index.php");
	}
?>
<!DOCTYPE html public>
<html><head>
	<title>Another world</title>
	<link href="css/structure-page.css" type="text/css" rel="stylesheet" />
	<link href="css/picture_video.css" type="text/css" rel="stylesheet" />
	<link href="css/picture_merge.css" type="text/css" rel="stylesheet" />
</head><body id="body">
	<header name="header"><h1 name="header_text">Smile</h1></header>
	<div id="disp_menu"><h3 id="menu">M</h3></div>
	<div id="hidd_menu" style="display:none"><?php include("php_script/menu_logged.php"); ?></div>
	<div id="rolling-menu" name="head_menu"><?php include("php_script/menu_logged.php"); ?></div>
	<div id="disp_log"><h3 id="hlog">L</h3></div>
	<div id="log"><?php include("php_script/logout.php"); ?></div>
	<div id="wordfromdev" name="speaktou"><p>Toto was a very good friend for Mike. They have known each other for quit some times. One day, Mike wanted to organize a surprise for Toto. But it has been a long time they did not see each other, he wasn't sure of what would make him happy. So he finaly decided that his idea was bad and finish his day on the couch</p></div>
	<div id="video_div" name="div_video">
		<h4>Take a picture now</h4>
		<video id="video">Not availlable for you YOU ARE TOO WEAK!</video>
		<button class="but_vid" id="smile" type="button">Take</button><button class="but_vid" id="reset" type="button">Reset</button>
		<canvas id="canvas"></canvas>
		<select id="select">
			<option selected disabled>Choose tag</option>
			<option>troll</option>
			<option>fun</option>
			<option>wtf</option>
			<option>cute</option>
			<option>freedom</option>
			<option>cantcategorize</option>
		</select><br />
		<button class="but_vid" id="save" type="button">save</button>
	</div>
	<div id="merge_div"><?php include("php_script/list_merge.php"); ?></div>
	<div id="last-picture_div">
		<h4>Last pictures you took :</h4><br />
		<?php include("php_script/last_picture.php"); ?>
	</div>
	<script src="js/videocanvas.js" type="text/javascript"></script>
	<script src="js/display_menu.js" type="text/javascript"></script>
	<script src="js/display_log.js" type="text/javascript"></script>
	<script src="js/face_stickers.js" type="text/javascript"></script>
	<footer></footer>
</body></html>
