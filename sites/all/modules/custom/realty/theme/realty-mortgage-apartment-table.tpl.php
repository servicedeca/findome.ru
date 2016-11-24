<?php if ($empty != TRUE): ?>
  <table class="book-table">
    <tr>
      <th>№ заявки</th>
      <th>№ квартиры</th>
      <th>Банк</th>
      <th>Ипотечная программа</th>
      <th>Сумма, руб</th>
    </tr>
    <?php foreach($mortgage as $val): ?>
      <tr>
        <td><?php print $val['number']?></td>
        <td><?php print $val['num_apartment']?></td>
        <td><?php print $val['bank']?></td>
        <td><?php print $val['program']?></td>
        <td><?php print $val['sum']?></td>
      </tr>
    <?php endforeach;?>
  </table>
<?php else: ?>
  <div class="col-xs-12 empty-message">
    <h3>ни одна заявка на ипотеку не была подана</h3>
    <p>это можно сделать на страницах жилого комплекса или квартиры, или в разделе ипотеки</p>
    <?php print $search_link; ?>
  </div>
<?php endif; ?>
