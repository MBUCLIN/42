<?php
	session_start();
	$call = 1;
	$call_menu = 1;
	include("config/database.php");
	if (!isset($_SESSION['logged_on_us'])) {
		header("Location: index.php");
	}
?>
<!DOCTYPE html public>
<html><head>
	<meta charset="utf-8">
	<meta name="viewport" content="width=device-width, user-scalable=no">
	<title>I love me</title><link href="css/structure-page.css" type="text/css" rel='stylesheet' /><link href="css/profil.css" type="text/css" rel="stylesheet" />
</head><body>
	<header name="header"><h1 name="header_text">Love me</h1></header>
	<div id="disp_menu"><h3 id="menu">M</h3></div>
	<div id="hidd_menu"><?php include("php_script/menu_logged.php"); ?></div>
	<div id="rolling-menu" name="head_menu"><?php include("php_script/menu_logged.php"); unset($call_menu);?></div>
	<div id="disp_log"><h3 id="hlog">L</h3></div>
	<div id="log" name="log_div"><?php include("php_script/logout.php"); ?></div>
	<div id="wordfromdev" name="speaktou"><p>Toto was a very good friend for Mike. They have known each other for quit some times. One day, Mike wanted to organize a surprise for Toto. But it has been a long time they did not see each other, he wasn't sure of what would make him happy. So he finaly decided that his idea was bad and finish his day on the couch</p></div>
	<div id="about" name="div_about"><?php include("php_script/about_you.php"); ?>
		<p id="you">Profil of <?php echo $info['login']; ?></p>
		<h4 class="sub_title" id="change">You're information : </h4>
		<div id="about-you">
			<div id="about-you-information">
				<h5>You're mail :</h5><p><?php echo $info['mail']; ?></p>
				<button class="change_info" id="modify-password" type="button">Modify password</button>
				<button class="change_info" id="modify-e_mail" type="button">Modify e-mail</button>
			</div>
			<div id="about-you-password" style="display:none;">
				<p class="modify">Old password :</p>
				<p class="modify">New password :</p>
				<p class="modify">Confirm password :</p>
				<form id="change-password" class='change-form' action="php_script/modify_information.php" method="POST">
					<input class="change-input" type="password" maxlength="40" pattern="[A-Za-z0-9]+" minlength="6" name="oldpw" placeholder="old password"/>
					<input class="change-input" type="password" maxlength="40" pattern="[A-Za-z0-9]+" minlength="6" name="newpw" placeholder="new password"/>
					<input class="change-input" type="password" maxlength="40" pattern="[A-Za-z0-9]+" minlength="6" name="confpw" placeholder="confirm password"/>
					<button class="change-button" type="submit">Modify</button>
				</form>
			</div>
			<div id="about-you-mail" style="display:none;">
				<p class="modify">Password :</p>
				<p class="modify">E-mail :</p>
				<form id="change-e_mail" class="change-form" action="php_script/modify_information.php" method="POST">
					<input class="change-input" type="password" maxlength="40" pattern="[A-Za-z0-9]+" minlength="6" name="pw" placeholder="password"/>
					<input class="change-input" type="email" pattern="[A-Za-z0-9.]+@[a-zA-Z0-9.]+" maxlength="320" minlength="6" name="mail" placeholder="e-mail"/>
					<button class="change-button" type="submit">Modify</button>
				</form>
			</div>
		</div>
	</div>
	<script src="js/display_menu.js" type="text/javascript"></script>
	<script src="js/display_log.js" type="text/javascript"></script>
	<script src="js/display_change.js" type="text/javascript"></script>
	<footer>
		<a class="footer-link" href="https://signin.intra.42.fr/users/sign_in" alt="intra" title="subject">Intra link</a>
		<br />
		<a class="footer-link" href="https://cdn.intra.42.fr/pdf/pdf/595/camagru.fr.pdf" alt="subject" title="subject">PDF subject camagru link</a>
		<p id="footer-copy">&copy mbuclin</p>
		<p id="footer-me">mail: mbuclin@student.42.fr :: date: 2016</p>
	</footer>
	<?php unset($info);?>
</body></html>
