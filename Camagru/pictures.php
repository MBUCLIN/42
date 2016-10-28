<?php
	session_start();
	$call = 1;
	$call_menu = 1;
	if (!isset($_SESSION['logged_on_us'])) {
		header("Location: index.php");
	}
?>
<!DOCTYPE html public>
<html><head>
	<meta charset="utf-8">
	<meta name="viewport" content="width=device-width, user-scalable=no">
	<title>Another world</title>
	<link href="css/structure-page.css" type="text/css" rel="stylesheet" />
	<link href="css/picture_video.css" type="text/css" rel="stylesheet" />
	<link href="css/picture_merge.css" type="text/css" rel="stylesheet" />
	<link href="css/picture_upload.css" type="text/css" rel="stylesheet" />
</head><body id="body">
	<header name="header"><h1 name="header_text">Smile</h1></header>
	<div id="disp_menu"><h3 id="menu">M</h3></div>
	<div id="hidd_menu" style="display:none"><?php include("php_script/menu_logged.php"); ?></div>
	<div id="rolling-menu" name="head_menu"><?php include("php_script/menu_logged.php"); unset($call_menu);?></div>
	<div id="disp_log"><h3 id="hlog">L</h3></div>
	<div id="log"><?php include("php_script/logout.php"); ?></div>
	<div id="wordfromdev" name="speaktou"><p>Toto was a very good friend for Mike. They have known each other for quit some times. One day, Mike wanted to organize a surprise for Toto. But it has been a long time they did not see each other, he wasn't sure of what would make him happy. So he finaly decided that his idea was bad and finish his day on the couch</p></div>
	<div id="video_div" name="div_video" >
		<h4>Take a picture now</h4>
		<button type="button" class="but_vid" id="upload">Upload</button>
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
	<div id="upload_div" name="div_upload" style="display:none">
		<h4>Upload a picture now</h4>
		<button type="button" id="toVideo" class="but_vid">WebCam</button>
		<img src="" id="uploaded-image" alt="You can't see that image" />
		<form id="upload-form" method="post" action="">
			<input type="file" accept="image/*" id="upload-file" />
			<br />
			<select id="upload-select">
				<option selected disabled>Choose tag</option>
				<option>troll</option>
				<option>fun</option>
				<option>wtf</option>
				<option>cute</option>
				<option>freedom</option>
				<option>cantcategorize</option>
			</select><br />
			<button type="submit" class="but_vid" id="upload-save">Save</button>
			<button type="reset" class="but_vid" id="upload-reset">Reset</button>
		</form>
	</div>
	<div id="merge_div"><?php include("php_script/list_merge.php"); ?></div>
	<div id="last-picture_div">
		<h4>Last pictures you took :</h4>
		<div id="picture_took"></div>
		<button class="but_vid" id="load_all" type="button">Load</button>
		<button class="but_vid" id="suppr_select" type="button" style="display:none">Delete</button>
	</div>
	<script src="js/changeToUpload.js" type="text/javascript"></script>
	<script src="js/show_image.js" type="text/javascript"></script>
	<script src="js/upload.js" type="text/javascript"></script>
	<script src="js/videocanvas.js" type="text/javascript"></script>
	<script src="js/display_menu.js" type="text/javascript"></script>
	<script src="js/display_log.js" type="text/javascript"></script>
	<script src="js/face_stickers.js" type="text/javascript"></script>
	<script src="js/load_picture.js" type="text/javascript"></script>
	<script src="js/delete_picture.js" type="text/javascript"></script>
	<footer>
		<a class="footer-link" href="https://signin.intra.42.fr/users/sign_in" alt="intra" title="subject">Intra link</a>
		<br />
		<a class="footer-link" href="https://cdn.intra.42.fr/pdf/pdf/595/camagru.fr.pdf" alt="subject" title="subject">PDF subject camagru link</a>
		<p id="footer-copy">&copy mbuclin</p>
		<p id="footer-me">mail: mbuclin@student.42.fr :: date: 2016</p>
	</footer>
</body></html>
