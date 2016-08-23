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
	<header name="header"><h1 name)="header_text">Come out of the wait list</h1></header>
	<div id="disp_menu"><h3 id="menu">M</h3></div>
	<div id="hidd_menu" style="display:none"></div>
	<div id="rolling-menu" name="head_menu"></div>
	<div id="sended_mail" name="sended_mail"><i>A mail has been send to your mail, get the code on it to validate.</i><br/><i>You can olso log you here, but you won't be able to save your pictures.</i></div>
	<div class="div_form" name="valid" id="valid_div">
		<form method="POST" id="token_form" name="token_form"><p>Insert the <i>code</i> sended in your mail.</p><input type="text" id="token" name="token" /><br /><button id="activ" name="active">Activ</button></form>
	</div>
	<div class="div_form" name="quick" id="quick_div">
		<form name="quick_form" id="quick_form" method="POST"><br />login : <input type="text" id="login" name="login" /><br />password : <input type="password" id="passwd" name="password" /><br /><button id="submit" name="submit">Log</button></form>
	</div>
	<script src="js/valid.js" type="text/javascript"></script>
	<script src="js/display_menu.js" type="text/javascript"></script>
	<script src="js/menu_visit.js" type="text/javascript"></script>
	<footer></footer>
</body></html>
