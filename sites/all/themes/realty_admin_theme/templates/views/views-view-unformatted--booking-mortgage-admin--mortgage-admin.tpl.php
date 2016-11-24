<table>
  <tr>
    <th>ID заявки</th>
    <th>Дата</th>
    <th>Пользователь подавший заявку</th>
    <th>Имя на кого подана заявка</th>
    <th>Банк</th>
    <th>Отделение</th>
    <th>Ипотечная программа</th>
    <th>Требуемая сумма</th>
  </tr>
  <?php if($mortgages):?>
    <?php foreach($mortgages as $mortgage): ?>
      <tr>
        <td><?php print $mortgage['title']; ?></td>
        <td><?php print $mortgage['date']; ?></td>
        <td><?php print $mortgage['username']; ?></td>
        <td><?php print $mortgage['full name']; ?></td>
        <td><?php print $mortgage['bank']; ?></td>
        <td><?php print $mortgage['affiliate']; ?></td>
        <td><?php print $mortgage['mortgage']; ?></td>
        <td><?php print $mortgage['amount']; ?></td>
      </tr>
    <?php endforeach; ?>
  <?php endif;?>
</table>