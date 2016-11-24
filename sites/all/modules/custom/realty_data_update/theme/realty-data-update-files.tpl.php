<table>
  <tr>
    <th>Застройщик</th>
    <th>Файл</th>
    <th>Размер</th>
    <th>Последнее изменение</th>
  </tr>

  <?php foreach ($args as $developer): ?>
  <tr>
    <td><?php print $developer['name']; ?></td>
    <td><?php print $developer['file']; ?></td>
    <td><?php print $developer['size'] . ' МБ'; ?></td>
    <td><?php print $developer['date']; ?></td>
  </tr>
  <?php endforeach; ?>
</table>