<?php

if (isset($_POST['family'], $_POST['name'], $_POST['patronymic'], $_POST['phone'], $_POST['mail'], $_POST['admin_email'])) {
	mail(
		$_POST['admin_email'],
		'Заказ ипотеки',
		$_POST['family'] . ' ' . $_POST['name'] . ' ' . $_POST['patronymic'] . ' ' . $_POST['phone'] . ' ' . $_POST['mail']
		);
}