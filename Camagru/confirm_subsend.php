<?php
	session_start();
	include("config/database.php");
	if (isset($_SESSION['logged_on_us'])) {
		header("Location: index.php");
	}
	$user_name = $_POST['user_name'];
	$password = hash('sha512', $_POST['passwd']);
	$e_mail = $_POST['mail'];
	try {
		$pdo = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD);
		$pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
		$sql = 'USE DATABASE db_camagru;';
		$pdo->exec($sql);
		$pdo->beginTransaction();
		$sql = 'SELECT login, mail FROM users, user_info WHERE login = :user OR mail = :mail';
		$pre = $pdo->prepare($sql);
		$pre->exectute(array(':user' => $user_name, ':mail' => $e_mail));
		$ret = $pre->fetchAll();
		print_r($ret);
	} catch (PDOException $error) {
		echo 'Exception catched : ' . $error->getMessage() . '\n';
		exit();
	}
?>
