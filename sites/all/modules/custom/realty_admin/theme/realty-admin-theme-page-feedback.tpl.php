<?php if(!empty($callback)):?>
  <h1>Заявки на обратный звонок</h1>
  <table>
    <thead style="background-color: #9f9f9f">
      <tr>
        <td>Дата</td>
        <td>Имя</td>
        <td>Email</td>
        <td>Телефон</td>
        <td>Желаемое время и дата звонка</td>
      </tr>
    </thead>
    <tbody>
      <?php foreach($callback as $val): ?>
        <tr>
        <td><?php print $val['date']?></td>
        <td><?php print $val['name']?></td>
        <td><?php print $val['email']?></td>
        <td><?php print $val['phone']?></td>
        <td><?php print $val['date_call']?></td>
        </tr>
      <?php endforeach?>
    </tbody>
  </table>
<?php endif; ?>

<?php if(!empty($excur)):?>

  <h1>Заявки на Экскурсию</h1>
  <table>
    <thead style="background-color: #9F9F9F">
    <tr>
      <td>Дата</td>
      <td>Имя</td>
      <td>Email</td>
      <td>Телефон</td>
      <td>Желаемое время и дата звонка</td>
      <td>ЖК</td>
    </tr>
    </thead>
    <tbody>
      <?php foreach($excur as $val): ?>
      <tr>
        <td><?php print $val['date']?></td>
        <td><?php print $val['name']?></td>
        <td><?php print $val['email']?></td>
        <td><?php print $val['phone']?></td>
        <td><?php print $val['date_call']?></td>
        <td><?php print $val['complex']?></td>
      </tr>
      <?php endforeach?>
    </tbody>
  </table>
<?php endif; ?>

<?php if(!empty($questions)):?>

  <h1>Воросы и предложение</h1>
  <table>
    <thead style="background-color: #9F9F9F">
    <tr>
      <td>Дата</td>
      <td>Имя</td>
      <td>Email</td>
      <td>Телефон</td>
      <td>Вопрос или предложение</td>
    </tr>
    </thead>
    <tbody>
    <?php foreach($questions as $val): ?>
      <tr>
        <td><?php print $val['date']?></td>
        <td><?php print $val['name']?></td>
        <td><?php print $val['email']?></td>
        <td><?php print $val['phone']?></td>
        <td><?php print $val['questions_offers']?></td>
      </tr>
    <?php endforeach?>
    </tbody>
  </table>
<?php endif; ?>


<?php if(!empty($selection)):?>

  <h1>Заявка на подбор</h1>
  <table>
    <thead style="background-color: #9F9F9F">
    <tr>
      <td>Дата</td>
      <td>Имя</td>
      <td>Email</td>
      <td>Телефон</td>
      <td>Вопрос или предложение</td>
    </tr>
    </thead>
    <tbody>
    <?php foreach($questions as $val): ?>
      <tr>
        <td><?php print $val['date']?></td>
        <td><?php print $val['name']?></td>
        <td><?php print $val['email']?></td>
        <td><?php print $val['phone']?></td>
        <td><?php print $val['questions_offers']?></td>
      </tr>
    <?php endforeach?>
    </tbody>
  </table>
<?php endif; ?>