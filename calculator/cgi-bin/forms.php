<?php

require_once "Mail.php";

// if (isset($_POST['family'], $_POST['name'], $_POST['patronymic'], $_POST['phone'], $_POST['mail'], $_POST['admin_email'])) {
// 	mail(
// 		$_POST['admin_email'],
// 		'Заказ ипотеки',
// 		$_POST['family'] . ' ' . $_POST['name'] . ' ' . $_POST['patronymic'] . ' ' . $_POST['phone'] . ' ' . $_POST['mail']
// 		);
// }
 if (isset($_POST['family'], $_POST['name'], $_POST['patronymic'], $_POST['phone'], $_POST['mail'], $_POST['admin_email'])) {

 	$to = $_POST['admin_email'];
 	$from = $_POST['mail'];
 	$subject = 'Заказ ипотеки';
 	$body = $_POST['family'] . ' ' . $_POST['name'] . ' ' . $_POST['patronymic'] . ' ' . $_POST['phone'] . ' ' . $_POST['mail'];

 	$host = 'ssl://smpt.gmail.com';
 	$port = '465';
 	$username = 'findome.adm@gmail.com';
 	$password = 'apetyqeza';

 	$headers = [
 		'From' => $from,
 		'To' => $to,
 		'Subject' => $subject
 	];

 	$smtp = Mail::factory('smtp', 
 		[
 			'port' => $port,
 			'auth' => true,
 			'username' => $username,
 			'password' => $password
 		]);

 	$mail = $smtp->send($to, $headers, $body);

 	if (PEAR::isError($mail)) {
 		return 'error';
 	} else {
 		return 'Sending';
 	}
 }