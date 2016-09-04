<?php
	$p = "<p>Modify e_mail :</p>";
	$form = "<form action='php_script/modify_information.php' method='POST' id='form_mail'>";
	$password = "Password : <input type='password' id='input_pass' name='pw' pattern='[A-Za-z0-9]+' minlength='6' maxlength='40' /><br />";
	$mail = "New e-mail : <input type='mail' id='input_mail' name='mail' pattern='[A-Za-z0-9.]+@[a-zA-Z0-9.]+' minlength='6' maxlength='320' /><br />";
	$button = "<button type='submit' id='send_mailform' name='newmail' class='mod'>Modify</button>";
	$end = "</form>";

	echo $p . $form . $password . $mail . $button . $end;
	unset($p, $form, $password, $mail, $button, $end);
?>
