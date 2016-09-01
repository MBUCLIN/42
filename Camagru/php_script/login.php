<?php
    echo "<form method='POST' action='connect.php' id='log_form' name='log_form'><input id='username' name='username' value='username' class='required' type='text' maxlength='15' pattern='[A-Za-z0-9]+' minlength='4'/><input id='password' name='password' value='password' class='required' type='password' maxlength='40' minlength='6' pattern='[A-Za-z0-9]+'/><button id='sub' name='log_sub'>Connect</button></form><a href='forgot_password.php' class='logref' name='pass_forg'>forgot your password?</a><br /><a href='subscribe.php' class='logref' name='subscribe'>not subscribe yet?</a>";
?>
