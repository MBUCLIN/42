<?php
  echo "<p id='welcome' style='color:red;margin-left:5px;'>Welcome " . $_SESSION['logged_on_us'] . "</p><br /><a href='myprofil.php' class='logref' name='profil'>My profil</a><br /><br /><a href='change_password.php' class='logref' name='change_pass'>Change password</a><form id='out_form' action='disconnect.php'><button id='logout' name='logout'>Logout</button></form>";
?>
