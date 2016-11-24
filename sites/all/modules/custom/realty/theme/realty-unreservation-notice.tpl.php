Здравствуйте, <?php print $node['account']->field_user_name['und'][0]['value']; ?>!

<br><br>Сообщаем Вам об изменении статуса квартиры <?php print $node['node']->title; ?>.

<br><br>Теперь Вы можете забронировать квартиру, отправив заявку застройщику.

<br><br><?php print l('Отправить заявку', '/node/' . $node['node']->nid, array('query' => array('booking' => 1))); ?>

<br><br><?php print l('Перейти на страницу квартиры', '/node/' . $node['node']->nid); ?>

<br><br>Спасибо за то, что воспользовались услугами сервиса Findome!

<br><br>С уважением, команда Findome!

<br><br>Это письмо автоматически сформированное уведомление. Пожалуйста, не отвечайте на него.

<br><br>©Findome