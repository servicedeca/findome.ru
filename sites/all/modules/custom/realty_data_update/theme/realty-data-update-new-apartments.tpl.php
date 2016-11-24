<?php print render($form); ?>
<?php print render($form_clear); ?>
<table>
  <tr>
    <th>номер квартиры</th>
    <th>ЖК</th>
    <th>Застройщик</th>
    <th>Адрес</th>
    <th>Номер дома в ЖК</th>
    <th>Статус</th>
    <th>Стоимость</th>
  </tr>
  <?php foreach ($apartments as $key => $val): ?>
    <tr>
      <td><?php print $val->number_apartment; ?></td>
      <td><?php print $val->complex; ?></td>
      <td><?php print $val->developer; ?></td>
      <td><?php print $val->street . ' ' . $val->number_home_street; ?></td>
      <td><?php print $val->number_home_complex; ?></td>
      <td><?php print $val->status; ?></td>
      <td><?php print $val->coast; ?></td>
    </tr>
  <?php endforeach; ?>
</table>