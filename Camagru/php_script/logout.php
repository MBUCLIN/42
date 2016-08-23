<?php
  echo "<p id='welcome'>Welcome " . $_SESSION['logged_on_us'] . "</p><a href='myprofil.php' class='logref' name='profil'>My profil</a><p>Double click here put a word about you!</p><form id='out_form' action='disconnect.php'><button id='logout' name='logout'>Logout</button></form>";
?>
