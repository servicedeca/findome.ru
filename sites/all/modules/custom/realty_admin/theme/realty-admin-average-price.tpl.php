<form class="form-actions form-wrapper" action="/average_price.xls">
  <button class="form-submit">Сохранить в XLS</button>
</form>

<table>
  <tr>
    <td>Застройщик</td>
    <td>Жилой комплекс</td>
    <td>Всего</td>
    <?php foreach ($args['apartment_types'] as $type): ?>
      <td><?php print $type; ?>-к квартира</td>
    <?php endforeach; ?>
  </tr>

  <tr style="background-color: #555555">
    <?php foreach($args['city'] as $city): ?>
      <th></th>
      <th></th>
      <th><?php print $city['apartments']['all']?></th>
      <?php foreach ($args['apartment_types'] as $type): ?>
      <th>
        <?php print $city['apartments'][$type]; ?>
      </th>
      <?php endforeach; ?>
    <?php endforeach; ?>
  </tr>

  <?php foreach ($args['developers'] as $developer_name => $developer): ?>

    <tr>
      <th><?php print $developer_name; ?></th>
      <th></th>
      <th><?php $developer['apartments']['all'] ? print $developer['apartments']['all'] : print '-'; ?></th>

      <?php foreach ($args['apartment_types'] as $type): ?>
          <th>
            <?php $developer['apartments'][$type] ? print $developer['apartments'][$type] : print '-';?>
          </th>
      <?php endforeach; ?>

    </tr>

    <?php foreach ($args['complexes'] as $complex_name => $complex): ?>
    <?php if($developer['tid'] == $complex['developer_tid']): ?>
      <tr>
        <td></td>
        <td><?php print $complex_name; ?></td>
        <td><?php print $complex['apartments']['all']; ?></td>
        <?php foreach ($args['apartment_types'] as $type): ?>
            <td><?php $complex['apartments'][$type] ? print $complex['apartments'][$type] : print '-'; ?></td>
        <?php endforeach; ?>
      </tr>
    <?php endif; ?>
    <?php endforeach;?>

  <?php endforeach; ?>
</table>