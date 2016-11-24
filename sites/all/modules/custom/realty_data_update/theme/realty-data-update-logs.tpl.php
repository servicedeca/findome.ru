<?php print $filters; ?>

<a href="/update_files">Последнии изменения файлов</a>

<?php foreach ($log_periods as $key => $log_period): ?>
  <table>
    <br>
    <tr>
      <th><?php print $key; ?></th>
    </tr>
    <tr>
      <th>Квартира</th>
      <th>Старый статус</th>
      <th>Новый статус</th>
      <th>Старая стоимость</th>
      <th>Новая стоимость</th>
    </tr>
      <?php foreach($log_period as $log): ?>
    <tr>
        <td><a href='/node/<?php print $log->nid_apartment; ?>' target='_blank'><?php print $log->title; ?></a></td>
        <td><?php print $log->old_status; ?></td>
        <td><?php print $log->new_status; ?></td>
        <td><?php print $log->old_cost; ?></td>
        <td><?php print $log->new_cost; ?></td>
    </tr>
      <?php endforeach; ?>
  </table>
<?php endforeach; ?>