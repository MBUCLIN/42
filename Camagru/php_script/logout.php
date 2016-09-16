<?php
  echo "<p id='welcome' style='color:red;margin-left:5px;'>Welcome " . $_SESSION['logged_on_us'] . "</p><br /><a href='myprofil.php' class='logref' name='profil'>My profil</a><br /><a href='change_password.php' class='logref' name='change_pass'>Change password</a><br/><form id='out_form' action='php_script/disconnect.php' ><button name='logout' value='disconnect' id='logout'>Logout</button></form>";
?>
