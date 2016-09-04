<?php
	$p = "<p>Modify password :</p>";
	$form = "<form action='php_script/modify_information.php' method='POST' id='form_pass'>";
	$old = "Old password : <input type='password' id='oldpw' name='oldpw' patern='[A-Za-z0-9]+' minlength='6' maxlength='40' /><br />";
	$new = "New password : <input type='password' id='newpw' name='newpw' patern='[A-Za-Z0-9]+' minlength='6' maxlength='40' /><br />";
	$conf = "Confirm password : <input type='password' id='confpw' name='confpw' patern='[A-Za-z0-9]+' mindlength='6' maxlength='40' /><br />";
	$button = "<button type='submit' id='send_passform' name='newpassword' class='mod'>Modify</button>";
	$end = "</form>";

	echo $p . $form . $old . $new . $conf . $button . $end;
	unset($p, $form, $old, $new, $conf, $button, $end);
?>
