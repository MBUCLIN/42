<?php
  session_start();
  if (!isset($_SESSION['logged_on_us'])) {
    $file_name_log = 'js/loggin.js';
  } else {
    $file_name_log = 'js/logged.js';
  }
  if ($file_name_log === 'js/logged.js') {
    $menu = 'js/menu_logged.js';
  }
  else {
    $menu = 'js/menu_visit.js';
  }
?>
<!DOCTYPE html public>
<html lang='en'><head>
  <title>Home Page</title>
  <link href="css/index.css" type="text/css" rel="stylesheet" />
  <link href="css/structure-page.css" type="text/css" rel="stylesheet" />
</head><body>
  <header name="header"><h1 name="header_text">Hello World !</h1></header>
  <div id="rolling-menu" name="head_menu"></div>
  <script src="<?php echo $menu; ?>" type="text/javascript"></script>
  <div id="log" name="log"></div>
  <script src="<?php echo $file_name_log; ?>" type="text/javascript"></script>
  <?php unset($menu, $file_name_log); ?>
  <footer></footer>
</body></html>
