<?php
  echo "<p id='welcome'>Welcome " . $_SESSION['logged_on_us'] . "</p><a href='myprofil.php' class='logref' name='profil'>My profil</a><br /><form id='out_form' action='php_script/disconnect.php' ><button name='logout' value='disconnect' id='logout'>Logout</button></form>";
?>
