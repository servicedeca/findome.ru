
<table>
  <tr>
    <th>ID бронированя</th>
    <th>Дата</th>
    <th>Имя на гого бронировали</th>
    <th>Пользователь</th>
    <th>Номер квартиры</th>
    <th>ЖК</th>
    <th>Менеджер</th>
  </tr>
  <?php if($bookings):?>
    <?php foreach($bookings as $val): ?>
      <tr>
        <td><?php print $val['id']; ?></td>
        <td><?php print $val['date']; ?></td>
        <td><?php print $val['name']; ?></td>
        <td><?php print $val['user_name'] ?></td>
        <td><?php print $val['number_apartment']; ?></td>
        <td><?php print $val['complex']; ?></td>
        <td><?php print $val['manager'];?></td>
      </tr>
    <?php endforeach; ?>
  <?php endif;?>
</table>