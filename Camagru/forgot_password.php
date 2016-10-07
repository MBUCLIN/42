<?php
	session_start();
	if (isset($_SESSION['logged_on_us'])) {
		header("Location: index.php");
	}

?>
<!DOCTYPE html public>
<html><head>
	<meta charset="utf-8">
	<meta name="viewport" content="width=device-width, user-scalable=no">
	<title>forgot password</title>
	<link href="css/structure-page.css" type="text/css" rel="stylesheet" />
	<link href="css/forgot.css" type="text/css" rel="stylesheet" />
</head><body>
	<header name="header"><h1 name="header_text">Memory problem?</h1></header>
	<div id="disp_menu"><h3 id="menu">M</h3></div>
	<div id="hidd_menu" style="display:none"><?php include("php_script/menu_visit.php"); ?></div>
	<div id="rolling-menu" name="head_menu"><?php include("php_script/menu_visit.php"); ?></div>
	<div id="disp_log"><h3 id="hlog">L</h3></div>
	<div id='log' name='log_div'><?php include('php_script/login.php'); ?></div>

	<div id="wordfromdev" name="speaktou"><p>Toto was a very good friend for Mike. They have known each other for quit some times. One day, Mike wanted to organize a surprise for Toto. But it has been a long time they did not see each other, he wasn't sure of what would make him happy. So he finaly decided that his idea was bad and finish his day on the couch</p></div>
	<div id="conseling" name="youshoulddo">
		<p><strong>1)</strong>	Put your loggin and e-mail!</p>
		<p><strong>2)</strong>	Get your new password from your mail-box</p>
		<p><strong>3)</strong>	Connect to your account and change your password</p>
	</div>
	<div id="forgot" name="forgot_div" style="<?php echo $top; ?>"><form id="forgot_form" action="php_script/forgot_change.php" name="forgot_form" method="POST">
		<h5>User name :</h5><input type="text" id="login" class="forg" name="login" maxlength="15" minlength="4" pattern="[A-Za-z0-9]+" placeholder="user name"/>
		<h5>e mail :</h5><input type="email" id="mail" class="forg" name="mail" pattern="[A-Za-z0-9.]+@[a-zA-Z0-9.]+" maxlength="320" minlength="6" placeholder="password"/><br />
		<button id="send_password" class="submit" type="submit" name="submit">Send Passwd</button></form>
	</div>
	<script src="js/display_menu.js" type="text/javascript"></script>
	<script src="js/display_log.js" type="text/javascript"></script>
	<footer>
		<a class="footer-link" href="http://www.intra.42.fr" alt="intra" title="subject">Intra link</a>
		<br />
		<a class="footer-link" href="https://cdn.intra.42.fr/pdf/pdf/595/camagru.fr.pdf" alt="subject" title="subject">PDF subject camagru link</a>
		<p id="footer-copy">&copy mbuclin</p>
		<p id="footer-me">mail: mbuclin@student.42.fr :: date: 2016</p>
	</footer>
</body></html>
