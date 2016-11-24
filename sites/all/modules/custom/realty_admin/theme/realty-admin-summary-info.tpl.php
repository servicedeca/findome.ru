<!-- 405 символов игнорируется при экспорте в pdf -->
<form class="form-actions form-wrapper" action="/summary_info.xls">
  <button class="form-submit">Сохранить в XLS</button>
</form>

<form class="form-actions form-wrapper" action="/summary_info.pdf">
  <button class="form-submit">Сохранить в PDF</button>
</form>
<!-- ------------------------------------ -->

<?php if(isset($form)): ?>
  <?php print render($form); ?>
<?php endif; ?>

<table>
  <tr>
    <td>Застройщик</td>
    <td>Жилой комплекс</td>
    <td>Всего квартир</td>
    <?php foreach ($apartment_types as $type): ?>
      <td><?php print $type; ?>-к квартир</td>
    <?php endforeach; ?>
  </tr>
  <?php foreach($args['city'] as $city): ?>
  <tr>
    <th></th>
    <th></th>
    <th><?php print $city['apartments']['apartment_active']['all'] . ' / ' . $city['apartments']['apartment_booking']['all'] . ' / ' . $city['apartments']['apartment_base']['all'] . ' / ' . $city['apartments']['apartment_all']['all']; ?></th>
    <?php foreach ($apartment_types as $type): ?>
      <th>
        <?php print $city['apartments']['apartment_active'][$type] . ' / ' . $city['apartments']['apartment_booking'][$type] . ' / ' . $city['apartments']['apartment_base'][$type] . ' / ' . $city['apartments']['apartment_all'][$type]; ?>
      </th>
    <?php endforeach; ?>
  </tr>
  <?php endforeach; ?>
  <?php foreach ($args['developers'] as $developer_name => $developer): ?>

    <tr>
      <th><?php print $developer_name; ?></th>
      <th></th>
      <th><?php print $developer['apartments']['apartment_active']['all'] . ' / ' . $developer['apartments']['apartment_booking']['all'] . ' / ' . $developer['apartments']['apartment_base']['all']. ' / ' . $developer['apartments']['apartment_all']['all']; ?></th>
      <?php foreach ($apartment_types as $type):?>
        <th>
          <?php print $developer['apartments']['apartment_active']['1'] . ' / ' . $developer['apartments']['apartment_booking'][$type] . ' / ' . $developer['apartments']['apartment_base'][$type]. ' / ' . $developer['apartments']['apartment_all'][$type]; ?>
        </th>
    <?php endforeach; ?>

    </tr>
    <?php foreach ($args['complexes'] as $complex_name => $complex): ?>
      <?php if($complex['developer_name'] == $developer_name): ?>
        <tr>
          <td></td>
          <td><?php print $complex_name; ?></td>
          <td><?php print $complex['apartments']['apartment_active']['all'] . ' / ' . $complex['apartments']['apartment_booking']['all'] . ' / ' . $complex['apartments']['apartment_base']['all']. ' / ' . $complex['apartments']['apartment_all']['all']; ?></td>
          <?php foreach ($apartment_types as $type): ?>
              <td><?php print $complex['apartments']['apartment_active'][$type] . ' / ' . $complex['apartments']['apartment_booking'][$type] . ' / ' . $complex['apartments']['apartment_base'][$type]. ' / ' . $complex['apartments']['apartment_all'][$type]; ?></td>
          <?php endforeach; ?>
        </tr>


      <?php foreach ($args['homes']as $home_name => $home): ?>
        <?php if($home['complex_name'] == $complex_name): ?>
          <tr>
            <td></td>
            <td style="background-color: #afd9ee"><?php print $home_name; ?></td>
            <td style="background-color: #afd9ee"><?php print $home['apartments']['apartment_active']['all'] . ' / ' . $home['apartments']['apartment_booking']['all'] . ' / ' . $home['apartments']['apartment_base']['all']. ' / ' . $home['apartments']['apartment_all']['all']; ?></td>
            <?php foreach ($apartment_types as $type): ?>
                <td style="background-color: #afd9ee"><?php print $home['apartments']['apartment_active'][$type] . ' / ' . $home['apartments']['apartment_booking'][$type] . ' / ' . $home['apartments']['apartment_base'][$type]. ' / ' . $home['apartments']['apartment_all'][$type]; ?></td>
            <?php endforeach; ?>
          </tr>


        <?php foreach ($args['sections'] as $sec_num => $section): ?>
          <?php if($section['home_name'] == $home_name): ?>
            <tr>
              <td></td>
              <td style="background-color: rgba(128, 238, 167, 0.40)"><?php print $section['section_num']; ?></td>
              <td style="background-color: rgba(128, 238, 167, 0.40)"><?php print $section['apartments']['apartment_active']['all'] . ' / ' . $section['apartments']['apartment_booking']['all'] . ' / ' . $section['apartments']['apartment_base']['all']. ' / ' . $section['apartments']['apartment_all']['all']; ?></td>
              <?php foreach ($apartment_types as $type): ?>
                  <td style="background-color: rgba(128, 238, 167, 0.40)"><?php print $section['apartments']['apartment_active'][$type] . ' / ' . $section['apartments']['apartment_booking'][$type] . ' / ' . $section['apartments']['apartment_base'][$type]. ' / ' . $section['apartments']['apartment_all'][$type]; ?></td>
              <?php endforeach; ?>
            </tr>
            <?php endif; ?>
        <?php endforeach;?>
          <?php endif; ?>
      <?php endforeach;?>
      <?php endif;?>
    <?php endforeach;?>

  <?php endforeach; ?>
</table>