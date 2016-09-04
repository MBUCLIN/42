<?php
	session_start();
	if (!isset($_SESSION['logged_on_us'])) {
		header("Location: index.php");
	} else if ($_GET['mail_click'] === "e_mail") {
		$file_name = "modify_mail.php";
	} else if ($_GET['pass_click'] === "password") {
		$file_name = "modify_password.php";
	} else {
		$file_name = "modify.php";
	}
?>
<!DOCTYPE html public>
<html><head>
	<title>Modify information</title>
	<link href="css/structure-page.css" type="text/css" rel="stylesheet" /><link href="css/modify.css" type="text/css" rel="stylesheet" />
</head><body>
	<header><h1 name="header_text">Modify account</h1></header>
	<div id="disp_menu"><h3 id="menu">M</h3></div>
	<div id="hidd_menu" style="display:none"></div>
	<div id="rolling-menu" name="head_menu"></div>
	<div id='log' name='log_div'><?php include('php_script/logout.php');?></div>
	<div id="modify" name="modify">
		<?php include('php_script/' . $file_name); ?>
	</div>
	<script src="js/display_menu.js" type="text/javascript"></script>
	<script src="js/menu_logged.js" type="text/javascript"></script>
	<?php unset($file_name); ?>
	<footer></footer>
</body></html>
