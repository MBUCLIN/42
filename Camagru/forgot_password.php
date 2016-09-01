<?php
	session_start();
	if (isset($_SESSION['logged_on_us'])) {
		header("Location: index.php");
	}
	if (isset($_POST['error'])) {
		$display = "display:block;";
		$top = "top:140px;";
	} else {
		$display = "display:none;";
		$top = "top:80px;";
	}
?>
<!DOCTYPE html public>
<html><head>
	<title>forgot password</title>
	<link href="css/structure-page.css" type="text/css" rel="stylesheet" />
	<link href="css/forgot.css" type="text/css" rel="stylesheet" />
</head><body>
	<header name="header"><h1 name="header_text">Memory problem?</h1></header>
	<div id="error" style="<?php echo $display; ?>"></div>
	<div id="disp_menu"><h3 id="menu">M</h3></div>
	<div id="hidd_menu" style="display:none"></div>
	<div id="rolling-menu" name="head_menu"></div>
	<div id='log' name='log_div'><?php include('php_script/login.php'); ?></div>
	<div id="conseling" name="youshoulddo" style="<?php echo $top; ?>">
		<p><strong>1)</strong>	Put your loggin and e-mail!</p><br />
		<p><strong>2)</strong>	Get your new password from your mail-box</p><br />
		<p><strong>3)</strong>	Connect to your account and change your password</p>
	</div>
	<div id="forgot" name="forgot_div" style="<?php echo $top; ?>"><form id="forgot_form" action="forgot_change.php" 	name="forgot_form" method="POST">
		<h5>User name :</h5><input type="text" id="login" class="forg" name="login" maxlength="15" minlength="4" pattern="[A-Za-z0-9]+" /><br />
		<h5>e mail :</h5><input type="email" id="mail" class="forg" name="mail" pattern="[A-Za-z0-9.]+@[a-zA-Z0-9.]+" maxlength="320" minlength="6" /><br />
		<button id="submit" class="submit" type="submit" name="submit">Send Passwd</button></form>
	</div>
	<script src="js/display_menu.js" type="text/javascript"></script>
	<script src="js/menu_visit.js" type="text/javascript"></script>
	<footer></footer>
</body></html>
