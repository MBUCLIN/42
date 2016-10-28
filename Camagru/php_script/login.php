<?php
	if (!isset($call)) {
		header("Location: ../index.php");
	} else {
    	echo "<form method='POST' action='php_script/connect.php' id='log_form' name='log_form'><input id='username' name='username' placeholder='user name' class='input_login' type='text' maxlength='15' pattern='[A-Za-z0-9]+' minlength='4'/><input id='password' name='password' placeholder='password' class='input_login' type='password' maxlength='40' minlength='6' pattern='[A-Za-z0-9]+'/><button id='sub' name='log_sub'>Connect</button></form><br /><a href='forgot_password.php' class='logref' name='pass_forg'>forgot your password?</a><br /><a href='subscribe.php' class='logref' name='subscribe'>not subscribe yet?</a>";
	}
	unset($call);
?>
