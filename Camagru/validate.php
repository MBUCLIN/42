<?php
	session_start();
	if (isset($_SESSION['logged_on_us'])) {
		header('Location : index.php');
	}
?>
<!DOCTYPE html public>
<html><head>
	<title>Validate Account</title><link href="css/structure-page.css" rel="stylesheet" type ="text/css" /><link href="css/validate.css" rel="stylesheet" type="text/css" />
</head><body>
	<header name="header"><h1 name)="header_text">Valid</h1></header>
	<div id="disp_menu"><h3 id="menu">M</h3></div>
	<div id="hidd_menu" style="display:none"><?php include("php_script/menu_visit.php"); ?></div>
	<div id="rolling-menu" name="head_menu"><?php include("php_script/menu_visit.php"); ?></div>
	<div id="disp_log"><h3 id="hlog" style="color:red;">L</h3></div>
	<div id='log' name='log_div'><?php include('php_script/login.php'); ?></div>
	<div id="wordfromdev" name="speaktou"><p>Toto was a very good friend for Mike. They have known each other for quit some times. One day, Mike wanted to organize a surprise for Toto. But it has been a long time they did not see each other, he wasn't sure of what would make him happy. So he finaly decided that his idea was bad and finish his day on the couch</p></div>
	<div id="sended_mail" name="sended_mail"><i>A mail has been send to your mail, get the code on it to validate.</i><br/><i>You can olso log you here, but you won't be able to save your pictures.</i></div>
	<div name="valid" id="valid_div"><p><span>Put the code here :</span></p>
		<form method="POST" id="token_form" name="token_form" action="php_script/valid_account.php"><input type="text" id="token" name="token" /><br /><button id="activ" name="active">Activ</button></form>
		<img src="face/face0.png" alt="meme0" id="meme0" />
		<img src="face/face1.png" alt="meme1" id="meme1" />
		<img src="face/face2.png" alt="meme2" id="meme2" />
	</div>
	<script src="js/display_menu.js" type="text/javascript"></script>
	<script src="js/display_log.js" type="text/javascript"></script>
	<footer></footer>
</body></html>
